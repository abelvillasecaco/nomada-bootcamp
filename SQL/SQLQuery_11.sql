USE nomadaDB;

-- Sistema de reservas de hoteles: Una cadena de hoteles desea registrar sus reservas y generar reportes sobre:

-- El ingreso total por habitación.
-- El promedio de estadía.
-- El número de reservas por mes.
-- Las habitaciones más reservadas.
-- Clientes frecuentes (con más de X reservas).
-- Rangos de fechas y uso de funciones.

-- Se necesita implementar un sistema en SQL que permita automatizar reportes y análisis.

-- Tablas: Clientes, Habitaciones, Reservas

CREATE TABLE Clientes (
    cliente_id INT IDENTITY(1, 1) PRIMARY KEY,
    nombre_completo NVARCHAR(100) NOT NULL,
    email NVARCHAR(100)
);
GO

CREATE TABLE Habitaciones (
    habitacion_id INT IDENTITY(1, 1) PRIMARY KEY,
    numero NVARCHAR(10) NOT NULL,
    tipo NVARCHAR(50) NOT NULL,
    precio_por_noche DECIMAL(10, 2) NOT NULL
);
GO

CREATE TABLE Reservas (
    reserva_id INT IDENTITY(1, 1) PRIMARY KEY,
    cliente_id INT NOT NULL,
    habitacion_id INT NOT NULL,
    fecha_check_in DATE NOT NULL,
    fecha_check_out DATE NOT NULL,
    CONSTRAINT FK_Reservas_Clientes FOREIGN KEY (cliente_id) REFERENCES Clientes(cliente_id),
    CONSTRAINT FK_Reservas_Habitaciones FOREIGN KEY (habitacion_id) REFERENCES Habitaciones(habitacion_id)
);
GO

SELECT * FROM Clientes;
SELECT * FROM Habitaciones;
SELECT * FROM Reservas;