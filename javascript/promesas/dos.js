function crearPromesaDescarga(nombreRecurso, tiempoMs){
  return new Promise((resolve) => {
    console.log(`Iniciando descarga de ${nombreRecurso}...`);
    setTimeout(() => {
      resolve(`${nombreRecurso} descargado.`);
    }, tiempoMs);
  });
}

const promesaImagen = crearPromesaDescarga("imagen.jpg", 1500);
const promesaVideo = crearPromesaDescarga("video.mp4", 3000);
const promesaAudio = crearPromesaDescarga("audio.mp3", 500);

console.log('-- Usando Promise.all() --');
const todasLasPromesas = [promesaImagen, promesaVideo, promesaAudio];
Promise.all(todasLasPromesas)
  .then(resultados => {
    console.log('Todas las descargas se han terminado.');
    console.log(resultados);
  })
  .catch(error => {
    console.error('Una de las descargas falló: ', error);
  });

console.log('-- Usando Promise.race() --');
Promise.race(todasLasPromesas)
  .then(primerResultado => {
    console.log('La primera descarga ha terminado.');
    console.log(primerResultado);
  })
  .catch(error => {
    console.error('La primera descarga que terminó falló: ', error);
  })
