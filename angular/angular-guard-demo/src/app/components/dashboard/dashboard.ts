import { Component } from '@angular/core';
import { RouterModule } from '@angular/router';
import { Auth } from '../../services/auth';

@Component({
  selector: 'app-dashboard',
  imports: [RouterModule],
  template: `
    <h2>Página del dashboard</h2>
    <p>Solo los usuarios autenticados pueden acceder a este panel.</p>
    <button (click)="logout()">Cerrar sesión</button>
    <br />
    <a routerLink="/">Volver al inicio</a>
  `,
  styleUrl: './dashboard.css',
})
export class Dashboard {
  constructor(private authService: Auth) {}

  logout() {
    this.authService.logout();
    alert('Sesión cerrada.');
  }
}
