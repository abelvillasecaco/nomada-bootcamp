import { Component, signal, inject } from '@angular/core';
import { ProfileService } from './services/profile';

@Component({
  selector: 'app-root',
  imports: [],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {
  public profileService = inject(ProfileService);
}
