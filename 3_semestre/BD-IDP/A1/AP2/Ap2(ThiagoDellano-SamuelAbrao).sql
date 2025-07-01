-- Tabela de Controle de Acesso
CREATE TABLE Access_Control (
    id INT PRIMARY KEY AUTO_INCREMENT,
    description VARCHAR(255)
);

-- Tabela de Usuários
CREATE TABLE Users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    access_control_id INT,
    name VARCHAR(255),
    email VARCHAR(255) UNIQUE,
    password VARCHAR(255),
    type ENUM('admin', 'customer', 'employee'),
    phone_number VARCHAR(20),
    role VARCHAR(50),
    FOREIGN KEY (access_control_id) REFERENCES Access_Control(id)
);

-- Tabela de Veículos
CREATE TABLE Vehicle (
    plate VARCHAR(20) PRIMARY KEY,
    model VARCHAR(100),
    color VARCHAR(50),
    owner_id INT,
    FOREIGN KEY (owner_id) REFERENCES Users(id)
);

-- Tabela de Espaços de Estacionamento
CREATE TABLE Parking_Space (
    id INT PRIMARY KEY AUTO_INCREMENT,
    code VARCHAR(50) UNIQUE,
    stats ENUM('available', 'occupied', 'reserved'),
    rate_id INT,
    FOREIGN KEY (rate_id) REFERENCES Rates(id)
);

-- Tabela de Tarifas
CREATE TABLE Rates (
    id INT PRIMARY KEY AUTO_INCREMENT,
    type ENUM('hourly', 'daily', 'monthly'),
    price DECIMAL(10,2),
    min_time INT,
    max_time INT
);

-- Tabela de Registros de Estacionamento
CREATE TABLE Register (
    id INT PRIMARY KEY AUTO_INCREMENT,
    vehicle_plate VARCHAR(20),
    parking_id INT,
    entry TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    exit TIMESTAMP NULL,
    time_remained INT,
    price_id INT,
    price_total DECIMAL(10,2),
    status ENUM('active', 'completed'),
    FOREIGN KEY (vehicle_plate) REFERENCES Vehicle(plate),
    FOREIGN KEY (parking_id) REFERENCES Parking_Space(id),
    FOREIGN KEY (price_id) REFERENCES Rates(id)
);

-- Tabela de Reservas
CREATE TABLE Reservations (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    parking_id INT,
    date_time TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES Users(id),
    FOREIGN KEY (parking_id) REFERENCES Parking_Space(id)
);

-- Tabela de Pagamentos
CREATE TABLE Payments (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    amount DECIMAL(10,2),
    date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    method ENUM('credit_card', 'debit_card', 'cash', 'digital_wallet'),
    status ENUM('pending', 'completed', 'failed'),
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

-- Tabela de Histórico de Acesso
CREATE TABLE Access_History (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    vehicle_plate VARCHAR(20),
    entry_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    exit_time TIMESTAMP NULL,
    FOREIGN KEY (user_id) REFERENCES Users(id),
    FOREIGN KEY (vehicle_plate) REFERENCES Vehicle(plate)
);

-- Tabela de Multas
CREATE TABLE Fines (
    id INT PRIMARY KEY AUTO_INCREMENT,
    register_id INT,
    amount DECIMAL(10,2),
    reason VARCHAR(255),
    date_issued TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status ENUM('pending', 'paid'),
    FOREIGN KEY (register_id) REFERENCES Register(id)
);

-- Tabela de Funcionários
CREATE TABLE Employees (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255),
    role VARCHAR(100),
    contact VARCHAR(50),
    assigned_parking_id INT,
    FOREIGN KEY (assigned_parking_id) REFERENCES Parking_Space(id)
);

-- Tabela de Permissões
CREATE TABLE Permissions (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    permission_level ENUM('read', 'write', 'admin'),
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

-- Tabela de Avaliações
CREATE TABLE Reviews (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    rating INT CHECK (rating BETWEEN 1 AND 5),
    comment TEXT,
    date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

-- Tabela de Notificações
CREATE TABLE Notifications (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    message TEXT,
    date_sent TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status ENUM('unread', 'read'),
    FOREIGN KEY (user_id) REFERENCES Users(id)
);
