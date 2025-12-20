package main

import (
	"context"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"strconv"
	"sync"
	"time"

	"github.com/golang-jwt/jwt/v5"
)

type Product struct {
	ID     int     `json:"id"`
	Name   string  `json:"name"`
	Price  float64 `json:"price"`
	UserID int     `json:"user_id"`
}

type User struct {
	ID       int    `json:"id"`
	Name     string `json:"name"`
	Email    string `json:"email"`
	Password string `json:"password,omitempty"`
}

var (
	products      = make(map[int]Product)
	users         = make(map[int]User)
	mu            sync.RWMutex
	nextProductID = 1
	nextUserID    = 1
	jwtSecret     = []byte("minha-chave-secreta-123")
)

type Claims struct {
	UserID int `json:"user_id"`
	jwt.RegisteredClaims
}

func GenerateToken(userID int) (string, error) {
	claims := &Claims{
		UserID: userID,
		RegisteredClaims: jwt.RegisteredClaims{
			ExpiresAt: jwt.NewNumericDate(time.Now().Add(1 * time.Hour)),
			IssuedAt:  jwt.NewNumericDate(time.Now()),
		},
	}
	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	return token.SignedString(jwtSecret)
}

func ValidateToken(tokenStr string) (*Claims, error) {
	token, err := jwt.ParseWithClaims(tokenStr, &Claims{}, func(t *jwt.Token) (interface{}, error) {
		return jwtSecret, nil
	})
	if err != nil {
		return nil, err
	}
	if claims, ok := token.Claims.(*Claims); ok && token.Valid {
		return claims, nil
	}
	return nil, fmt.Errorf("invalid token")
}

func withAuth(next http.HandlerFunc) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		authHeader := r.Header.Get("Authorization")
		if authHeader == "" || len(authHeader) < 8 {
			http.Error(w, "Missing or invalid token", http.StatusUnauthorized)
			return
		}
		tokenStr := authHeader[len("Bearer "):]
		claims, err := ValidateToken(tokenStr)
		if err != nil {
			http.Error(w, "Invalid token", http.StatusUnauthorized)
			return
		}
		ctx := context.WithValue(r.Context(), "userID", claims.UserID)
		next(w, r.WithContext(ctx))
	}
}

func main() {
	http.HandleFunc("/login", loginHandler)
	http.HandleFunc("/users", handleUsers)
	http.HandleFunc("/users/", handleUserByID)

	http.HandleFunc("/products", withAuth(handleProducts))
	http.HandleFunc("/products/", withAuth(handleProductByID))

	log.Println("✅ API running on :8080")
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func handleUsers(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case http.MethodGet:
		getUsers(w, r)
	case http.MethodPost:
		createUser(w, r)
	default:
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

func handleUserByID(w http.ResponseWriter, r *http.Request) {
	id, err := strconv.Atoi(r.URL.Path[len("/users/"):])
	if err != nil {
		http.Error(w, "Invalid ID", http.StatusBadRequest)
		return
	}

	switch r.Method {
	case http.MethodGet:
		getUser(w, r, id)
	case http.MethodPut:
		updateUser(w, r, id)
	case http.MethodDelete:
		deleteUser(w, r, id)
	default:
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

func getUsers(w http.ResponseWriter, r *http.Request) {
	mu.RLock()
	defer mu.RUnlock()

	list := make([]User, 0, len(users))
	for _, u := range users {
		list = append(list, u)
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(list)
}

func createUser(w http.ResponseWriter, r *http.Request) {
	var u User
	if err := json.NewDecoder(r.Body).Decode(&u); err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	if u.Email == "" || u.Password == "" {
		http.Error(w, "Email and password required", http.StatusBadRequest)
		return
	}

	mu.Lock()
	u.ID = nextUserID
	nextUserID++
	users[u.ID] = u
	mu.Unlock()

	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(http.StatusCreated)
	json.NewEncoder(w).Encode(u)
}

func getUser(w http.ResponseWriter, r *http.Request, id int) {
	mu.RLock()
	u, exists := users[id]
	mu.RUnlock()

	if !exists {
		http.Error(w, "User not found", http.StatusNotFound)
		return
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(u)
}

func updateUser(w http.ResponseWriter, r *http.Request, id int) {
	var u User
	if err := json.NewDecoder(r.Body).Decode(&u); err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	mu.Lock()
	if _, exists := users[id]; !exists {
		mu.Unlock()
		http.Error(w, "User not found", http.StatusNotFound)
		return
	}
	u.ID = id
	users[id] = u
	mu.Unlock()

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(u)
}

func deleteUser(w http.ResponseWriter, r *http.Request, id int) {
	mu.Lock()
	if _, exists := users[id]; !exists {
		mu.Unlock()
		http.Error(w, "User not found", http.StatusNotFound)
		return
	}
	delete(users, id)
	mu.Unlock()

	w.WriteHeader(http.StatusNoContent)
}

func loginHandler(w http.ResponseWriter, r *http.Request) {
	var creds struct {
		Email    string `json:"email"`
		Password string `json:"password"`
	}
	if err := json.NewDecoder(r.Body).Decode(&creds); err != nil {
		http.Error(w, "Invalid JSON", http.StatusBadRequest)
		return
	}

	mu.RLock()
	defer mu.RUnlock()

	for _, u := range users {
		if u.Email == creds.Email && u.Password == creds.Password {
			token, _ := GenerateToken(u.ID)
			w.Header().Set("Content-Type", "application/json")
			json.NewEncoder(w).Encode(map[string]string{"token": token})
			return
		}
	}
	http.Error(w, "Invalid credentials", http.StatusUnauthorized)
}

func handleProducts(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case http.MethodGet:
		if r.URL.Query().Get("user_id") != "" {
			getProductsByUser(w, r)
		} else {
			getProducts(w, r)
		}
	case http.MethodPost:
		createProduct(w, r)
	default:
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

func handleProductByID(w http.ResponseWriter, r *http.Request) {
	id, err := strconv.Atoi(r.URL.Path[len("/products/"):])
	if err != nil {
		http.Error(w, "Invalid ID", http.StatusBadRequest)
		return
	}

	switch r.Method {
	case http.MethodGet:
		getProduct(w, r, id)
	case http.MethodPut:
		updateProduct(w, r, id)
	case http.MethodDelete:
		deleteProduct(w, r, id)
	default:
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

func getProducts(w http.ResponseWriter, r *http.Request) {
	mu.RLock()
	defer mu.RUnlock()
	list := make([]Product, 0, len(products))
	for _, p := range products {
		list = append(list, p)
	}
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(list)
}

func createProduct(w http.ResponseWriter, r *http.Request) {
	var p Product
	if err := json.NewDecoder(r.Body).Decode(&p); err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	userID := r.Context().Value("userID").(int)
	p.UserID = userID

	mu.Lock()
	p.ID = nextProductID
	nextProductID++
	products[p.ID] = p
	mu.Unlock()

	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(http.StatusCreated)
	json.NewEncoder(w).Encode(p)
}

func getProduct(w http.ResponseWriter, r *http.Request, id int) {
	mu.RLock()
	p, exists := products[id]
	mu.RUnlock()
	if !exists {
		http.Error(w, "Product not found", http.StatusNotFound)
		return
	}
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(p)
}

func updateProduct(w http.ResponseWriter, r *http.Request, id int) {
	var p Product
	if err := json.NewDecoder(r.Body).Decode(&p); err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}
	mu.Lock()
	if _, exists := products[id]; !exists {
		mu.Unlock()
		http.Error(w, "Product not found", http.StatusNotFound)
		return
	}
	p.ID = id
	products[id] = p
	mu.Unlock()
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(p)
}

func deleteProduct(w http.ResponseWriter, r *http.Request, id int) {
	mu.Lock()
	if _, exists := products[id]; !exists {
		mu.Unlock()
		http.Error(w, "Product not found", http.StatusNotFound)
		return
	}
	delete(products, id)
	mu.Unlock()
	w.WriteHeader(http.StatusNoContent)
}

func getProductsByUser(w http.ResponseWriter, r *http.Request) {
	userID, err := strconv.Atoi(r.URL.Query().Get("user_id"))
	if err != nil || userID == 0 {
		getProducts(w, r)
		return
	}
	mu.RLock()
	defer mu.RUnlock()
	list := make([]Product, 0)
	for _, p := range products {
		if p.UserID == userID {
			list = append(list, p)
		}
	}
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(list)
}
