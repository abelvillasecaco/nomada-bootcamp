// Simular la petición de datos:
// 1. Crea una función simularPeticionDatos
// 2. Consume la promesa en el caso de éxito
// 3. Consume la promesa en el caso de fallo

function simularPeticionDatos(peticionExitosa){
  console.log('Iniciando petición de datos...');

  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if(peticionExitosa){
        const datos = { id: 1, nombre: 'Producto de Ejemplo', stock: 100 };
        console.log('Petición exitosa, resolviendo promesa.');
        resolve(datos);
      }else{
        const error = new Error('Error de red: No se pudo conectar al servidor');
        console.log('Petición fallida, rechazando promesa.');
        reject(error);
      }
    }, 2000);
  });
}

console.log('-- Caso de Éxito --');
simularPeticionDatos(true)
  .then(datosRecibidos => {
    console.log('Callback de .then() ejecutado.');
    console.log('Datos recibidos: ', datosRecibidos);
    datosRecibidos.stock -= 1;
    return datosRecibidos;
  })
  .then(datosModificados => {
    console.log('Segundo .then() ejecutado.');
    console.log('Stock actualizado: ', datosModificados.stock);
  })
  .catch(error => {
    console.error('Callback de .catch() ejecutado', error.message);
  })
  .finally(() => {
    console.log('Callback de .finally() ejecutado para el caso de éxito.');
  });


setTimeout(() => {
  console.log('-- Caso de Fallo --');
  simularPeticionDatos(false)
    .then(datosRecibidos => {
      console.log('Datos recibidos: ', datosRecibidos);
    })
    .catch(error => {
      console.log('Callback de .catch() ejecutado.');
      console.error('Error capturado: ', error.message);
    })
    .finally(() => {
    console.log('Callback de .finally() ejecutado para el caso de fallo.');
  });
}, 5000);
