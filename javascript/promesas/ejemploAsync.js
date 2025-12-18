async function obtenerNumero() { // async = asíncrono
  return 10;
}

// const obtenerNumero = async() => {

// }

obtenerNumero().then(n => console.log(n));

async function obtenerUsuarios() {
  const response = await fetch('/api/usuarios'); // await => espera
  const data = await response.json();
  return data;
}

function obtenerUsuarios(){
  return fetch('/api/usuarios')
    .then(res => res.json());
}

// Manejo de errores
async function login() {
  try{
    const res = await fetch('api/login');
    if(!res.ok){
      throw new Error('Credenciales inválidas');
    }
    const data = await res.json();
    return data;
  }catch(error){
    console.error(error.message);
  }
}

// Ejecución Secuencial
const a = await fetch(url1)
const b = await fetch(url2)

// Ejecución Paralela
const [c, d] = await Promise.all([
  fetch(url1),
  fetch(url2)
])
