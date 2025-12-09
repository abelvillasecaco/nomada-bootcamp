export function toUpper(text: string): string {
  return text.toUpperCase();
}

export function reverse(text: string): string {
  return text.split('').reverse().join('');
}

export function isPalindrome(text: string): boolean {
  const cleaned = text.toLowerCase().replace(/\s+/g, '');
  const reversed = cleaned.split('').reverse().join('');
  return cleaned === reversed;
}

// const texto = "Hola  mundo cómo estás";
// const sinEspacios = texto.replace(/\s+/g, '');
// console.log(sinEspacios);

// Holamundocómoestás

// holamundocómoestás

// anitalatina
// anitalatina
//
