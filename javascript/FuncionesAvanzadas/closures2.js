function crearContador() {
  let contadorPrivado = 0;

  return {
    incrementar: function() {
      contadorPrivado++;
      console.log('Contador incrementado.');
    },
    decrementar: function() {
      contadorPrivado--;
      console.log('Contador decrementado.');
    },
    obtenerValor: function() {
      return contadorPrivado;
    }
  };
}

const miContador1 = crearContador();

console.log("Valor inicial: ", miContador1.obtenerValor()); // 0
miContador1.incrementar();
miContador1.incrementar();
console.log("Valor después de incrementar: ", miContador1.obtenerValor()); // 2
miContador1.decrementar();
console.log("Valor después de decrementar: ", miContador1.obtenerValor()); // 1

console.log('Intentando acceder a contadorPrivado: ', miContador1.contadorPrivado);

const miContador2 = crearContador();
console.log('\nValor inicial del contador 2: ', miContador2.obtenerValor());

