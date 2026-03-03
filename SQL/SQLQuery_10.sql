DECLARE @ID_Generado INT;
DECLARE @Mensaje_Out NVARCHAR(200);

-- PRINT '--- PRUEBA 1: EMPLEADO ANTIGUO ---'
-- EXEC dbo.sp_RegistrarEmpleado_Bono
--     @Nombre = 'Sofía Vergara',
--     @SalarioMensual = 3000.00,
--     @FechaIngreso = '2019-05-10',
--     @NuevoEmpleadoID = @ID_Generado OUTPUT,
--     @MensajeResultado = @Mensaje_Out OUTPUT;

-- SELECT @ID_Generado AS ID_Insertado, @Mensaje_Out AS ResultadoDeOperacion;

PRINT '--- PRUEBA 2: EMPLEADO NUEVO (HOY) ---'
EXEC dbo.sp_RegistrarEmpleado_Bono
    @Nombre = 'Mateo Silva',
    @SalarioMensual = 2000.00,
    @NuevoEmpleadoID = @ID_Generado OUTPUT,
    @MensajeResultado = @Mensaje_Out OUTPUT;

SELECT @ID_Generado AS ID_Insertado, @Mensaje_Out AS ResultadoDeOperacion;
GO

SELECT * FROM Empleado_V2;
SELECT * FROM Bonos;
GO