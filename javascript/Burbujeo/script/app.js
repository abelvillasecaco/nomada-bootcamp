const abuelo = document.getElementById('abuelo');
const padre = document.getElementById('padre');
const hijo = document.getElementById('hijo');

abuelo.addEventListener('click', function(e) {
  console.log('CAPTURA: Abuelo clickeado. Target: ', e.target.id, 'CurrentTarget: ', e.currentTarget.id);
}, true);

padre.addEventListener('click', function(e) {
  console.log('CAPTURA: Padre clickeado. Target: ', e.target.id, 'CurrentTarget: ', e.currentTarget.id);
}, true);

hijo.addEventListener('click', function(e) {
  console.log('CAPTURA (o Target): Hijo clickeado. Target: ', e.target.id, 'CurrentTarget: ', e.currentTarget.id);
}, true);

abuelo.addEventListener('click', function(e) {
  console.log('BURBUJEO: Abuelo clickeado. Target: ', e.target.id, 'CurrentTarget: ', e.currentTarget.id);
}, false);

padre.addEventListener('click', function(e) {
  console.log('BURBUJEO: Padre clickeado. Target: ', e.target.id, 'CurrentTarget: ', e.currentTarget.id);
}, false);

hijo.addEventListener('click', function(e) {
  console.log('BURBUJEO (o Target): Hijo clickeado. Target: ', e.target.id, 'CurrentTarget: ', e.currentTarget.id);
  e.stopPropagation();
}, false);
