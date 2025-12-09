import { Component, inject, OnInit } from '@angular/core';
import { TaskService } from '../../services/task';
import { Task } from '../../interfaces/task';

@Component({
  selector: 'app-task-list',
  imports: [],
  templateUrl: './task-list.html',
  styleUrl: './task-list.css',
})
export class TaskList implements OnInit {
  private taskService = inject(TaskService);

  tasks: Task[] = [];

  isLoading = true;

  ngOnInit() {
    this.loadTasks();
  }

  loadTasks() {
    this.isLoading = true;

    this.taskService.getTasks().subscribe({
      next: (data) => {
        this.tasks = data;
        this.isLoading = false;
      },
      error: (err) => {
        this.isLoading = false;
        alert('Hubo un error cargando las taras.');
      }
    });
  }

  crearTarea() {
    const nueva: Task = {
      userId: 1,
      title: 'Nueva tarea',
      completed: false
    };

    this.taskService.createTask(nueva).subscribe(taskCreada => {
      taskCreada.id = Math.floor(Math.random() * 1000) + 200;
      this.tasks.unshift(taskCreada);
    });
  }

  toggleTarea(task: Task) {
    const tareaEditada = { ...task, completed: !task.completed };
    this.taskService.updateTask(tareaEditada).subscribe(() => {
      task.completed = tareaEditada.completed;
    });
  }

  borrarTarea(id: number) {
    if (!confirm('¿Seguro que quieres borrar la tarea?')) return;

    this.taskService.deleteTask(id).subscribe(() => {
      this.tasks = this.tasks.filter(task => task.id !== id);
    });
  }
}
