CREATE DATABASE IF NOT EXISTS produtos_db;

USE produtos_db;

CREATE USER IF NOT EXISTS 'app_user'@'%' IDENTIFIED BY 'samuel';
GRANT ALL PRIVILEGES ON produtos_db.* TO 'app_user'@'%';
FLUSH PRIVILEGES;

CREATE TABLE IF NOT EXISTS produtos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    descricao TEXT,
    preco DECIMAL(10,2) NOT NULL,
    quantidade INT NOT NULL,
    data_cadastro TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
