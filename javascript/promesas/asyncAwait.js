// Reutiliza la función simularPeticionesDatos (que devuelve una promesa)

function simularPeticionDatos(peticionExitosa){
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if(peticionExitosa){
        resolve({ id: 1, nombre: 'Producto de Ejemplo', stock: 100 });
      }else{
        reject(new Error('Fallo en la red.'));
      }
    }, 1500);
  });
}

// Crea una función async para manejar el caso de éxito
async function gestionarPeticionExitosa() {
  console.log('--- Async/Await: Caso de Éxito ---');
  try{
    console.log('Esperando datos...');
    const datos = await simularPeticionDatos(true);
    console.log('La promesa se resolvió. Continuamos.');
    console.log('Datos obtenidos: ', datos);

    console.log('Actualizando stock...');
    const stockActualizo = await Promise.resolve(datos.stock - 5);
    console.log('Stock final: ', stockActualizo);

  }catch(error){
    console.error('Este bloque no debería ejecutarse: ', error.message);
  }finally{
    console.log('Fin de la gestión de petición exitosa.');
  }
}

// Crea una función async para manejar el caso de fallo
async function gestionarPeticionFallida() {
  console.log('--- Async/Await: Caso de Fallo ---');
  try{
    console.log('Esperando datos (se espera un fallo)...');
    const datos = await simularPeticionDatos(false);
    console.log('Este log no se mostrará: ', datos);

  }catch(error){
    console.error('Este bloque no debería ejecutarse: ', error.message);
  }finally{
    console.log('Fin de la gestión de petición fallida.');
  }
}

// Llama a las funciones async
gestionarPeticionExitosa();
setTimeout(gestionarPeticionFallida, 4000);
