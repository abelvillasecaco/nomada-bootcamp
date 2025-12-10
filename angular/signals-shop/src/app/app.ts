import { Component, signal } from '@angular/core';
import { ProductDashboard } from './components/product-dashboard/product-dashboard';

@Component({
  selector: 'app-root',
  imports: [ProductDashboard],
  template: `<app-product-dashboard></app-product-dashboard>`,
  styleUrl: './app.css',
})
export class App {
  protected readonly title = signal('signals-shop');
}
