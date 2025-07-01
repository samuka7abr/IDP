INSERT INTO marcas (nome)
SELECT DISTINCT Brand FROM mytable;

INSERT INTO modelos (nome, marca_id)
SELECT DISTINCT Model, m.marca_id
FROM mytable t
JOIN marcas m ON t.Brand = m.nome;

INSERT INTO combustiveis (tipo)
SELECT DISTINCT Fuel_Type FROM mytable;

INSERT INTO cambios (tipo)
SELECT DISTINCT Transmission FROM mytable;

INSERT INTO motores (litragem)
SELECT DISTINCT Engine_Size FROM mytable;

INSERT INTO carros (modelo_id, motor_id, combustivel_id, cambio_id, ano, quilometragem, portas, proprietarios, preco)
SELECT
  mo.modelo_id,
  mo2.motor_id,
  co.combustivel_id,
  ca.cambio_id,
  t.Year,
  t.Mileage,
  t.Doors,
  t.Owner_Count,
  t.Price
FROM mytable t
JOIN modelos mo      ON t.Model = mo.nome
JOIN motores mo2     ON t.Engine_Size = mo2.litragem
JOIN combustiveis co ON t.Fuel_Type = co.tipo
JOIN cambios ca      ON t.Transmission = ca.tipo;
