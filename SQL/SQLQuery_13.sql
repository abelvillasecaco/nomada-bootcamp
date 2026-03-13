USE nomadaDB;

-- Una universidad tiene una base de datos académica con dos tablas principales: Estudiantes e Inscripciones.
-- Cada vez que los administrativos revisan el sistema, hacen las siguientes consultas frecuentes:

-- 1. Buscar a todos los estudiantes inscritos en un curso específico (curso_id) en un determinado semestre (semestre).
-- 2. Obtener la lista de inscripciones junto con el nombre del estudiante y filtrar por apellidos (apellido) y por semestre.

-- Tareas:

-- Crear la base de datos y las dos tablas (Estudiantes y Inscripciones).
-- Insertar datos de prueba.
-- Crear un índice simple sobre el campo curso_id en la tabla Inscripciones.
-- Crear un índice compuesto sobre (semestre, curso_id) en la tabla Inscripciones.
-- Crear un índice compuesto sobre (apellido, nombre) en Estudiantes.
-- Ejecutar y analizar una consulta que se beneficie de los índices.

DROP TABLE IF EXISTS Estudiantes;
GO

CREATE TABLE Estudiantes (
    estudiante_id INT IDENTITY(1, 1) PRIMARY KEY,
    nombre NVARCHAR(100) NOT NULL,
    apellido NVARCHAR(100) NOT NULL,
    email NVARCHAR(100)
);
GO

CREATE TABLE Inscripciones (
    inscripcion_id INT IDENTITY(1, 1) PRIMARY KEY,
    estudiante_id INT NOT NULL,
    curso_id INT NOT NULL,
    semestre NVARCHAR(20) NOT NULL, -- '2026-I', '2026-II'
    fecha_inscripcion DATE DEFAULT GETDATE(),
    CONSTRAINT FK_Inscripciones_Estudiantes FOREIGN KEY (estudiante_id) REFERENCES Estudiantes(estudiante_id)
);
GO

INSERT INTO Estudiantes (nombre, apellido, email) VALUES
('Pepe', 'Mujica', 'pepe@gmail.com'),
('Ana', 'García', 'ana@gmail.com'),
('Carlos', 'López', 'carlos@gmail.com'),
('Lucía', 'Terrones', 'lucia@gmail.com'),
('Pedro', 'García', 'pedro@gmail.com');

INSERT INTO Inscripciones (estudiante_id, curso_id, semestre) VALUES
(1, 101, '2023-II'),
(1, 102, '2024-I'),
(2, 101, '2024-I'),
(2, 103, '2024-I'),
(3, 102, '2023-II'),
(3, 104, '2024-I'),
(4, 101, '2024-I'),
(4, 105, '2024-II'),
(5, 101, '2024-I');
GO

SELECT * FROM Estudiantes;
SELECT * FROM Inscripciones;

-- Índice Simple
CREATE INDEX IX_Inscripciones_Curso
ON Inscripciones (curso_id);
GO

-- Índice Compuesto 1
CREATE INDEX IX_Inscripciones_Semestre_Curso
ON Inscripciones (semestre, curso_id);
GO

-- Índice Compuesto 2
CREATE INDEX IX_Estudiantes_Apellido_Nombre
ON Estudiantes (apellido, nombre);
GO

PRINT '=== CONSULTA 1: Buscar estudiantes en un curso y semestre específico ===';

SELECT  inscripcion_id, estudiante_id, curso_id, semestre
FROM Inscripciones
WHERE semestre = '2024-I' AND curso_id = 101;
GO

-- Haz una lista de inscripciones filtrando por apellido y semestre
SELECT E.apellido, E.nombre, I.semestre, I.curso_id
FROM Estudiantes AS E
INNER JOIN Inscripciones AS I ON E.estudiante_id = I.estudiante_id
WHERE E.apellido = 'García' AND I.semestre = '2024-I';
GO