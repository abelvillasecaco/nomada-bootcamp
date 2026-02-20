-- I. Una empresa quiere llevar control de sus empleados y calcular:

-- 1. Cuántos días lleva un empleado trabajando (desde su fecha de ingreso).
-- 2. Cuál es su bono anual calculado como el 5% de su salario base por cada año trabajado completo.

-- Crea:

-- Una tabla Empleados con datos básicos.
-- Una función definida por el usuario que calcule el bono. (5% del salario base por año completo) => Función escalar
-- Un procedimiento almacenado que muestre el nombre del empleado, los días trabajados y su bono.
-- Usa funciones nativas de SQL Server (GETDATE( ), DATEDIFF( ), etc.).

CREATE TABLE Empleados (
    id_empleado INT IDENTITY(1, 1) PRIMARY KEY,
    nombre NVARCHAR(100) NOT NULL,
    salario_base DECIMAL(10, 2) NOT NULL,
    fecha_ingreso DATE NOT NULL
);

GO

INSERT INTO Empleados (nombre, salario_base, fecha_ingreso)
VALUES
    ('Ana García', 2000.00, '2015-03-15'),  
    ('Carlos López', 1500.00, '2022-11-01'),
    ('María Torres', 1800.00, GETDATE()),
    ('Juan Pérez', 2500.00, '2010-01-20');

SELECT * FROM Empleados;

CREATE FUNCTION dbo.fn_CalcularBonoAnual (
    @Salario DECIMAL(10, 2),
    @FechaIngreso DATE
)
RETURNS DECIMAL(10, 2)
AS
BEGIN
    DECLARE @AniosTrabajados INT;
    DECLARE @BonoCalculado DECIMAL(10, 2);

    SET @AniosTrabajados = DATEDIFF(DAY, @FechaIngreso, GETDATE()) / 365;

    SET @BonoCalculado = (@Salario * 0.05) * @AniosTrabajados;

    RETURN @BonoCalculado;
END;
GO

CREATE PROCEDURE dbo.sp_ReporteEmpleados
AS
BEGIN
    SET NOCOUNT ON;

    SELECT 
        nombre, 
        DATEDIFF(DAY, fecha_ingreso, GETDATE()) AS DiasTrabajados,
        dbo.fn_CalcularBonoAnual(salario_base, fecha_ingreso) AS BonoAnual
    FROM Empleados;
END
GO

SELECT * FROM Empleados;
EXEC dbo.sp_ReporteEmpleados;