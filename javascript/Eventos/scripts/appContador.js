const boton = document.getElementById('btnInteractivo');
const pContador = document.getElementById('contadorClicks');

let contador = 0;

function manejarClickBoton() {
  contador++;
  pContador.textContent = `Clicks: ${contador}`;

  if (contador >= 3) {
    boton.removeEventListener('click', manejarClickBoton);
    boton.textContent = 'Listener eliminado';
    boton.disabled = true;
  }
}

boton.addEventListener('click', manejarClickBoton);
