import { Injectable, signal } from '@angular/core';

@Injectable({
  providedIn: 'root',
})
export class AuthService {
  currentUser = signal<{ name: string } | null>(null);

  login() {
    this.currentUser.set({ name: 'John Doe' });
  }

  logut() {
    this.currentUser.set(null);
  }
}
