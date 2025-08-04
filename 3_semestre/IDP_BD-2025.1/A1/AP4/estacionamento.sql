CREATE DATABASE IF NOT EXISTS estacionamento;
USE estacionamento;

CREATE TABLE Docente (
    docente_id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    telefone VARCHAR(20) NOT NULL
);

CREATE TABLE Veiculo (
    veiculo_id INT PRIMARY KEY AUTO_INCREMENT,
    docente_id INT NOT NULL,
    placa VARCHAR(20) UNIQUE NOT NULL,
    modelo VARCHAR(50) NOT NULL,
    FOREIGN KEY (docente_id) REFERENCES Docente(docente_id) ON DELETE CASCADE
);

CREATE TABLE Vaga (
    vaga_id INT PRIMARY KEY AUTO_INCREMENT,
    status ENUM('disponível', 'reservada') NOT NULL DEFAULT 'disponível'
);

CREATE TABLE Reserva (
    reserva_id INT PRIMARY KEY AUTO_INCREMENT,
    docente_id INT NOT NULL,
    veiculo_id INT NOT NULL,
    vaga_id INT NOT NULL,
    data_reserva DATE NOT NULL,
    hora_reserva TIME NOT NULL,
    FOREIGN KEY (docente_id) REFERENCES Docente(docente_id) ON DELETE CASCADE,
    FOREIGN KEY (veiculo_id) REFERENCES Veiculo(veiculo_id) ON DELETE CASCADE,
    FOREIGN KEY (vaga_id) REFERENCES Vaga(vaga_id) ON DELETE CASCADE,
    UNIQUE (veiculo_id, data_reserva) -- Índice para evitar reservas duplicadas para o mesmo veículo
);


INSERT INTO Docente (nome, email, telefone) VALUES
('Carlos Silva', 'carlos.silva@email.com', '11987654321'),
('Mariana Souza', 'mariana.souza@email.com', '11912345678'),
('Roberto Lima', 'roberto.lima@email.com', '11956789012');

INSERT INTO Veiculo (docente_id, placa, modelo) VALUES
(1, 'ABC-1234', 'Toyota Corolla'),
(2, 'DEF-5678', 'Honda Civic'),
(3, 'GHI-9012', 'Ford Focus');

INSERT INTO Vaga (status) VALUES
('disponível'),
('disponível'),
('reservada');

INSERT INTO Reserva (docente_id, veiculo_id, vaga_id, data_reserva, hora_reserva) VALUES
(1, 1, 1, '2024-06-10', '08:00:00'),
(2, 2, 2, '2024-06-10', '09:00:00');

SELECT * FROM Docente;
SELECT * FROM Veiculo;
SELECT * FROM Vaga;
SELECT * FROM Reserva;
