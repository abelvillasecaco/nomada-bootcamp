import data from './data.json';
import avatar from './assets/avatar.jpg';
import './style.scss';

const app = document.querySelector('#app');

app.innerHTML = `
  <div class="profile-card">
    <img src="${avatar}" alt="Avatar">
    <h2>${data.name}</h2>
    <p>${data.description}</p>
  </div>
`;
