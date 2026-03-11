const tasks = require('../db/db');

const getAllTasks = (req, res) => {
  res.json({
    message: 'Tareas obtenidas con éxito.',
    data: tasks
  });
};

const createTask = (req, res) => {

  const { title } = req.body;

  if(!title){
    return res.status(400).json({ error: 'El título es obligatorio.' });
  }

  const newTask = {
    id: tasks.length + 1,
    title: title,
    done: false
  };

  tasks.push(newTask);

  res.status(201).json({
    message: 'Tarea creada con éxito.',
    data: newTask
  });
};

module.exports = {
  getAllTasks,
  createTask
};
