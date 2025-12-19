import '@/style.css'

const app = document.querySelector('#app');

const nombreAPP = import.meta.env.VITE_NOMBRE_APP;
const claveSecretaAPP = import.meta.env.CLAVE_SECRETA; // Será undefined

app.innerHTML = `
  <h1>Bienvenido a ${nombreAPP}</h1>
  <p>Estamos corriendo en modo: <strong>${import.meta.env.MODE}</strong></p>
  <p>Intento de leer clave: ${claveSecretaAPP}</p>
`;
