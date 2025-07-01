CREATE DATABASE IF NOT EXISTS estacionamento;
USE estacionamento;

-- Tabela de Controle de Acesso
CREATE TABLE Access_Control (
    id INT PRIMARY KEY AUTO_INCREMENT,
    description VARCHAR(255)
);

-- Tabela de Clientes
CREATE TABLE Clients (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    phone_number VARCHAR(20),
    registration_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Tabela de Veículos
CREATE TABLE Vehicles (
    plate VARCHAR(20) PRIMARY KEY,
    model VARCHAR(100) NOT NULL,
    color VARCHAR(50),
    client_id INT NOT NULL,
    FOREIGN KEY (client_id) REFERENCES Clients(id) ON DELETE CASCADE
);

-- Tabela de Espaços de Estacionamento (Vagas)
CREATE TABLE Parking_Spaces (
    id INT PRIMARY KEY AUTO_INCREMENT,
    code VARCHAR(50) UNIQUE NOT NULL,
    status ENUM('available', 'occupied', 'reserved') NOT NULL,
    rate_id INT NOT NULL,
    FOREIGN KEY (rate_id) REFERENCES Rates(id) ON DELETE SET NULL
);

-- Tabela de Tarifas
CREATE TABLE Rates (
    id INT PRIMARY KEY AUTO_INCREMENT,
    type ENUM('hourly', 'daily', 'monthly') NOT NULL,
    price DECIMAL(10,2) NOT NULL,
    min_time INT NOT NULL,
    max_time INT NOT NULL
);

-- Tabela de Registros de Estacionamento (Controle de Saída)
CREATE TABLE Parking_Records (
    id INT PRIMARY KEY AUTO_INCREMENT,
    vehicle_plate VARCHAR(20) NOT NULL,
    parking_id INT NOT NULL,
    entry TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    exit TIMESTAMP NULL,
    duration INT,
    price_id INT NOT NULL,
    total_price DECIMAL(10,2),
    status ENUM('active', 'completed') NOT NULL,
    FOREIGN KEY (vehicle_plate) REFERENCES Vehicles(plate) ON DELETE CASCADE,
    FOREIGN KEY (parking_id) REFERENCES Parking_Spaces(id) ON DELETE CASCADE,
    FOREIGN KEY (price_id) REFERENCES Rates(id) ON DELETE SET NULL
);

-- Tabela de Reservas
CREATE TABLE Reservations (
    id INT PRIMARY KEY AUTO_INCREMENT,
    client_id INT NOT NULL,
    parking_id INT NOT NULL,
    reservation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    expiration_date TIMESTAMP NOT NULL,
    status ENUM('pending', 'confirmed', 'canceled') NOT NULL,
    FOREIGN KEY (client_id) REFERENCES Clients(id) ON DELETE CASCADE,
    FOREIGN KEY (parking_id) REFERENCES Parking_Spaces(id) ON DELETE CASCADE
);

-- Tabela de Pagamentos
CREATE TABLE Payments (
    id INT PRIMARY KEY AUTO_INCREMENT,
    client_id INT NOT NULL,
    amount DECIMAL(10,2) NOT NULL,
    payment_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    method ENUM('credit_card', 'debit_card', 'cash', 'digital_wallet') NOT NULL,
    status ENUM('pending', 'completed', 'failed') NOT NULL,
    FOREIGN KEY (client_id) REFERENCES Clients(id) ON DELETE CASCADE
);

-- Tabela de Funcionários
CREATE TABLE Employees (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    role VARCHAR(100) NOT NULL,
    contact VARCHAR(50),
    assigned_parking_id INT NOT NULL,
    FOREIGN KEY (assigned_parking_id) REFERENCES Parking_Spaces(id) ON DELETE SET NULL
);

-- Tabela de Histórico de Acesso
CREATE TABLE Access_History (
    id INT PRIMARY KEY AUTO_INCREMENT,
    client_id INT NOT NULL,
    vehicle_plate VARCHAR(20) NOT NULL,
    entry_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    exit_time TIMESTAMP NULL,
    FOREIGN KEY (client_id) REFERENCES Clients(id) ON DELETE CASCADE,
    FOREIGN KEY (vehicle_plate) REFERENCES Vehicles(plate) ON DELETE CASCADE
);

-- Tabela de Multas
CREATE TABLE Fines (
    id INT PRIMARY KEY AUTO_INCREMENT,
    parking_record_id INT NOT NULL,
    amount DECIMAL(10,2) NOT NULL,
    reason VARCHAR(255),
    date_issued TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status ENUM('pending', 'paid') NOT NULL,
    FOREIGN KEY (parking_record_id) REFERENCES Parking_Records(id) ON DELETE CASCADE
);

-- Tabela de Permissões
CREATE TABLE Permissions (
    id INT PRIMARY KEY AUTO_INCREMENT,
    client_id INT NOT NULL,
    permission_level ENUM('read', 'write', 'admin') NOT NULL,
    FOREIGN KEY (client_id) REFERENCES Clients(id) ON DELETE CASCADE
);

-- Tabela de Avaliações
CREATE TABLE Reviews (
    id INT PRIMARY KEY AUTO_INCREMENT,
    client_id INT NOT NULL,
    rating INT CHECK (rating BETWEEN 1 AND 5),
    comment TEXT,
    date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (client_id) REFERENCES Clients(id) ON DELETE CASCADE
);

-- Tabela de Notificações
CREATE TABLE Notifications (
    id INT PRIMARY KEY AUTO_INCREMENT,
    client_id INT NOT NULL,
    message TEXT NOT NULL,
    date_sent TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status ENUM('unread', 'read') NOT NULL,
    FOREIGN KEY (client_id) REFERENCES Clients(id) ON DELETE CASCADE
);
