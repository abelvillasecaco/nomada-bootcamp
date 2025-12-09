// capitalize => abel => Abel
// trucate => Hola mundo ¿cómo estas? => Hola mundo...
// isEmpty => null, undefined, '', 0 => true

export const capitalize = (text = '') => {
  if (typeof text !== 'string') return '';
  return text.charAt(0).toUpperCase() + text.slice(1);
};

export const trucate = (text = '', length = 10) => {
  if (typeof text !== 'string') return '';
  return text.length > length ? text.slice(0, length) + '...' : text;
};

export const isEmpty = (value) => {
  if (value == null) return true;
  if (typeof value === 'string' || Array.isArray(value)) return value.length === 0;
  if (typeof value === 'object') return Object.keys(value).length === 0;
  return false;
};
