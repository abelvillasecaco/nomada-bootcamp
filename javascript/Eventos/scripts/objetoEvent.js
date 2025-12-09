const area = document.getElementById('areaSensible');
const pInfo = document.getElementById('infoEvento');
const input = document.getElementById('inputTeclado');
const botonInterno = document.getElementById('botonInterno');

function mostrarInfoEvento(e) {
  let info = `Tipo de Evento: ${e.type}<br>`;
  info += `Target: ${e.target.tagName} (id: ${e.target.id || 'ninguno'})<br>`;
  info += `CurrentTarget: ${e.currentTarget.tagName} (id: ${e.currentTarget.id || 'ninguno'})<br>`;

  if (e.type === 'click' || e.type === 'mousedown') {
    info += `Botón del mouse: ${e.button}<br>`;
  }

  if (e.type === 'mousemove' || e.type === 'click') {
    info += `Posición Client (X, Y): ${e.clientX}, ${e.clientY}<br>`;
  }

  if(e.type === 'keydown') {
    info += `Tecla: ${e.key} (Código: ${e.code})<br>`;
    info += `Ctrl: ${e.ctrlKey}, Shift: ${e.shiftKey}, Alt: ${e.altKey}, Meta: ${e.metaKey}<br>`;
  }

  pInfo.innerHTML = info;
}

area.addEventListener('click', mostrarInfoEvento);

area.addEventListener('mousemove', function(e) {
  pInfo.innerHTML = `Mouse en Área: X=<span class="math-inline">\{e\.clientX\}, Y\=</span>{e.clientY}`;
});

area.addEventListener('mouseout', function(e) {
  pInfo.innerHTML = `Mouse fue saliendo de Área`;
});

botonInterno.addEventListener('click', function(e) {
  console.log("Target del Evento: ", e.target);
  console.log("CurrentTarget: ", e.currentTarget);
})

input.addEventListener('keydown', mostrarInfoEvento);
