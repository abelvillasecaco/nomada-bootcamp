import './style.css'

const API_URL = import.meta.env.VITE_API_URL;

const app = document.querySelector('#app');
app.innerHTML = `<p>Cargando personajes...</p>`;

async function fetchPersonajes() {
  try{
    if(!API_URL) throw new Error('No se ha definido la URL de la API');

    const response = await fetch(API_URL);
    const data = await response.json();
    render(data.results);
  }catch(error){
    console.error(error);
    app.innerHTML = `<p style="color:red">Error: ${error.message}</p>`;
  }
}

function render(personajes){

  app.innerHTML = '';

  const grid = document.createElement('div');
  grid.className = 'grid';

  personajes.forEach(personaje => {
    const card = document.createElement('div');
    card.className = 'card';
    card.innerHTML = `
      <img src="${personaje.image}" alt="${personaje.name}">
      <h3>${personaje.name}</h3>
      <p>${personaje.status} - ${personaje.species}</p>
    `;
    grid.appendChild(card);
  });
  app.appendChild(grid);
}

fetchPersonajes();
