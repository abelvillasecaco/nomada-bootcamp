import './style.css';
import { header } from './modules/header';
import { hero } from './modules/hero';
import { footer } from './modules/footer';

document.querySelector("#app").innerHTML = `
  ${header()}
  ${hero()}
  ${footer()}
`;
