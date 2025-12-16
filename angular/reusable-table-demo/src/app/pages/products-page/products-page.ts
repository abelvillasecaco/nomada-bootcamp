import { Component, signal } from '@angular/core';
import { DataTable } from '../../components/data-table/data-table';
import { ColumnDirective } from '../../components/data-table/column';

@Component({
  selector: 'app-products-page',
  imports: [DataTable, ColumnDirective],
  templateUrl: './products-page.html',
  styleUrl: './products-page.css',
})
export class ProductsPage {

  products = signal([
    { id: 1, name: 'MacBook Pro', price: 3000, stock: 5 },
    { id: 2, name: 'iPhone', price: 999, stock: 12 },
    { id: 3, name: 'Monitor', price: 350, stock: 0 },
  ]);

  onProductSelect(product: any) {
    alert(`Has seleccionado: ${product.name} que cuesta $${product.price}`);
  }

  addProduct() {
    this.products.update(current => [
      ...current,
      { id: Date.now(), name: 'Nuevo Producto', price: 100, stock: 10 }
    ]);
  }
}
