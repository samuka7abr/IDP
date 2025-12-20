package main

import (
	"bytes"
	"context"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"time"
)

type Product struct {
	ID     int     `json:"id"`
	Name   string  `json:"name"`
	Price  float64 `json:"price"`
	UserID int     `json:"user_id"`
}

type User struct {
	ID    int    `json:"id"`
	Name  string `json:"name"`
	Email string `json:"email"`
}

type Client struct {
	BaseURL string
	HTTP    *http.Client
}

func NewClient(baseURL string) *Client {
	return &Client{
		BaseURL: baseURL,
		HTTP:    &http.Client{Timeout: 5 * time.Second},
	}
}

func (c *Client) doJSON(ctx context.Context, method, path string, in any, out any) error {
	var body io.Reader
	var bodyBytes []byte
	if in != nil {
		b, err := json.Marshal(in)
		if err != nil {
			return err
		}
		bodyBytes = b
		body = bytes.NewBuffer(b)
	}
	
	fullURL := c.BaseURL + path
	fmt.Printf("[HTTP] %s %s\n", method, fullURL)
	if bodyBytes != nil {
		fmt.Printf("[REQUEST BODY] %s\n", string(bodyBytes))
	}
	
	req, err := http.NewRequestWithContext(ctx, method, fullURL, body)
	if err != nil {
		return err
	}
	if in != nil {
		req.Header.Set("Content-Type", "application/json")
	}
	resp, err := c.HTTP.Do(req)
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	fmt.Printf("[RESPONSE] Status: %d %s\n", resp.StatusCode, http.StatusText(resp.StatusCode))

	if resp.StatusCode >= 400 {
		b, _ := io.ReadAll(resp.Body)
		fmt.Printf("[ERROR BODY] %s\n", string(b))
		return fmt.Errorf("HTTP %d: %s", resp.StatusCode, string(b))
	}

	if out != nil && resp.StatusCode != http.StatusNoContent {
		bodyData, err := io.ReadAll(resp.Body)
		if err != nil {
			return err
		}
		fmt.Printf("[RESPONSE BODY] %s\n", string(bodyData))
		return json.Unmarshal(bodyData, out)
	}
	fmt.Println()
	return nil
}

func (c *Client) CreateProduct(ctx context.Context, p Product) (Product, error) {
	var out Product
	err := c.doJSON(ctx, http.MethodPost, "/products", p, &out)
	return out, err
}

func (c *Client) ListProducts(ctx context.Context) ([]Product, error) {
	var out []Product
	err := c.doJSON(ctx, http.MethodGet, "/products", nil, &out)
	return out, err
}

func (c *Client) GetProduct(ctx context.Context, id int) (Product, error) {
	var out Product
	err := c.doJSON(ctx, http.MethodGet, fmt.Sprintf("/products/%d", id), nil, &out)
	return out, err
}

func (c *Client) UpdateProduct(ctx context.Context, id int, p Product) (Product, error) {
	var out Product
	err := c.doJSON(ctx, http.MethodPut, fmt.Sprintf("/products/%d", id), p, &out)
	return out, err
}

func (c *Client) DeleteProduct(ctx context.Context, id int) error {
	return c.doJSON(ctx, http.MethodDelete, fmt.Sprintf("/products/%d", id), nil, nil)
}

func (c *Client) ListProductsByUser(ctx context.Context, userID int) ([]Product, error) {
	var out []Product
	err := c.doJSON(ctx, http.MethodGet, fmt.Sprintf("/products?user_id=%d", userID), nil, &out)
	return out, err
}

func (c *Client) CreateUser(ctx context.Context, u User) (User, error) {
	var out User
	err := c.doJSON(ctx, http.MethodPost, "/users", u, &out)
	return out, err
}

func (c *Client) ListUsers(ctx context.Context) ([]User, error) {
	var out []User
	err := c.doJSON(ctx, http.MethodGet, "/users", nil, &out)
	return out, err
}

func (c *Client) GetUser(ctx context.Context, id int) (User, error) {
	var out User
	err := c.doJSON(ctx, http.MethodGet, fmt.Sprintf("/users/%d", id), nil, &out)
	return out, err
}

func (c *Client) UpdateUser(ctx context.Context, id int, u User) (User, error) {
	var out User
	err := c.doJSON(ctx, http.MethodPut, fmt.Sprintf("/users/%d", id), u, &out)
	return out, err
}

func (c *Client) DeleteUser(ctx context.Context, id int) error {
	return c.doJSON(ctx, http.MethodDelete, fmt.Sprintf("/users/%d", id), nil, nil)
}

func main() {
	c := NewClient("http://localhost:8080")
	ctx := context.Background()

	fmt.Println("=== Testando API de Usuários ===")

	fmt.Println("1. Criando usuário...")
	createdUser, err := c.CreateUser(ctx, User{Name: "João Silva", Email: "joao@exemplo.com"})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Criado: %+v\n\n", createdUser)

	fmt.Println("=== Testando Cliente da API de Produtos ===")

	fmt.Println("2. Criando produto sem usuário...")
	created, err := c.CreateProduct(ctx, Product{Name: "Notebook", Price: 1200.50})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Criado: %+v\n\n", created)

	fmt.Println("3. Criando produto com usuário...")
	createdWithUser, err := c.CreateProduct(ctx, Product{Name: "Mouse", Price: 25.99, UserID: createdUser.ID})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Criado: %+v\n\n", createdWithUser)

	fmt.Println("4. Listando todos os produtos...")
	all, err := c.ListProducts(ctx)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Todos: %+v\n\n", all)

	fmt.Println("5. Listando produtos por usuário...")
	userProducts, err := c.ListProductsByUser(ctx, createdUser.ID)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Produtos do Usuário %d: %+v\n\n", createdUser.ID, userProducts)

	fmt.Println("6. Obtendo produto por ID...")
	one, err := c.GetProduct(ctx, created.ID)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Buscado: %+v\n\n", one)

	fmt.Println("7. Atualizando produto com usuário...")
	updated, err := c.UpdateProduct(ctx, created.ID, Product{Name: "Notebook Gamer", Price: 1500, UserID: createdUser.ID})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Atualizado: %+v\n\n", updated)

	fmt.Println("8. Excluindo produto...")
	if err := c.DeleteProduct(ctx, createdWithUser.ID); err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Excluído ID: %d\n\n", createdWithUser.ID)

	fmt.Println("9. Listando todos os produtos após exclusão...")
	final, err := c.ListProducts(ctx)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Todos Após Exclusão: %+v\n\n", final)

	fmt.Println("=== Testando Mais Operações de Usuários ===")

	fmt.Println("10. Listando todos os usuários...")
	allUsers, err := c.ListUsers(ctx)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Todos: %+v\n\n", allUsers)

	fmt.Println("11. Obtendo usuário por ID...")
	oneUser, err := c.GetUser(ctx, createdUser.ID)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Buscado: %+v\n\n", oneUser)

	fmt.Println("12. Atualizando usuário...")
	updatedUser, err := c.UpdateUser(ctx, createdUser.ID, User{Name: "Maria Silva", Email: "maria@exemplo.com"})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Atualizado: %+v\n\n", updatedUser)

	fmt.Println("13. Excluindo produto restante...")
	if err := c.DeleteProduct(ctx, created.ID); err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Excluído ID: %d\n\n", created.ID)

	fmt.Println("14. Excluindo usuário...")
	if err := c.DeleteUser(ctx, createdUser.ID); err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Excluído ID: %d\n\n", createdUser.ID)

	fmt.Println("15. Estado final - Todos os usuários...")
	finalUsers, err := c.ListUsers(ctx)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Todos Após Exclusão: %+v\n\n", finalUsers)

	fmt.Println("16. Estado final - Todos os produtos...")
	finalProducts, err := c.ListProducts(ctx)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("   Todos Após Exclusão: %+v\n", finalProducts)
}
