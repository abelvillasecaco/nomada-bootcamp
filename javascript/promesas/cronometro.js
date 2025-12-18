// Objetivo: Crear un cronómetro que muestre segundos y se pueda detener
const display = document.getElementById('display-cronometro');
const btnIniciar = document.getElementById('btn-iniciar-crono');
const btnDetener = document.getElementById('btn-detener-crono');

let segundos = 0;
let idIntervalo = null;

btnIniciar.addEventListener('click', function() {
  if(idIntervalo !== null){
    console.log('El cronómetro ya está iniciado.');
    return;
  }

  console.log('Cronómetro iniciado.');
  idIntervalo = setInterval(function(){
    segundos++;
    display.textContent = segundos;
  }, 1000);
});

btnDetener.addEventListener('click', function() {
  if(idIntervalo === null){
    console.log('El cronómetro no está iniciado.');
    return;
  }
  clearInterval(idIntervalo);
  console.log('Cronómetro detenido.');
  idIntervalo = null;
})
