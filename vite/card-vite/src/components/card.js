import styles from './card.module.scss';

export function createCard(){
  const el = document.createElement('div');
  el.className = styles.card; // card_abc123

  const header = document.createElement('div');
  header.className = 'header';
  header.textContent = 'Tarjeta';
}
