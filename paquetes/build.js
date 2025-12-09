import fs from 'fs';

const srcCode = fs.readFileSync('./src/index.js', 'utf-8');

if (!fs.existsSync('./dist')) fs.mkdirSync('./dist');

// Versión ESM
fs.writeFileSync('./dist/index.js', srcCode);

// Versión CommonJS
const cjsCode = srcCode.replace(/export const/g, 'exports.').replace(/ =/g, ' =');
fs.writeFileSync('./dist/index.cjs.js', cjsCode);

console.log('Build completado: dist/index.js y dist/index.cjs.js');
