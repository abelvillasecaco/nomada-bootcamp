// Filtrar usuarios desde un JSON

// Tienes un string en formato JSON que representa una lista de usuarios.
// Cada usuario tiene: nombre y estado (activo o inactivo).

// Escribe una función que haga lo siguiente:

// 1. Convertir el string JSON a un array de objetos
// 2. Filtrar solo los usuarios cuyo estado es "activo"
// 3. Devolver un array con solo los nombre de esos usuarios activos

const usuariosJSON = `
[
  { "nombre": "Hugo", "estado": "activo" },
  { "nombre": "Paco", "estado": "inactivo" },
  { "nombre": "Luis", "estado": "activo" }
]
`;

function obtenerUsuarios(jsonString){
  const usuarios = JSON.parse(jsonString);
  const activos = usuarios.filter(usuario => usuario.estado === "activo");

  return activos.map(usuario => usuario.nombre);
}

const resultado = obtenerUsuarios(usuariosJSON);
console.log(resultado);

