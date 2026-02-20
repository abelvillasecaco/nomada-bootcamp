const express = require('express');

const app = express();

const PORT = 3000;

// .get()
// '/' (el home)
// (req, res)

app.get('/', (req, res) => {
  res.send('Hola mi servidor está corriendo.');
});

app.get('/info', (req, res) => {
  res.json({
    bootcamp: "Nómada Bootcamp",
    curso: "Backend con Node.js",
    profesor: "Abel Villaseca",
    estado: "Activo"
  });
});

app.get('/saludo/:nombre', (req, res) => {
  const nombreUsuario = req.params.nombre;

  res.json({
    mensaje: `Hola ${nombreUsuario}, bienvenido al backend.`,
    timestamp: new Date()
  });
});

app.get('/perfil', (req, res) => {
  res.json({
    nombre: "Abel",
    edad: 32,
    pais: "Perú",
    hobbies: ["Programar", "Escuchar música", "Leer"]
  });
});

app.get('/suma/:num1/:num2', (req, res) => {

  const n1 = req.params.num1;
  const n2 = req.params.num2;

  const suma = parseInt(n1) + parseInt(n2);

  res.json({
    operacion: "Suma",
    valor1: n1,
    valor2: n2,
    resultado: suma
  });
});

app.use((req, res) => {
  res.status(404).json({
    error: "Ruta no encontrada.",
    mensaje: "Parece que te perdiste en el servidor."
  });
});

app.listen(PORT, () => {
  console.log(`Servidor escuchando en el puerto: ${PORT}`);
});
