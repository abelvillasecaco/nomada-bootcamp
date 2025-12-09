// 1. Definimos la función procesarArreglo

function procesarArreglo(arreglo, callback) {
  console.log('Empezando a procesar el arreglo...');
  for (const elemento of arreglo) {
    callback(elemento);
  }
}

// 2. Definimos un callback para duplicar los números

function duplicarNumero(numero) {
  console.log(numero * 2);
}

// 3. Defimos un callback para poner texto en mayúsculas

function convertirAMayusculas(texto) {
  console.log(texto.toUpperCase());
}

// 4. Uso de los callbacks

const misNumeros = [1, 2, 3, 4];
const misNombres = ['hugo', 'paco', 'luis'];

procesarArreglo(misNumeros, duplicarNumero);
procesarArreglo(misNombres, convertirAMayusculas);

procesarArreglo(misNumeros, (num) => {
  console.log(`La raíz cuadrada de ${num} es ${Math.sqrt(num).toFixed(2)}`);
})
