import { Component } from '@angular/core';
import { RegistroForm } from './registro-form/registro-form';

@Component({
  selector: 'app-root',
  imports: [RegistroForm],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {
}
