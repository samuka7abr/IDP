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
	ID       int    `json:"id"`
	Name     string `json:"name"`
	Email    string `json:"email"`
	Password string `json:"password,omitempty"`
}

type Client struct {
	BaseURL string
	HTTP    *http.Client
	Token   string
}

func NewClient(baseURL string) *Client {
	return &Client{
		BaseURL: baseURL,
		HTTP:    &http.Client{Timeout: 5 * time.Second},
	}
}

func (c *Client) SetToken(token string) {
	c.Token = token
}

func (c *Client) doJSON(ctx context.Context, method, path string, in any, out any) error {
	var body io.Reader
	if in != nil {
		b, err := json.Marshal(in)
		if err != nil {
			return err
		}
		body = bytes.NewBuffer(b)
	}

	fullURL := c.BaseURL + path
	req, err := http.NewRequestWithContext(ctx, method, fullURL, body)
	if err != nil {
		return err
	}

	if in != nil {
		req.Header.Set("Content-Type", "application/json")
	}
	if c.Token != "" {
		req.Header.Set("Authorization", "Bearer "+c.Token)
	}

	resp, err := c.HTTP.Do(req)
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	if resp.StatusCode >= 400 {
		b, _ := io.ReadAll(resp.Body)
		return fmt.Errorf("HTTP %d: %s", resp.StatusCode, string(b))
	}

	if out != nil && resp.StatusCode != http.StatusNoContent {
		return json.NewDecoder(resp.Body).Decode(out)
	}
	return nil
}

func main() {
	c := NewClient("http://localhost:8080")
	ctx := context.Background()

	fmt.Println("=== Criando usuário ===")
	user := User{Name: "João", Email: "joao@exemplo.com", Password: "1234"}
	if err := c.doJSON(ctx, "POST", "/users", user, &user); err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Usuário criado: %+v\n", user)

	fmt.Println("=== Fazendo login ===")
	var loginResp struct {
		Token string `json:"token"`
	}
	if err := c.doJSON(ctx, "POST", "/login",
		map[string]string{"email": user.Email, "password": user.Password},
		&loginResp); err != nil {
		log.Fatal(err)
	}
	fmt.Println("Token recebido:", loginResp.Token)
	c.SetToken(loginResp.Token)

	fmt.Println("=== Criando produto autenticado ===")
	product := Product{Name: "Notebook", Price: 1999.90}
	if err := c.doJSON(ctx, "POST", "/products", product, &product); err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Produto criado: %+v\n", product)

	fmt.Println("=== Listando produtos ===")
	var all []Product
	if err := c.doJSON(ctx, "GET", "/products", nil, &all); err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Produtos: %+v\n", all)
}
