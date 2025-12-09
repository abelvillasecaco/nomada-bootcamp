import { Component } from '@angular/core';
import { bootstrapApplication } from '@angular/platform-browser';
import { ProductDashboard } from './product-dashboard/product-dashboard';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [ProductDashboard],
  template: `
    <main>
      <h1>Product Dashboard</h1>
      <app-product-dashboard></app-product-dashboard>
    </main>
  `,
  styles: `
    main {
      padding: 1rem;
      font-family: system-ui, sans-serif;
    }
    h1 {
      margin-bottom: 0.5rem;
    }
  `,
})
export class App {}
