-- La empresa desea automatizar el proceso de registro de empleados y cálculo de sus beneficios. Cada vez que se registra un nuevo empleado:

-- Se debe calcular su antigüedad (en años) y registrar su información.
-- Si tiene más de 3 años de antigüedad, se le asigna un bono del 10% de su salario anual.
-- Se deben guardar los datos del empleado en una tabla Empleados y el registro del bono (si corresponde) en una tabla Bonos.

USE nomadaDB;

CREATE TABLE Empleado_V2 (
    empleado_id INT IDENTITY(1, 1) PRIMARY KEY,
    nombre NVARCHAR(100) NOT NULL,
    salario_mensual DECIMAL(10, 2) NOT NULL,
    fecha_ingreso DATE NOT NULL
);
GO

INSERT INTO Empleado_V2 (nombre, salario_mensual, fecha_ingreso) VALUES
('Juan Pérez', 1200.00, '2018-03-15'),
('María López', 1450.50, '2019-07-22'),
('Carlos Ramírez', 980.75, '2020-01-10'),
('Ana Torres', 1570.00, '2017-11-05'),
('Luis Fernández', 1100.00, '2021-06-18'),
('Sofía Martínez', 1300.30, '2016-09-30'),
('Diego Herrera', 890.00, '2022-02-14'),
('Valeria Gómez', 1730.80, '2015-12-01'),
('Miguel Castro', 1050.60, '2019-04-25'),
('Elena Ruiz', 1600.00, '2014-08-12'),
('Ricardo Morales', 1100.00, '2023-01-09'),
('Patricia Navarro', 1400.00, '2018-05-27'),
('Fernando Rojas', 950.00, '2020-10-03'),
('Gabriela Mendoza', 1250.90, '2017-03-19'),
('Andrés Silva', 1080.00, '2022-07-11');

CREATE TABLE Bonos (
    bono_id INT IDENTITY(1, 1) PRIMARY KEY,
    empleado_id INT NOT NULL,
    monto_bono DECIMAL(10, 2) NOT NULL,
    fecha_asignacion DATE DEFAULT GETDATE(),
    CONSTRAINT FK_bonos_empleados FOREIGN KEY (empleado_id) REFERENCES Empleado_V2(empleado_id)
);
GO

SELECT * FROM Empleado_V2;
SELECT * FROM Bonos;

CREATE FUNCTION dbo.fn_CalcularAntiguedad (
    @FechaIngreso DATE 
)
RETURNS INT
AS
BEGIN
    DECLARE @Anios INT;

    SET @Anios = DATEDIFF(DAY, @FechaIngreso, GETDATE()) / 365;

    RETURN @Anios;
END;
GO

CREATE PROCEDURE dbo.sp_RegistrarEmpleado_Bono (
    @Nombre NVARCHAR(100),
    @SalarioMensual DECIMAL(10, 2),
    @FechaIngreso DATE = NULL,
    @NuevoEmpleadoID INT OUTPUT,
    @MensajeResultado NVARCHAR(200) OUTPUT
)
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @AntiguedadAnios INT;
    DECLARE @MontoBono DECIMAL(10, 2);
    DECLARE @SalarioAnual DECIMAL(10, 2);

    IF @FechaIngreso IS NULL
    BEGIN
        SET @FechaIngreso = GETDATE();
    END

    INSERT INTO Empleados_V2 (nombre, salario_mensual, fecha_ingreso)
    VALUES (@Nombre, @SalarioMensual, @FechaIngreso);

    SET @NuevoEmpleadoID = SCOPE_IDENTITY();

    SET @AntiguedadAnios = dbo.fn_CalcularAntiguedad(@FechaIngreso);

    IF @AntiguedadAnios > 3
    BEGIN
        SET @SalarioAnual = @SalarioMensual * 12;
        SET @MontoBono = @SalarioAnual * 0.10;

        INSERT INTO Bonos (empleado_id, monto_bono)
        VALUES (@NuevoEmpleadoID, @MontoBono);

        SET @MensajeResultado = 'Empleado registrado con éxito. Bono por antiguedad: $' + CAST(@MontoBono AS NVARCHAR(20));
    END
    ELSE
    BEGIN
        SET @MensajeResultado = 'Empleado registrado con éxito. No aplica bono (Antiguedad: )' + CAST(@AntiguedadAnios AS NVARCHAR(5)) + ' años.';
    END
END;
GO