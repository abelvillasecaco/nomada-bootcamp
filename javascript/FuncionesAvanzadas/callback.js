function saludar(nombre) {
  console.log("Hola, " + nombre);
}

function procesarUsuario(callback) {
  const nombre = 'Abel';
  callback(nombre); // ejecuta la función pasada
}

procesarUsuario(saludar);
