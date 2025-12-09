function contador() {
  let contador = 0;
  return function() {
    contador++;
    console.log('Cuenta actual: ', contador);
  }
}

const contar = contador();
contar();
contar();
contar();
