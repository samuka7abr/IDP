INSERT INTO alunos VALUES
(1, 'Alice', 6.50),
(2, 'Bruno', 8.20),
(3, 'Carla', 4.30);

UPDATE alunos
SET nota = 7.75
WHERE id = 1;

DELETE FROM alunos
WHERE nota < 5;
