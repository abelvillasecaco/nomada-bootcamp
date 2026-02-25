const express = require('express');
const app = express();
app.use(express.json());

const PORT = 3000;

const usuarios = [
  { id: 1, nombre: "Abel", rol: "Admin" },
  { id: 2, nombre: "María", rol: "Estudiante" },
  { id: 3, nombre: "Juan", rol: "Estudiante" },
];

const libros = [
  { id: 1, titulo: "El Principito", genero: "Ficción" },
  { id: 2, titulo: "Clean Code", genero: "Tecnología" },
  { id: 3, titulo: "Harry Potter", genero: "Ficción" }
]

app.get('/', (req, res) => { // home
  res.send('API Semana 2 funcionando.');
});

// 1. ROUTE PARAMS (:id) => Busca un usuario en específico
app.get('/usuarios/:id', (req, res) => {

  const idBusqueda = parseInt(req.params.id);

  const usuarioEncontrado = usuarios.find(u => u.id === idBusqueda);

  if(!usuarioEncontrado){
    return res.status(404).json({ error: "Usuario no encontrado." });
  }

  res.json(usuarioEncontrado);
});

// 2. QUERY PARAMS (?rol=Admin) => Filtrar datos de una lista
app.get('/usuarios', (req, res) => {
  const rolBuscado = req.query.rol;

  if(rolBuscado){
    const resultados = usuarios.filter(u => u.rol === rolBuscado); // API REST
    return res.json(resultados);
  }

  res.json(usuarios);
});

app.post('/usuarios', (req, res) => {
  const nuevosDatos = req.body;

  if(!nuevosDatos.nombre || !nuevosDatos.rol){
    return res.status(400).json({
      error: "Datos incompletos. Se requiere nombre y rol."
    });
  }

  const nuevoUsuario = {
    id: usuarios.length + 1,
    nombre: nuevosDatos.nombre,
    rol: nuevosDatos.rol
  };

  usuarios.push(nuevoUsuario);

  res.status(201).json({
    mensaje: "Usuario creado con éxito.",
    usuario: nuevoUsuario
  });
});

app.get('/libros', (req, res) => {
  const generoFiltro = req.query.genero;
  if(generoFiltro){
    return res.json(libros.filter(l => l.genero === generoFiltro));
  }
  res.json(libros);
});

app.listen(PORT, () => {
  console.log(`Servidor escuchando en el puerto: ${PORT}`);
});
