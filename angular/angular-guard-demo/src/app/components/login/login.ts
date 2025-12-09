import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { Auth } from '../../services/auth';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-login',
  imports: [RouterModule],
  template: `
    <h2>Página de login</h2>
    <p>Simulación de autenticación</p>
    <button (click)="login()">Iniciar sesión</button>
    <br /> <br />
    <a [routerLink]="['/']">Volver al inicio</a>
  `,
  styleUrl: './login.css',
})
export class Login {

  constructor(private authService: Auth, private router: Router) {}

  login() {
    this.authService.login();
    alert('Sesión iniciada.');
    this.router.navigate(['/dashboard']);
  }
}
