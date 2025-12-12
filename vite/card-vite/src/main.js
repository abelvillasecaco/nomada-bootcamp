import '../src/styles/global.scss';
import { createCard } from './components/card';

const app = document.getElementById('app');
app.innerHTML = '';

const card = createCard({
  title: 'Card Vite + SCSS',
  description: 'Creando un componente con Vite y SCSS. Prueba el botón para destacar.',
});

app.appendChild(card);

const card2 = createCard({
  title: 'Card Vite + SCSS + Tailwind',
  description: 'Creando un componente con Vite, SCSS y Tailwind. Prueba el botón para destacar.',
});

card2.style.marginTop = '16px';
app.appendChild(card2);

if (import.meta.hot) {
  import.meta.hot.accept((newModule) => {
    console.log('main.js actualizado por HMR');
  });
}
