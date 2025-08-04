SELECT m.nome AS marca, AVG(c.preco) AS media_preco
FROM carros c
JOIN modelos mo   ON c.modelo_id = mo.modelo_id
JOIN marcas m     ON mo.marca_id = m.marca_id
GROUP BY m.nome
ORDER BY media_preco DESC;

SELECT c.ano, ca.tipo AS cambio, COUNT(*) AS qtd
FROM carros c
JOIN cambios ca ON c.cambio_id = ca.cambio_id
GROUP BY c.ano, ca.tipo
ORDER BY c.ano, qtd DESC;

SELECT m.nome AS marca, mo.nome AS modelo, c.ano, mo2.litragem
FROM carros c
JOIN modelos mo    ON c.modelo_id = mo.modelo_id
JOIN marcas m      ON mo.marca_id = m.marca_id
JOIN motores mo2   ON c.motor_id = mo2.motor_id
WHERE c.ano >= 2020 AND mo2.litragem >= 2.0;
