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