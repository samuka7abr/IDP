
CREATE TABLE Aluno (
    id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    idade INT CHECK (idade >= 18),
    email VARCHAR(255) UNIQUE NOT NULL
);

CREATE TABLE Curso (
    codigo INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL
);

CREATE TABLE Matricula (
    id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    aluno_id INT UNSIGNED,
    curso_id INT UNSIGNED,
    FOREIGN KEY (aluno_id) REFERENCES Aluno(id) ON DELETE CASCADE,
    FOREIGN KEY (curso_id) REFERENCES Curso(codigo) ON DELETE CASCADE
);


DELIMITER $$

CREATE TRIGGER impedir_matricula_duplicada
BEFORE INSERT ON Matricula
FOR EACH ROW
BEGIN
    IF (EXISTS (SELECT 1 FROM Matricula WHERE aluno_id = NEW.aluno_id AND curso_id = NEW.curso_id)) THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'Este aluno já está matriculado neste curso!';
    END IF;
END $$

DELIMITER ;
