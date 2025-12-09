import { Component } from '@angular/core';
import { UserStateForm } from './user-state-form/user-state-form';

@Component({
  selector: 'app-root',
  imports: [UserStateForm],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {
}
