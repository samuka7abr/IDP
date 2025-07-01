CREATE DATABASE IF NOT EXISTS tabacaria;
USE tabacaria;

-- Tabela Cliente
CREATE TABLE IF NOT EXISTS Cliente (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phone_number VARCHAR(20),
    register_date DATE 
);

-- Tabela Address (Endereço)
CREATE TABLE IF NOT EXISTS Address (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    client_id BIGINT NOT NULL,
    street VARCHAR(100),
    number VARCHAR(10),
    neighborhood VARCHAR(100),
    city VARCHAR(50),
    state VARCHAR(50),
    cep BIGINT,
    type ENUM('Residencial', 'Comercial', 'Outro'),
    FOREIGN KEY (client_id) REFERENCES Cliente(id) ON DELETE CASCADE
);

-- Tabela Product (Produtos)
CREATE TABLE IF NOT EXISTS Product (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(150) NOT NULL,
    description TEXT,
    category ENUM('cigarro', 'charuto', 'essência', 'acessório') NOT NULL,
    brand VARCHAR(100),
    price DECIMAL(10,2) NOT NULL,
    storage BIGINT NOT NULL,
    register_date DATE 
);

-- Tabela Orders (Pedidos)
CREATE TABLE IF NOT EXISTS Orders (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    client_id BIGINT NOT NULL,
    date_order DATE ,
    status ENUM('pendente', 'processando', 'enviado', 'entregue', 'cancelado') DEFAULT 'pendente',
    total DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (client_id) REFERENCES Cliente(id) ON DELETE CASCADE
);

-- Tabela Ordered_Items (Itens do Pedido)
CREATE TABLE IF NOT EXISTS Ordered_Items (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    order_id BIGINT NOT NULL,
    product_id BIGINT NOT NULL,
    amount INT NOT NULL,
    unit_price DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (order_id) REFERENCES Orders(id) ON DELETE CASCADE,
    FOREIGN KEY (product_id) REFERENCES Product(id) ON DELETE CASCADE
);

-- Tabela Payments (Pagamentos)
CREATE TABLE IF NOT EXISTS Payments (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    order_id BIGINT NOT NULL,
    method ENUM('cartão de crédito', 'boleto', 'pix', 'paypal') NOT NULL,
    status ENUM('pendente', 'aprovado', 'recusado') DEFAULT 'pendente',
    value DECIMAL(10,2) NOT NULL,
    payment_date DATE ,
    FOREIGN KEY (order_id) REFERENCES Orders(id) ON DELETE CASCADE
);


-- INSERÇÕES:

-- Inserindo Clientes (primeiro, para garantir que existam antes de endereços)
INSERT INTO Cliente (name, email, phone_number) VALUES
('João Silva', 'joao.silva@email.com', '11987654321'),
('Mariana Santos', 'mariana.santos@email.com', '11912345678'),
('Carlos Oliveira', 'carlos.oliveira@email.com', '11965498732'),
('Fernanda Lima', 'fernanda.lima@email.com', '11934567890'),
('Roberto Souza', 'roberto.souza@email.com', '11998765432');

-- Agora, inserindo Endereços (já temos os clientes no banco)
INSERT INTO Address (client_id, street, number, neighborhood, city, state, cep, type) VALUES
(1, 'Rua das Palmeiras', '123', 'Centro', 'São Paulo', 'SP', 12345678, 'Residencial'),
(1, 'Rua dos Pinheiros', '456', 'Jardins', 'São Paulo', 'SP', 12345679, 'Comercial'),
(2, 'Av. Paulista', '789', 'Bela Vista', 'São Paulo', 'SP', 98765432, 'Residencial'),
(3, 'Rua do Comércio', '321', 'Centro', 'Rio de Janeiro', 'RJ', 11223344, 'Comercial'),
(4, 'Rua das Orquídeas', '654', 'Jardins', 'Belo Horizonte', 'MG', 55667788, 'Residencial'),
(5, 'Av. dos Bandeirantes', '987', 'Centro', 'Curitiba', 'PR', 99887766, 'Comercial');

-- Inserindo Produtos
INSERT INTO Product (name, description, category, brand, price, storage) VALUES
('Cigarro Marlboro', 'Marlboro Vermelho, 20 unidades.', 'cigarro', 'Marlboro', 12.99, 200),
('Charuto Cohiba', 'Charuto cubano de alta qualidade.', 'charuto', 'Cohiba', 89.99, 50),
('Essência Blueberry', 'Essência de narguilé sabor blueberry.', 'essência', 'Zomo', 19.99, 100),
('Isqueiro Zippo', 'Isqueiro recarregável de metal.', 'acessório', 'Zippo', 99.99, 30),
('Papel de Seda Smoking', 'Papel de seda ultra fino.', 'acessório', 'Smoking', 5.99, 300);

-- Inserindo Pedidos
INSERT INTO Orders (client_id, status, total) VALUES
(1, 'pendente', 32.98),
(2, 'processando', 99.99),
(3, 'enviado', 19.99),
(4, 'entregue', 89.99),
(5, 'cancelado', 5.99);

-- Inserindo Itens do Pedido
INSERT INTO Ordered_Items (order_id, product_id, amount, unit_price) VALUES
(1, 1, 2, 12.99),
(1, 5, 1, 5.99),
(2, 4, 1, 99.99),
(3, 3, 1, 19.99),
(4, 2, 1, 89.99),
(5, 5, 1, 5.99);

-- Inserindo Pagamentos
INSERT INTO Payments (order_id, method, status, value) VALUES
(1, 'cartão de crédito', 'pendente', 32.98),
(2, 'pix', 'aprovado', 99.99),
(3, 'boleto', 'aprovado', 19.99),
(4, 'cartão de crédito', 'aprovado', 89.99),
(5, 'paypal', 'recusado', 5.99);

-- Validando inserções
SELECT * FROM Cliente;
SELECT * FROM Address;
SELECT * FROM Product;
SELECT * FROM Orders;
SELECT * FROM Ordered_Items;
SELECT * FROM Payments;
