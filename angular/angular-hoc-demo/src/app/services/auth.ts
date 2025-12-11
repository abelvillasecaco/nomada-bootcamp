import { Injectable, signal } from "@angular/core";

export interface User {
  name: string;
  role: 'admin' | 'user' | 'guest';
}

@Injectable({
  providedIn: 'root'
})

export class AuthService {
  currentUser = signal<User | null>(null);

  loginAsAdmin() {
    console.log('Login como admin');
    this.currentUser.set({ name: 'Abel', role: 'admin' });
  }

  loginAsUser() {
    console.log('Login como usuario');
    this.currentUser.set({ name: 'Juan', role: 'user' });
  }

  logout() {
    console.log('Logout');
    this.currentUser.set(null);
  }
}
