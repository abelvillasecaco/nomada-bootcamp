import { Component, input } from '@angular/core';
import { Task } from '../../models/board';

@Component({
  selector: 'app-task-card',
  standalone: true,
  template: `
    <div class="card">
      {{ task().title }}
    </div>
  `,
  styles: [`
    .card {
      background: white;
      padding: 10px;
      border-radius: 8px;
      box-shadow: 0 1px 2px rgba(9,30,66,0.25);
      cursor: grab;
      font-size: 14px;
      color: #172b4d;
    }
    .card:hover {
      background: #f4f5f7;
    }
  `]
})
export class TaskCardComponent {
  task = input.required<Task>();
}
