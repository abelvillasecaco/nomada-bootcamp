const express = require('express');
const app = express();
const PORT = 3000;

const taskRoutes = require('./routes/task.routes');

// Middleware para JSON (Siempre necesario)
app.use(express.json());

app.use('/tasks', taskRoutes);

app.listen(PORT, () => {
  console.log(`Servidor corriendo en http://localhost:${PORT}`);
});
