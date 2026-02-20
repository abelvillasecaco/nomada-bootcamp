-- II. En una empresa se necesita calcular el impuesto anual de un trabajador en función de su salario mensual. 
-- El impuesto es del 12% sobre el salario anual. Se desea:

-- 1. Crear una función escalar llamada CalcularImpuestoAnual que reciba el salario mensual y devuelva el impuesto anual.
-- 2. Crear una tabla de auditoría llamada AuditoriaImpuestos donde se almacene el nombre del empleado, su salario mensual,
-- el impuesto calculado y la fecha del cálculo.
-- 3. Crear un procedimiento almacenado llamado RegistrarImpuesto que reciba el nombre del empleado y su salario mensual, 
-- use la función para calcular el impuesto, y registre los datos en la tabla de auditoría.

CREATE TABLE AuditoriaImpuestos (
    id_auditoria INT IDENTITY(1, 1) PRIMARY KEY,
    nombre_empleado NVARCHAR(100) NOT NULL,
    salario_mensual DECIMAL(10, 2) NOT NULL,
    impuesto_calculado DECIMAL(10, 2) NOT NULL,
    fecha_calculo DATETIME DEFAULT GETDATE()
);
GO

SELECT * FROM AuditoriaImpuestos;

CREATE FUNCTION dbo.fn_CalcularImpuestoAnual (
    @SalarioMensual DECIMAL(10, 2)
)
RETURNS DECIMAL(10, 2)
AS
BEGIN
    DECLARE @SalarioAnual DECIMAL(10, 2);
    DECLARE @ImpuestoAnual DECIMAL(10, 2);

    SET @SalarioAnual = @SalarioMensual * 12;

    SET @ImpuestoAnual = @SalarioAnual * 0.12;

    RETURN @ImpuestoAnual;
END
GO

CREATE PROCEDURE dbo.RegistrarImpuesto (
    @NombreEmpleado NVARCHAR(100),
    @SalarioMensual DECIMAL(10, 2)
)
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @ImpuestoFinal DECIMAL(10, 2);

    SET @ImpuestoFinal = dbo.fn_CalcularImpuestoAnual(@SalarioMensual);

    INSERT INTO AuditoriaImpuestos(nombre_empleado, salario_mensual, impuesto_calculado)
    VALUES (@NombreEmpleado, @SalarioMensual, @ImpuestoFinal);

    PRINT 'Impuesto calculado y registrado exitosamente para: ' + @NombreEmpleado;
END
GO

EXEC dbo.RegistrarImpuesto
    @NombreEmpleado = 'Lucía Méndez',
    @SalarioMensual = 2500.00;

EXEC dbo.RegistrarImpuesto
    @NombreEmpleado = 'Roberto Sánchez',
    @SalarioMensual = 3200.50;

SELECT * FROM AuditoriaImpuestos;