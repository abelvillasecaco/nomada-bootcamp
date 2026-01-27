-- Una biblioteca quiere organizar su base de datos para gestionar los libros, autores, usuarios y los préstamos que realiza a los usuarios.

-- Se pide lo siguiente:

-- Crear las tablas necesarias con claves primarias y foráneas.
-- Establecer las relaciones adecuadas:

    -- Autores y sus libros (relación N a N)
    -- Libros con múltiples géneros (relación N a N adicional)
    -- Usuarios registrados (lectores)
    -- Préstamos realizados por los usuarios (relación 1 a N)
    -- Información sobre la devolución del libro
    -- Identificar libros no prestados, autores más prestados, préstamos activos, etc.

-- Insertar algunos datos de prueba
-- Realizar consultas JOIN

USE nomadaBiblioteca;

-- =========================================
-- 1. TABLAS PRINCIPALES (ENTIDADES FUERTES)
-- =========================================

-- TABLA AUTORES
CREATE TABLE Autores (
    id_autor INT PRIMARY KEY IDENTITY(1, 1),
    nombre NVARCHAR(100) NOT NULL,
    nacionalidad NVARCHAR(50)
);

-- TABLA GÉNEROS (Categorías)
CREATE TABLE Generos (
    id_genero INT PRIMARY KEY IDENTITY(1, 1),
    nombre NVARCHAR(50) NOT NULL
);

-- TABLA LIBROS
CREATE TABLE Libros (
    id_libro INT PRIMARY KEY IDENTITY(1, 1),
    titulo NVARCHAR(150) NOT NULL,
    anio_publicacion INT,
    stock INT DEFAULT 1
);

-- TABLA USUARIOS (Lectores)
CREATE TABLE Usuarios (
    id_usuario INT PRIMARY KEY IDENTITY(1, 1),
    nombre NVARCHAR(100) NOT NULL,
    email NVARCHAR(100) UNIQUE,
    telefono NVARCHAR(20)
);

-- =============================================
-- 2. TABLAS INTERMEDIAS (PARA RELACIONES N a N)
-- =============================================

-- AUTORES <-> LIBROS
CREATE TABLE LibroAutor (
    id_libro INT,
    id_autor INT,
    PRIMARY KEY (id_libro, id_autor), -- PK Compuesta
    FOREIGN KEY (id_libro) REFERENCES Libros(id_libro),
    FOREIGN KEY (id_autor) REFERENCES Autores(id_autor)
);

-- LIBROS <-> GÉNEROS
CREATE TABLE LibroGenero (
    id_libro INT,
    id_genero INT,
    PRIMARY KEY (id_libro, id_genero), -- PK Compuesta
    FOREIGN KEY (id_libro) REFERENCES Libros(id_libro),
    FOREIGN KEY (id_genero) REFERENCES Generos(id_genero)
);

-- ========================================
-- 3. TABLA TRANSACCIONAL (Relación 1 a N)
-- ========================================
CREATE TABLE Prestamos (
    id_prestamo INT PRIMARY KEY IDENTITY(1, 1),
    id_usuario INT NOT NULL,
    id_libro INT NOT NULL,
    fecha_prestamo DATE DEFAULT GETDATE(),
    fecha_devolucion DATE NULL,
    CONSTRAINT FK_Prestamo_Usuario FOREIGN KEY (id_usuario) REFERENCES Usuarios(id_usuario),
    CONSTRAINT FK_Prestamo_Libro FOREIGN KEY (id_libro) REFERENCES Libros(id_libro)
);

-- INSERCIÓN DE DATOS
INSERT INTO Autores (nombre, nacionalidad) VALUES
('Gabriel García Márquez', 'Colombia'),
('J.K. Rowling', 'Británica'),
('Neil Gaiman', 'Británica'),
('Terry Pratchett', 'Británica'),
('Stephen', 'Estadounidense');

SELECT * FROM Generos;

INSERT INTO Generos (nombre) VALUES
('Realismo mágico'),
('Fantasía'),
('Terror'),
('Comedia');

SELECT * FROM Libros;
SELECT * FROM Autores;
SELECT * FROM Generos;
SELECT * FROM LibroGenero;
SELECT * FROM LibroAutor;
SELECT * FROM Usuarios;
SELECT * FROM Prestamos;

INSERT INTO Libros (titulo, anio_publicacion) VALUES
('Cien Años de Soledad', 1967), -- ID 1
('Harry Potter y la Piedra Filosofal', 1997), -- ID 2
('It', 1986), -- ID 3
('Buenos Presagios', 1990), -- ID 4
('El Resplandor', 1977); -- ID 5

INSERT INTO LibroAutor (id_libro, id_autor) VALUES (1, 1);
INSERT INTO LibroAutor (id_libro, id_autor) VALUES (2, 2);
INSERT INTO LibroAutor (id_libro, id_autor) VALUES (3, 5);
INSERT INTO LibroAutor (id_libro, id_autor) VALUES (5, 5);
INSERT INTO LibroAutor (id_libro, id_autor) VALUES (4, 3), (4, 4);

INSERT INTO LibroGenero (id_libro, id_genero) VALUES (1, 1);
INSERT INTO LibroGenero (id_libro, id_genero) VALUES (2, 2);
INSERT INTO LibroGenero (id_libro, id_genero) VALUES (3, 3);
INSERT INTO LibroGenero (id_libro, id_genero) VALUES (4, 2), (4, 4);
INSERT INTO LibroGenero (id_libro, id_genero) VALUES (5, 3);

SELECT * FROM Usuarios;
SELECT * FROM Libros;

INSERT INTO Usuarios (nombre, email, telefono) VALUES ('Juan Pérez', 'juan@gmail.com', '987123543');
INSERT INTO Usuarios (nombre, email, telefono) VALUES ('Mariá Ramírez', 'maria@gmail.com', '902183423');
INSERT INTO Usuarios (nombre, email, telefono) VALUES ('Pedro Reyes', 'pedro@gmail.com', '919125398');

SELECT * FROM Prestamos;

INSERT INTO Prestamos (id_usuario, id_libro, fecha_prestamo, fecha_devolucion) VALUES (1, 2, GETDATE(), NULL);
INSERT INTO Prestamos (id_usuario, id_libro, fecha_prestamo, fecha_devolucion) VALUES (2, 3, '2023-09-29', '2023-09-30');
INSERT INTO Prestamos (id_usuario, id_libro, fecha_prestamo, fecha_devolucion) VALUES (2, 1, GETDATE(), NULL);

-- QUIERO VER EL TÍTULO DEL LIBRO Y EL NOMBRE DE SU AUTOR. SI UN LIBRO NO TIENE AUTOR ASIGNADO, QUE NO SALGA. USA INNER JOIN.

SELECT * FROM Libros;
SELECT * FROM Autores;
SELECT * FROM Generos;
SELECT * FROM LibroGenero;
SELECT * FROM LibroAutor;
SELECT * FROM Usuarios;
SELECT * FROM Prestamos;

SELECT L.titulo, A.nombre
FROM Libros AS L
INNER JOIN LibroAutor AS LA ON L.id_libro = LA.id_libro
INNER JOIN Autores AS A ON LA.id_autor = A.id_autor

-- QUEREMOS UN REPORTE DE TODOS LOS USUARIOS Y QUÉ LIBROS TIENEN PRESTADOS. QUEREMOS VER A PEDRO AUNQUE NO HAYA PEDIDO NADA.

SELECT U.nombre, L.titulo, P.fecha_prestamo
FROM Usuarios AS U
LEFT JOIN Prestamos AS P ON U.id_usuario = P.id_usuario
LEFT JOIN Libros AS L ON P.id_libro = L.id_libro

-- ¿QUÉ LIBROS ESTÁN FUERA DE LA BIBLIOTECA AHORA MISMO Y QUIÉN LOS TIENE?

SELECT L.titulo, U.nombre AS LoTiene
FROM Prestamos AS P
INNER JOIN Libros AS L ON P.id_libro = L.id_libro
INNER JOIN Usuarios AS U ON P.id_usuario = U.id_usuario
WHERE P.fecha_devolucion IS NULL;

-- QUEREMOS VER TODOS LOS GÉNEROS QUE EXISTEN EN EL SISTEMA Y QUÉ LIBROS TENEMOS EN ELLOS. SI HAY UN GÉNERO SIN LIBROS QUEREMOS VERLO TAMBIÉN.

SELECT G.nombre, L.titulo
FROM Libros AS L
INNER JOIN LibroGenero AS LG ON L.id_libro = LG.id_libro
RIGHT JOIN Generos AS G ON LG.id_genero = G.id_genero

DELETE FROM Libros WHERE id_libro = 2;

DELETE FROM LibroAutor WHERE id_libro = 2;
DELETE FROM LibroGenero WHERE id_libro = 2;
DELETE FROM Prestamos WHERE id_libro = 2;

SELECT * FROM Libros;