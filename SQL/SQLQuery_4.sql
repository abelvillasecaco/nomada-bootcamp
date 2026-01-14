-- Table Usuarios {
--   id_usuario int [primary key, increment]
--   nombre nvarchar
--   email nvarchar
--   direccion nvarchar  
-- }

CREATE TABLE Usuarios (
    id_usuario INT PRIMARY KEY IDENTITY(1, 1),
    nombre NVARCHAR(100) NOT NULL,
    email NVARCHAR(100) NOT NULL UNIQUE,
    direccion NVARCHAR(200)
);

SELECT * FROM Usuarios;

-- Table Categorias {
--   id_categoria int [primary key, increment]
--   nombre nvarchas
-- }

CREATE TABLE Categorias (
    id_categoria INT PRIMARY KEY IDENTITY(1, 1),
    nombre NVARCHAR(50) NOT NULL
);

SELECT * FROM Categorias;

-- Table Productos {
--   id_producto int [primary key, increment]
--   nombre nvarchar
--   precio decimal(10, 2)
--   stock int
--   id_categoria int
-- }

CREATE TABLE Productos (
    id_producto INT PRIMARY KEY IDENTITY(1, 1),
    nombre NVARCHAR(100) NOT NULL,
    precio DECIMAL(10, 2) NOT NULL,
    stock INT DEFAULT 0,
    id_categoria INT,
    FOREIGN KEY (id_categoria) REFERENCES Categorias(id_categoria)
);

SELECT * FROM Productos;

-- Table Pedidos {
--   id_pedido int [primary key, increment]
--   id_usuario int
--   fecha datetime
--   estado varchar
-- }

CREATE TABLE Pedidos (
    id_pedido INT PRIMARY KEY IDENTITY(1, 1),
    id_usuario INT NOT NULL,
    fecha DATETIME DEFAULT GETDATE(),
    estado NVARCHAR(20) DEFAULT 'Pendiente',
    FOREIGN KEY (id_usuario) REFERENCES Usuarios(id_usuario)
);

SELECT * FROM Pedidos;

-- Table DetallePedido {
--   id_detallepedido int [primary key, increment]
--   id_pedido int
--   id_producto int
--   cantidad int
--   precio_unitario decimal(10,2)
-- }

CREATE TABLE DetallePedido (
    id_detallepedido INT PRIMARY KEY IDENTITY(1, 1),
    id_pedido INT NOT NULL,
    id_producto INT NOT NULL,
    cantidad INT NOT NULL,
    precio_unitario DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (id_pedido) REFERENCES Pedidos(id_pedido),
    FOREIGN KEY (id_producto) REFERENCES Productos(id_producto),
);

SELECT * FROM DetallePedido;

-- Ref: Productos.id_categoria > Categorias.id_categoria
-- Ref: Pedidos.id_usuario > Usuarios.id_usuario
-- Ref: DetallePedido.id_pedido > Pedidos.id_pedido
-- Ref: DetallePedido.id_producto > Productos.id_producto

CREATE DATABASE nomadaEcommerceDB;
USE nomadaEcommerceDB;