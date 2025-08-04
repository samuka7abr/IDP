-- Criando o banco de dados
CREATE DATABASE LanchoneteDB;
USE LanchoneteDB;

-- Tabela de Clientes
CREATE TABLE Cliente (
    id_cliente INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    telefone VARCHAR(15),
    email VARCHAR(100) UNIQUE,
    endereco TEXT
);

-- Tabela de Produtos
CREATE TABLE Produto (
    id_produto INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    descricao TEXT,
    preco DECIMAL(10,2) NOT NULL,
    estoque INT NOT NULL DEFAULT 0
);

-- Tabela de Pedidos
CREATE TABLE Pedido (
    id_pedido INT AUTO_INCREMENT PRIMARY KEY,
    id_cliente INT,
    data_pedido TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status ENUM('Pendente', 'Em Preparo', 'Pronto', 'Finalizado', 'Cancelado') DEFAULT 'Pendente',
    valor_total DECIMAL(10,2) DEFAULT 0,
    FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente) ON DELETE SET NULL
);

-- Tabela de Itens do Pedido
CREATE TABLE ItemPedido (
    id_item INT AUTO_INCREMENT PRIMARY KEY,
    id_pedido INT,
    id_produto INT,
    quantidade INT NOT NULL,
    preco_unitario DECIMAL(10,2) NOT NULL,
    subtotal DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (id_pedido) REFERENCES Pedido(id_pedido) ON DELETE CASCADE,
    FOREIGN KEY (id_produto) REFERENCES Produto(id_produto) ON DELETE CASCADE
);

-- Tabela de Pagamentos
CREATE TABLE Pagamento (
    id_pagamento INT AUTO_INCREMENT PRIMARY KEY,
    id_pedido INT,
    forma_pagamento ENUM('Dinheiro', 'Cartão de Crédito', 'Cartão de Débito', 'Pix') NOT NULL,
    valor_pago DECIMAL(10,2) NOT NULL,
    data_pagamento TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (id_pedido) REFERENCES Pedido(id_pedido) ON DELETE CASCADE
);
