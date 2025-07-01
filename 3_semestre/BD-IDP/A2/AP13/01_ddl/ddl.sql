CREATE TABLE marcas (
  marca_id    SERIAL PRIMARY KEY,
  nome        VARCHAR(50) NOT NULL UNIQUE
);

CREATE TABLE modelos (
  modelo_id   SERIAL PRIMARY KEY,
  nome        VARCHAR(50) NOT NULL,
  marca_id    INTEGER NOT NULL REFERENCES marcas(marca_id),
  UNIQUE(nome, marca_id)
);

CREATE TABLE combustiveis (
  combustivel_id  SERIAL PRIMARY KEY,
  tipo            VARCHAR(20) NOT NULL UNIQUE
);

CREATE TABLE cambios (
  cambio_id   SERIAL PRIMARY KEY,
  tipo        VARCHAR(20) NOT NULL UNIQUE
);

CREATE TABLE motores (
  motor_id    SERIAL PRIMARY KEY,
  litragem    NUMERIC(3,1) NOT NULL UNIQUE
);

CREATE TABLE carros (
  carro_id       SERIAL PRIMARY KEY,
  modelo_id      INTEGER NOT NULL REFERENCES modelos(modelo_id),
  motor_id       INTEGER NOT NULL REFERENCES motores(motor_id),
  combustivel_id INTEGER NOT NULL REFERENCES combustiveis(combustivel_id),
  cambio_id      INTEGER NOT NULL REFERENCES cambios(cambio_id),
  ano            INTEGER NOT NULL,
  quilometragem  INTEGER NOT NULL,
  portas         INTEGER NOT NULL,
  proprietarios  INTEGER NOT NULL,
  preco          INTEGER NOT NULL
);
