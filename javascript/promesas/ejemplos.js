// SINTAXIS DE UNA PROMESA

// const promesa = new Promise((resolve, reject) => {
//   // Operación asíncrona
// })

// Promesa normal

const pedirPizza = new Promise((resolve, reject) => {
  const hayPizza = true;

  if(hayPizza){
    resolve('Pizza entregada');
  }else{
    reject('No hay pizza');
  }
});

pedirPizza
  .then((mensaje) => {
    console.log(mensaje);
  })
  .catch((error) => {
    console.log(error);
  })
  .finally(() => {
    console.log('Pedido finalizado');
  });

  // Encadenamiento de Promesas

// 1. Comprar ingredientes
// 2. Cocinar
// 3. Servir

const cocinar = (paso) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(`Paso completado: ${paso}`);
    }, 2000);
  });
};

cocinar("Comprar ingredientes")
  .then((resultado) => {
    console.log(resultado);
    return cocinar("Cocinar");
  })
  .then((resultado) => {
    console.log(resultado);
    return cocinar("Servir");
  })
  .then((resultado) => {
    console.log(resultado);
  })
  .catch((error) => {
    console.log(error);
  })
