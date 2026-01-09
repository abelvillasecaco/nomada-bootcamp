-- INTRODUCCIÓN A SQL

-- PASO 1: Crear base de datos:

-- CREATE DATABASE nomadaDB;

-- PASO 2: Usar la base de datos:
USE nomadaDB;

-- PASO 3: Crear las tablas
CREATE TABLE Usuarios (

    id_usuario INT PRIMARY KEY IDENTITY, --autoincrementa
    nombre VARCHAR(50),
    email VARCHAR(100) UNIQUE,
    edad INT
);

-- PASO 4: Insertar datos
-- INSERT INTO Usuarios (nombre, email, edad) VALUES ('Juan', 'juan@gmail.com', 25);
-- INSERT INTO Usuarios (nombre, email, edad) VALUES ('Ana', 'ana@gmail.com', 30);
-- INSERT INTO Usuarios (nombre, email, edad) VALUES ('Luis', 'luis@gmail.com', 15);

-- PASO 5: Consultar datos
SELECT * FROM Usuarios;
SELECT TOP 1 * FROM Usuarios;
SELECT * FROM Usuarios WHERE edad < 25;

-- PASO 6: Actualizar usuarios
UPDATE Usuarios
SET nombre = 'Juana',
    email = 'juana@gmail.com'
WHERE id_usuario = 2;

-- PASO 7: Eliminar usuarios
DELETE FROM Usuarios WHERE id_usuario = 2;

-- CRUD
-- Create, Read, Update, Delete
