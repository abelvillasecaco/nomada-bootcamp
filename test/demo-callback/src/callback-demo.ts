export function procesarDatos(datos: string[], guardarCallback: (res: string) => void) {
  const resultado = datos.join(' - ');
  guardarCallback(resultado);
}
