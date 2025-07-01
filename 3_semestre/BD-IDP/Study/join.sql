-- Criando o banco de dados
CREATE DATABASE IF NOT EXISTS Escola;
USE Escola;

CREATE TABLE Curso (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome_curso VARCHAR(50) NOT NULL
);

-- Criando a tabela Aluno
CREATE TABLE Aluno (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    idade INT NOT NULL,
    curso_id INT,
    FOREIGN KEY (curso_id) REFERENCES Curso(id)
);

-- Criando a tabela Professores
CREATE TABLE Professores (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    curso_id INT,
    FOREIGN KEY (curso_id) REFERENCES Curso(id)
);

-- Inserindo cursos
INSERT INTO Curso (id, nome_curso) VALUES
(1, 'Sistemas de Informação'),
(2, 'Administração'),
(3, 'Ciência da Computação');

-- Inserindo alunos
INSERT INTO Aluno (id, nome, idade, curso_id) VALUES
(1, 'Ana', 20, 1),
(2, 'João', 22, 2),
(3, 'Maria', 19, 1),
(4, 'Pedro', 25, 3),
(5, 'Lucas', 21, NULL); -- Lucas não está em nenhum curso

-- Inserindo professores
INSERT INTO Professores (id, nome, curso_id) VALUES
(1, 'Carlos', 1),
(2, 'Fernanda', 2),
(3, 'Marcos', 3);

-- Exercícios de JOIN
-- 1. Liste os alunos com os respectivos cursos matriculados.
SELECT Aluno.nome, Curso.nome_curso 
FROM Aluno 
JOIN Curso ON Curso.id=Aluno.curso_id;
-- 2. Liste os professores e os cursos que eles ministram.
SELECT Professores.nome, Curso.nome_curso 
FROM Professores 
JOIN Curso ON Curso.id=Professores.curso_id;
-- 3. Liste os alunos que não estão matriculados em nenhum curso.
SELECT Aluno.nome, Curso.nome_curso 
FROM Aluno 
JOIN Curso ON ISNULL(Curso.id)=Aluno.curso_id; --não consegui fazer e te mandei o comando que eu tentei
-- 4. Liste os cursos que não possuem alunos matriculados.
SELECT Curso.nome_curso, Aluno.nome 
FROM Curso 
JOIN Aluno ON ISNULL(Aluno.curso_id)=Curso.id; --não consegui fazer e te mandei o comando que eu tentei
-- 5. Liste os alunos e seus professores responsáveis pelo curso matriculado.
SELECT Aluno.nome, Professores.nome, Curso.nome_Curso 
FROM Aluno
JOIN Professores ON Professores.curso_id=Curso.id 
JOIN Curso ON Curso.id=Curso.id 


-- CORREÇÃO

-- 1. Liste os alunos com os respectivos cursos matriculados.
SELECT Aluno.nome, Curso.nome_curso 
FROM Aluno 
JOIN Curso ON Curso.id = Aluno.curso_id;

-- 2. Liste os professores e os cursos que eles ministram.
SELECT Professores.nome, Curso.nome_curso 
FROM Professores 
JOIN Curso ON Curso.id = Professores.curso_id;

-- 3. Liste os alunos que não estão matriculados em nenhum curso.
SELECT Aluno.nome 
FROM Aluno 
LEFT JOIN Curso ON Curso.id = Aluno.curso_id
WHERE Aluno.curso_id IS NULL;

-- 4. Liste os cursos que não possuem alunos matriculados.
SELECT Curso.nome_curso 
FROM Curso 
LEFT JOIN Aluno ON Curso.id = Aluno.curso_id
WHERE Aluno.curso_id IS NULL;

-- 5. Liste os alunos e seus professores responsáveis pelo curso matriculado.
SELECT Aluno.nome AS Nome_Aluno, Professores.nome AS Nome_Professor, Curso.nome_curso 
FROM Aluno
JOIN Curso ON Aluno.curso_id = Curso.id
JOIN Professores ON Professores.curso_id = Curso.id;
