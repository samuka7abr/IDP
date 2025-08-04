USE futebol;

INSERT INTO time (nome) VALUES ('Corinthians');

SET @time_id = LAST_INSERT_ID();

INSERT INTO estadio (nome, publico, capacidade, time_id) 
VALUES ('Neo Química Arena', 63267, NULL, @time_id);

INSERT INTO jogadores (nome, idade, time_id) 
VALUES 
    ('Cássio', 33, @time_id), 
    ('Luan', 27, @time_id);
