// Usar localStorage para que la página "recuerde" el nombre del usuario entre visitas.
const saludoH1 = document.getElementById("saludo");
const inputNombre = document.getElementById("input-nombre");
const btnGuardar = document.getElementById("btn-guardar-nombre");
const btnBorrar = document.getElementById("btn-borrar-nombre");

const CLAVE_STORAGE_NOMBRE = "nombreDeUsuario";

function actualizarSaludo(nombre){
  saludoH1.textContent = nombre ? `Hola, ${nombre}` : "Hola visitante";
}

function cargarNombreGuardado(){
  const nombreGuardado = localStorage.getItem(CLAVE_STORAGE_NOMBRE);
  if(nombreGuardado){
    console.log(`Nombre encontrado en localStorage: ${nombreGuardado}`);
    actualizarSaludo(nombreGuardado);
  }else{
    alert("No se encontró un nombre en localStorage.");
  }
}

btnGuardar.addEventListener("click", function(){
  const nombreIngresado = inputNombre.value.trim();
  if(nombreIngresado){
    localStorage.setItem(CLAVE_STORAGE_NOMBRE, nombreIngresado);
    console.log(`Nombre "${nombreIngresado}" guardado en el localStorage`);
    actualizarSaludo(nombreIngresado);
    inputNombre.value = "";
  }else{
    alert("Por favor, ingresa un nombre.");
  }
});

btnBorrar.addEventListener("click", function(){
  localStorage.removeItem(CLAVE_STORAGE_NOMBRE);
  console.log("Nombre borrado del localStorage.");
  actualizarSaludo(null);
});

cargarNombreGuardado();
