USE nomadaDB;

CREATE TABLE UsuariosPrueba(
    usuario_id INT IDENTITY(1, 1) PRIMARY KEY,
    nombre NVARCHAR(100),
    email NVARCHAR(100),
    pais NVARCHAR(50),
    ciudad NVARCHAR(50),
    fecha_registro DATE
);

GO

INSERT INTO UsuariosPrueba (nombre, email, pais, ciudad, fecha_registro)
VALUES
    ('Ana García', 'ana@gmail.com', 'Perú', 'Lima', '2023-01-15'),
    ('Carlos López', 'carlos@gmail.com', 'México', 'CDMX', '2023-02-20'),
    ('María Torres', 'maria@gmail.com', 'España', 'Madrid', '2023-03-10'),
    ('Juan Pérez', 'juan@gmail.com', 'Perú', 'Cajamarca', '2023-04-05'),
    ('Lucía Méndez', 'lucia@gmail.com', 'Perú', 'Trujillo', '2023-05-11'),
    ('Roberto Sánchez', 'roberto@gmail.com', 'España', 'Madrid', '2023-06-23'),
    ('Elena Gómez', 'elena@gmail.com', 'México', 'Monterrey', '2023-07-22');
GO

CREATE INDEX IX_UsuariosPrueba_Email
ON UsuariosPrueba (email);
GO

CREATE INDEX IX_UsuariosPrueba_Pais_Ciudad
ON UsuariosPrueba (pais, ciudad);
GO

PRINT '=== PRUEBA 1: Usando el Índice Simple ==='
SELECT nombre, email
FROM UsuariosPrueba
WHERE email = 'juan@gmail.com';
GO

PRINT '=== PRUEBA 2: Usando el Índice Compuesto (Completo) ==='
SELECT nombre, pais, ciudad
FROM UsuariosPrueba
WHERE pais = 'España' AND ciudad = 'Madrid';
GO

PRINT '=== PRUEBA 3: Usando el Índice Compuesto (Parcial) ==='
SELECT nombre, pais
FROM UsuariosPrueba
WHERE pais = 'Perú';
GO

PRINT '=== PRUEBA 4: Usando el Índice Compuesto de forma no óptima ==='
SELECT nombre, ciudad
FROM UsuariosPrueba
WHERE ciudad = 'Lima';
GO