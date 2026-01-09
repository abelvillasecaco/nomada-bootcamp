CREATE TABLE Estudiantes (
    id_estudiante INT PRIMARY KEY IDENTITY,
    nombre VARCHAR(100),
    edad INT,
    carrera VARCHAR(100),
    email VARCHAR(100)
);

INSERT INTO Estudiantes (nombre, edad, carrera, email) VALUES 
('Ana López', 22, 'Ingeniería', 'ana@gmail.com'),
('Pedro Ruíz', 19, 'Arquitectura', NULL),
('Lucía Paredes', 24, 'Ingeniería', 'lucia@gmail.com'),
('Carlos Vera', 17, 'Diseño', NULL),
('Marta Salas', 22, 'Arquitectura', 'marta@gmail.com');

SELECT * FROM Estudiantes;

-- Muestra todos los estudiantes que estudian Ingeniería.
SELECT * FROM Estudiantes
WHERE carrera = 'Ingeniería';

-- Muestra los estudiantes cuya edad sea mayor a 20 y estudian Arquitectura.
SELECT * FROM Estudiantes
WHERE edad > 20 AND carrera = 'Arquitectura';

-- Muestra los estudiantes que no tienen correo electrónico registrado.
SELECT * FROM Estudiantes
WHERE email IS NULL;

-- Ordena los estudiantes por edad de mayor a menor.
SELECT * FROM Estudiantes
ORDER BY edad DESC;

-- Muestra los 3 primeros estudiantes registrados (por orden de ID).
SELECT TOP 3 * FROM Estudiantes
ORDER BY id_estudiante ASC

-- Muestra los estudiantes cuya edad no sea 22.
SELECT * FROM Estudiantes
WHERE edad != 22;

-- Muestra los estudiantes que tengan entre 18 y 24 años.
SELECT * FROM Estudiantes
-- WHERE edad > 17 AND edad < 25
WHERE edad BETWEEN 18 AND 24;