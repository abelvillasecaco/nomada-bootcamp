USE nomadaAgregacion;
GO -- es un separador de lotes

-- CREACIÓN DE TABLA

CREATE TABLE Ventas (
    id_venta INT IDENTITY(1, 1) PRIMARY KEY,
    nombre_producto VARCHAR(50),
    vendedor VARCHAR(50),
    precio_unitario DECIMAL(10, 2),
    fecha_venta DATE
);

-- POBLACIÓN DE TABLA

INSERT INTO Ventas (nombre_producto, vendedor, precio_unitario, fecha_venta)
VALUES
    ('Laptop', 'Ana', 1200.00, '2023-10-01'),
    ('Mouse', 'Carlos', 25.50, '2023-10-01'),
    ('Teclado', 'Ana', 45.00, '2023-10-02'),
    ('Laptop', 'Beatriz', 1200.00, '2023-10-03'),
    ('Monitor', 'Carlos', 300.00, '2023-10-03'),
    ('Mouse', 'Ana', 25.50, '2023-10-04'),
    ('Auriculares', 'Beatriz', 50.00, '2023-10-05');

GO

-- VERIFICACIÓN DE DATOS

SELECT * FROM Ventas;
GO

-- FUNCIONES DE AGREGACIÓN

-- A. ¿Cuántas transacciones de venta individuales hay registradas en la tabla Ventas?

SELECT COUNT(*) AS TotalTransacciones
FROM Ventas;

-- B. ¿Cuántos tipos diferentes de productos hemos vendido?

SELECT COUNT(DISTINCT nombre_producto) AS TiposDeProductosVendidos
FROM Ventas;

-- C. ¿Cuál es la cantidad total de unidades de productos vendidas en todas las transacciones?

IF OBJECT_ID('dbo.Ventas', 'U') IS NOT NULL
DROP TABLE dbo.Ventas; -- DataBase Owner
GO

CREATE TABLE Ventas (
    id_venta INT IDENTITY(1, 1) PRIMARY KEY,
    nombre_producto VARCHAR(50),
    categoria VARCHAR(50),
    vendedor VARCHAR(50),
    cantidad INT,
    precio_unitario DECIMAL(10, 2),
    fecha_venta DATE
);

INSERT INTO Ventas (nombre_producto, categoria, vendedor, cantidad, precio_unitario, fecha_venta)
VALUES
    ('Laptop', 'Electrónica', 'Ana', 1,  1200.00, '2023-10-01'),
    ('Mouse', 'Electrónica', 'Carlos', 10, 25.50, '2023-10-01'),
    ('Laptop', 'Electrónica', 'Beatriz', 1, 1200.00, '2023-10-03'),

    ('Camiseta', 'Ropa', 'Ana', 5,  15.00, '2023-10-02'),
    ('Pantalón', 'Ropa', 'Carlos', 2, 40.00, '2023-10-02'),
    ('Camiseta', 'Ropa', 'Beatriz', 3, 15.00, '2023-10-04'),
    
    ('Novela A', 'Libros', 'Ana', 10,  20.00, '2023-10-05'),
    ('Cómic Marvel', 'Libros', 'Carlos', 5, 12.00, '2023-10-05');

GO

UPDATE Ventas
SET precio_unitario = 25.50
WHERE id_venta = 6

SELECT SUM(cantidad) AS TotalUnidadesVendidas
FROM Ventas;

-- D. ¿Cuál es el ingreso total generado por todas las ventas? (Ingreso por venta = CantidadVendida * PrecioUnitario)

SELECT SUM(cantidad * precio_unitario) AS IngresoTotal
FROM Ventas;

-- E. ¿Cuál es el precio unitario promedio de todos los productos en las ventas registradas? (AVG())
-- AVG() = SUM(columna) / COUNT(columna)

SELECT ROUND(AVG(precio_unitario), 2) AS PrecioPromedio
FROM Ventas;

-- F. ¿Cuál es el valor promedio de venta por transacción?

SELECT AVG(cantidad * precio_unitario) AS VentaPromedioPorTransaccion
FROM Ventas;

-- G. ¿Cuál fue la mayor cantidad de unidades vendidas en una sola transacción?

SELECT MAX(cantidad) AS MayorCantidadVendida
FROM Ventas;

-- H. ¿Cuándo fue la última venta registrada?

SELECT MAX(fecha_venta) AS UltimaVentaRegistrada
FROM Ventas;

-- I. Indica cuál fue la mayor cantidad de unidades vendidas y todos sus detalles

SELECT * FROM Ventas
WHERE cantidad = (SELECT MAX(cantidad) FROM Ventas)

-- J. ¿Cuál es el precio unitario más bajo registrado en alguna venta?

SELECT MIN(precio_unitario) AS PrecioMasBajo
FROM Ventas;

-- K. ¿Cuándo fue la primera venta registrada en este lote?

SELECT MIN(fecha_venta) AS PrimeraVentaHistorica
FROM Ventas;

-- AGRUPACIÓN CON GROUP BY

-- A. Queremos saber cuántas unidades de productos se han vendido en total para cada Categoria (Electrónica, Libros, Ropa, etc.).

SELECT categoria, SUM(cantidad) AS TotalUnidadesVendidas
FROM Ventas
GROUP BY categoria;

-- B. Para cada Producto, queremos saber cuántas transacciones de venta hubo y cuál fue el precio unitario promedio de ese 
-- producto a lo largo de esas ventas.

SELECT nombre_producto, COUNT(*) AS NumeroDeTransacciones, AVG(precio_unitario) AS PrecioPromedio
FROM Ventas
GROUP BY nombre_producto

-- Queremos listar solo aquellas categorías que han tenido un total de ventas (transacciones) superior a 3.

SELECT categoria, COUNT(*) AS TotalTransacciones
FROM Ventas
GROUP BY categoria
HAVING COUNT(*) >= 3;

-- Queremos identificar los productos cuyo ingreso total por todas sus ventas es mayor a $500.

SELECT * FROM Ventas;

SELECT nombre_producto, SUM(cantidad * precio_unitario) AS IngresoTotal
FROM Ventas
GROUP BY nombre_producto
HAVING SUM(cantidad * precio_unitario) > 500

INSERT INTO Ventas (nombre_producto, categoria, vendedor, cantidad, precio_unitario, fecha_venta)
VALUES
    ('Silla Gamer', 'Muebles', 'Ana', 8, 500.00, '2023-03-10'),
    ('Escritorio', 'Muebles', 'Carlos', 4, 400.00, '2023-03-15'),
    ('Manguera', 'Jardín', 'Beatriz', 5, 20.00, '2023-03-05');
GO

-- Listar las categorías y la suma de unidades vendidas, pero solo para las ventas que ocurrieron en marzo de 2023, 
-- y solo incluir categorías donde el total de unidades vendidas en ese mes fue mayor a 10.

-- WHERE => DONDE
-- HAVING => TENIENDO

SELECT categoria, SUM(cantidad) AS TotalUnidadesMarzo
FROM Ventas
WHERE fecha_venta >= '2023-03-01' AND fecha_venta <= '2023-03-31'
GROUP BY categoria
HAVING SUM(cantidad) > 10;

-- Listar los productos y sus precios unitarios para aquellas ventas cuyo PrecioUnitario es mayor que el promedio de PrecioUnitario de todas las ventas.

SELECT nombre_producto, precio_unitario, categoria
FROM Ventas
WHERE precio_unitario > (SELECT AVG(precio_unitario) FROM Ventas);

-- Mostrar todas las ventas que corresponden a productos de la categoría 'Libros'. (Aunque simple con WHERE Categoria = 'Libros', 
-- demuestra el uso de IN con subconsulta).

SELECT * FROM Ventas
WHERE nombre_producto IN (
    SELECT DISTINCT nombre_producto
    FROM Ventas
    WHERE categoria = 'Libros'
);

-- Queremos ver los detalles de cada venta individualmente, pero también incluir una columna adicional que muestre 
-- el precio unitario promedio de todas las ventas como referencia.

SELECT nombre_producto, precio_unitario, 
       (SELECT AVG(precio_unitario) FROM Ventas) AS PrecioPromedioGlobal,
       precio_unitario - (SELECT AVG(precio_unitario) FROM Ventas) AS Diferencia
FROM Ventas;


-- Queremos obtener el precio unitario promedio, pero considerando únicamente las ventas que ocurrieron después del 12 de marzo de 2023.

SELECT AVG(precio_unitario) AS PromedioDespuesMarzo
FROM Ventas
WHERE fecha_venta > '2023-03-12';

SELECT * 
FROM Ventas
WHERE precio_unitario > (
    SELECT AVG(precio_unitario)
    FROM Ventas
    WHERE fecha_venta > '2023-03-12'
) AND fecha_venta > '2023-03-12';