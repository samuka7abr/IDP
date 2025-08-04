CREATE DATABASE IF NOT EXISTS naruto;
USE naruto;

CREATE TABLE IF NOT EXISTS personagens (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    habilidade_principal VARCHAR(255) NOT NULL,
    natureza_chakra ENUM('fogo', 'agua', 'terra', 'vento', 'raio', 'não definido') DEFAULT 'não definido'
);

INSERT INTO personagens (nome, habilidade_principal, natureza_chakra) VALUES
('Naruto Uzumaki', 'Kage Bunshin no Jutsu', 'vento'),
('Sasuke Uchiha', 'Chidori', 'raio'),
('Sakura Haruno', 'Força aprimorada', 'não definido'),
('Kakashi Hatake', 'Raikiri (Chidori aprimorado)', 'raio'),

('Hinata Hyuga', 'Byakugan e Juuken', 'não definido'),
('Kiba Inuzuka', 'Jujin Bunshin', 'não definido'),
('Shino Aburame', 'Controle de insetos', 'não definido'),
('Kurenai Yuhi', 'Genjutsu avançado', 'não definido'),

('Neji Hyuga', 'Byakugan e Juuken avançado', 'não definido'),
('Tenten', 'Kuchiyose de armas', 'não definido'),
('Rock Lee', 'Taijutsu extremo', 'não definido'),

('Shikamaru Nara', 'Jutsu das Sombras', 'não definido'),
('Ino Yamanaka', 'Jutsu de Possessão Mental', 'não definido'),
('Choji Akimichi', 'Baika no Jutsu', 'não definido'),
('Asuma Sarutobi', 'Punhos com lâminas de chakra', 'vento'),

('Dosu Kinuta', 'Vibração Sonora', 'não definido'),
('Zaku Abumi', 'Jutsu das Ondas de Ar', 'vento'),
('Kin Tsuchi', 'Genjutsu com sinos', 'não definido'),

('Gaara', 'Controle da Areia', 'terra'),
('Temari', 'Kuchiyose e Jutsu do Leque', 'vento'),
('Kankuro', 'Manipulação de Marionetes', 'não definido'),

('Orochimaru', 'Jutsu proibidos e Edo Tensei', 'não definido'),
('Kabuto Yakushi', 'Regeneração e Ninjutsu Médico', 'não definido'),
('Anko Mitarashi', 'Jutsus com cobras', 'não definido');

SELECT * FROM personagens;