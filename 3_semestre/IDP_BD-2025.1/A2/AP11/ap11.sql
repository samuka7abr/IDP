CREATE TABLE Cliente (
    cpf_cliente    CHAR(11)    PRIMARY KEY,
    nome_cliente   VARCHAR(100) NOT NULL,
    endereco       VARCHAR(255) NOT NULL
);

CREATE TABLE Vendedor (
    cpf_vendedor  CHAR(11)    PRIMARY KEY,
    nome_vendedor VARCHAR(100) NOT NULL,
    regional      VARCHAR(100) NOT NULL
);

CREATE TABLE Produto (
    cod_produto    INT          PRIMARY KEY,
    nome_produto   VARCHAR(100) NOT NULL,
    categoria      VARCHAR(50)  NOT NULL,
    preco_unitario DECIMAL(10,2) NOT NULL
);

CREATE TABLE Venda (
    id_venda     INT       PRIMARY KEY,
    data_venda   DATE      NOT NULL,
    cpf_cliente  CHAR(11)  NOT NULL,
    cpf_vendedor CHAR(11)  NOT NULL,
    FOREIGN KEY (cpf_cliente)  REFERENCES Cliente(cpf_cliente),
    FOREIGN KEY (cpf_vendedor) REFERENCES Vendedor(cpf_vendedor)
);

CREATE TABLE VendaItem (
    id_venda    INT       NOT NULL,
    cod_produto INT       NOT NULL,
    quantidade  INT       NOT NULL,
    PRIMARY KEY (id_venda, cod_produto),
    FOREIGN KEY (id_venda)    REFERENCES Venda(id_venda),
    FOREIGN KEY (cod_produto) REFERENCES Produto(cod_produto)
);

INSERT INTO Cliente VALUES
('12345678901', 'Maria Souza',    'Rua A, 123'),
('32165498700', 'Carlos Mendes',  'Av. Central, 456'),
('45612378900', 'Bruna Rocha',    'Rua B, 789');

INSERT INTO Vendedor VALUES
('98765432100', 'João Lima',  'Sul'),
('11122233344', 'Ana Paula',  'Norte');

INSERT INTO Produto VALUES
(101, 'Caneta Azul',     'Papelaria',  2.50),
(102, 'Caderno 200fl',   'Papelaria', 15.00),
(103, 'Mochila Escolar', 'Mochilas', 120.00);

INSERT INTO Venda VALUES
(1, '2025-05-01', '12345678901', '98765432100'),
(2, '2025-05-01', '32165498700', '98765432100'),
(3, '2025-05-02', '12345678901', '11122233344'),
(4, '2025-05-03', '45612378900', '98765432100'),
(5, '2025-05-03', '32165498700', '11122233344');

INSERT INTO VendaItem VALUES
(1, 101, 10),
(2, 102,  5),
(3, 103,  1),
(4, 101, 15),
(5, 103,  2);
