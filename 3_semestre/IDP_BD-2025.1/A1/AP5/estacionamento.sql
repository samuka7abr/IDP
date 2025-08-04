-- Criando as tabelas

CREATE TABLE professor (
    id_professor INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100),
    departamento VARCHAR(100)
);

CREATE TABLE tag_estacionamento (
    id_tag INT PRIMARY KEY AUTO_INCREMENT,
    id_professor INT NOT NULL,
    tag VARCHAR(100) UNIQUE NOT NULL,
    status ENUM('ativa', 'inativa') DEFAULT 'inativa',
    FOREIGN KEY (id_professor) REFERENCES professor(id_professor)
);

CREATE TABLE pagamento (
    id_pagamento INT PRIMARY KEY AUTO_INCREMENT,
    id_professor INT NOT NULL,
    valor DECIMAL(10,2) NOT NULL,
    forma_pagamento ENUM('Pix', 'Boleto', 'Visa', 'Mastercard') NOT NULL,
    data_pagamento TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (id_professor) REFERENCES professor(id_professor)
);

CREATE TABLE problemas (
    id_problema INT PRIMARY KEY AUTO_INCREMENT,
    id_professor INT NOT NULL,
    descricao TEXT,
    data_registro TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (id_professor) REFERENCES professor(id_professor)
);

-- Tabela reserva (apenas para a consulta 2)
CREATE TABLE reserva (
    id_reserva INT PRIMARY KEY AUTO_INCREMENT,
    id_professor INT NOT NULL,
    FOREIGN KEY (id_professor) REFERENCES professor(id_professor)
);

-- Inserindo professores

INSERT INTO professor (id_professor, nome, departamento) VALUES
(1, 'Ana Paula', 'Engenharia'),
(2, 'João Pedro', 'Direito'),
(3, 'Carlos Silva', 'Economia'),
(4, 'Carla Menezes', 'Administração'),
(5, 'Beatriz Gonçalves', 'Psicologia'),
(6, 'Lucas Almeida', 'Arquitetura');

-- Inserindo reservas (para consulta 2)

INSERT INTO reserva (id_professor) VALUES
(3), -- Carlos Silva
(6); -- Lucas Almeida

-- Inserindo tags

INSERT INTO tag_estacionamento (id_tag, id_professor, tag, status) VALUES
(1, 1, 'TAG123ABC', 'ativa'),     -- Ana Paula
(2, 2, 'TAG987ZYX', 'ativa'),     -- João Pedro
(3, 4, 'TAG654TRE', 'inativa');   -- Carla Menezes

-- Inserindo pagamentos

INSERT INTO pagamento (id_pagamento, id_professor, valor, forma_pagamento, data_pagamento) VALUES
(1, 1, 100.00, 'Visa', '2024-03-10 12:00:00'),   -- Ana Paula
(2, 2, 120.00, 'Visa', '2024-03-15 09:30:00');   -- João Pedro

-- Inserindo problemas (consulta 10)

INSERT INTO problemas (id_problema, id_professor, descricao, data_registro) VALUES
(1, 1, 'Falha na leitura da tag', '2024-03-16 08:45:00'),   -- Ana Paula
(2, 2, 'Tag desprogramada', '2024-03-17 14:10:00');         -- João Pedro
