import { Component } from '@angular/core';
import { TaskList } from './components/task-list/task-list';

@Component({
  selector: 'app-root',
  imports: [TaskList],
  template: `<app-task-list></app-task-list>`,
  styleUrl: './app.css'
})
export class App {}
