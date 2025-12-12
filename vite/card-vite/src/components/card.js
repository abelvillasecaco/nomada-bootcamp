import styles from './card.module.scss';

/**
 * createCard
 * @param {Object} opts - { title, description }
 * @returns {HTMLElement}
 */

export function createCard(opts = {}) {

  const { title = 'Título', description = 'Descripción de la tarjeta' } = opts;

  const el = document.createElement('div');
  el.className = styles.card; // card_abc123

  const header = document.createElement('div');
  header.className = 'header';
  header.textContent = title;

  const body = document.createElement('div');
  body.className = 'body';
  body.textContent = description;

  const actions = document.createElement('div');
  actions.className = 'actions';

  const btnHighlight = document.createElement('button');
  btnHighlight.textContent = 'Destacar';

  btnHighlight.addEventListener('click', () => {
    el.classList.toggle(styles.highlighted);
  });

  actions.appendChild(btnHighlight);

  el.appendChild(header);
  el.appendChild(body);
  el.appendChild(actions);

  return el;
}


