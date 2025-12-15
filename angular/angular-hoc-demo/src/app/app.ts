import { Component, signal } from '@angular/core';
import { AdminDashboardComponent } from './components/admin-dashboard/admin-dashboard';

@Component({
  selector: 'app-root',
  imports: [AdminDashboardComponent],
  template: `<app-admin-dashboard></app-admin-dashboard>`,
})
export class App {
  protected readonly title = signal('angular-hoc-demo');
}
