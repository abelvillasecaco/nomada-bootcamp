const saludo = document.getElementById('saludo');

saludo.addEventListener('mouseover', function() {
  saludo.textContent = 'Hola, soy un evento!';
});

saludo.addEventListener('mouseout', function() {
  saludo.textContent = 'Pasa el mouse sobre mi...';
});
