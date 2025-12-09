import { Component } from '@angular/core';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-home',
  imports: [RouterModule],
  template: `
    <h2>Página de inicio</h2>
    <p>Bienvenido al sitio. Puedes acceder al panel o iniciar sesión.</p>
    <a routerLink="/dashboard">Ir al dashboard</a> |
    <a routerLink="/login">Ir al login</a>
  `,
  styleUrl: './home.css',
})
export class Home {

}
