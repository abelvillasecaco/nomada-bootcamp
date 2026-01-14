USE nomadaDB;

-- Crea la tabla CursosEstudiantes con las siguientes columnas:

-- ID (entero, autoincremental, clave primaria)
-- NombreEstudiante (nombre completo, tipo texto adecuado)
-- Edad (entero)
-- Curso (nombre del curso, tipo texto adecuado)
-- Email (correo electrónico del estudiante, debe ser único)
-- NotaFinal (número decimal)
-- FechaRegistro (fecha del registro)

CREATE TABLE CursosEstudiantes(
    id_cursosestudiantes INT IDENTITY(1, 1) PRIMARY KEY,
    nombre_estudiante NVARCHAR(100) NOT NULL,
    edad INT NOT NULL,
    email NVARCHAR(50) NOT NULL,
    nota_final DECIMAL(10, 2) NOT NULL,
    fecha_registro DATE NOT NULL
)

SELECT * FROM CursosEstudiantes;

-- VARCHAR: Texto NO UNICODE => no soportan ñ, tilde, caracteres especiales
-- NVARCHAR: Texto UNICODE => soporta ñ, tilde, caracteres especiales

-- COLLATION => cómo se comparan los textos, cómo se ordenan, dinstingue entre mayúscula y minúscula, tildes, 
-- el juego de caracteres que se utiliza

SELECT DATABASEPROPERTYEX(DB_NAME(), 'Collation') AS CollationBaseDatos;

-- SQL_ => Collation legacy (propia de version antiguas de SQL)
-- Latin1_General => Reglas generales para idiomas latinos
-- CP1 => Code Page 1252 (Windows Western European)
-- CI => Case Insensitive (no distingue entre mayúsculas/minúsculas)
-- AS => Accent Sensitive (sí distingue tildes)

-- Ana = ana
-- Jose != José
-- Soporta español limitadamente
-- No es UNICODE real

INSERT INTO CursosEstudiantes
    (nombre_estudiante, edad, curso, email, nota_final, fecha_registro)
VALUES
    ('Ana Torres', 22, 'JavaScript', 'ana.torres@gmail.com', 15, '2025-01-10'),
    ('Carlos Medina', 24, 'Python', 'carlos.medina', 12, '2025-01-12'),
    ('Lucía Ramos', 21, 'JavaScript', 'lucia.ramos@gmail.com', 9.50, '2025-01-15'),
    ('José Castillo', 26, 'C++', 'jose.castillo', 14, '2025-01-18'),
    ('María López', 23, 'JavaScript', 'maria.lopez@gmail.com', 16, '2025-01-20'),
    ('Pedro Salazar', 28, 'Java', 'pedro.salazar@gmail.com', 11.50, '2025-01-22');

-- Muestra los estudiantes con nota mayor o igual a 14
-- Muestra los que no están inscritos en JavaScript
-- Muestra los que no tienen email registrado
-- Muestra los 3 estudiantes más recientes (por FechaRegistro)
-- Muestra los estudiantes con nota mayor a 12 y edad menor a 25
-- Ordena todos los estudiantes por NotaFinal de mayor a menor
-- Muestra los estudiantes cuya NotaFinal esté entre 10 y 13 inclusive

SELECT * FROM CursosEstudiantes
WHERE nota_final >= 14;

SELECT * FROM CursosEstudiantes
WHERE curso != 'JavaScript';

SELECT TOP 3 *
FROM CursosEstudiantes
ORDER BY fecha_registro DESC;

SELECT * FROM CursosEstudiantes
WHERE nota_final > 12 AND edad < 25;

SELECT * FROM CursosEstudiantes ORDER BY nota_final DESC;

SELECT * FROM CursosEstudiantes WHERE nota_final BETWEEN 10 AND 13;