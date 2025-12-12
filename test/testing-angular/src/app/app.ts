import { Component, signal } from '@angular/core';
import { Contador } from './contador/contador';

@Component({
  selector: 'app-root',
  imports: [Contador],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {
  protected readonly title = signal('testing-angular');
}
