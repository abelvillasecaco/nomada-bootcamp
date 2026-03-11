const express = require('express');
const router = express.Router();

const taskController = require('../controllers/task.controller');

// GET /tasks (Obtener todas)
router.get('/', taskController.getAllTasks);

// POST /tasks (Crear una)
router.post('/', taskController.createTask);

module.exports = router;
