import { Component } from '@angular/core';
import { ProductsPage } from './pages/products-page/products-page';

@Component({
  selector: 'app-root',
  imports: [ProductsPage],
  template: `<app-products-page></app-products-page>`,
})
export class App {}
