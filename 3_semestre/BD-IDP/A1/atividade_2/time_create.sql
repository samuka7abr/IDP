USE futebol;

CREATE TABLE IF NOT EXISTS time (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL
);

CREATE TABLE IF NOT EXISTS estadio (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    publico INT NOT NULL,
    capacidade INT DEFAULT NULL,
    time_id INT,  -- Adicionado o campo necessário
    FOREIGN KEY (time_id) REFERENCES time(id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS jogadores (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    idade INT NOT NULL,
    time_id INT,  -- Adicionado o campo correto para chave estrangeira
    FOREIGN KEY (time_id) REFERENCES time(id) ON DELETE CASCADE
);
