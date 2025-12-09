import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { Producto } from '../models/producto';
import { FormatoFechaPipe } from '../pipes/formato-fecha-pipe';
import { StockStatusDirective } from "../directives/stock-status";

@Component({
  selector: 'app-product-dashboard',
  templateUrl: './product-dashboard.html',
  styleUrl: './product-dashboard.css',
  standalone: true,
  imports: [CommonModule, FormatoFechaPipe, StockStatusDirective]
})
export class ProductDashboard {
  productos: Producto[] = [
    {
      id: 1,
      nombre: 'Juego de mesa',
      precio: 100,
      enOferta: true,
      fechaLanzamiento: new Date(2025, 9, 1),
      stock: 5
    },
    {
      id: 2,
      nombre: 'Zapatillas para correr',
      precio: 150.99,
      enOferta: false,
      fechaLanzamiento: new Date(2025, 6, 15),
      stock: 1
    },
    {
      id: 3,
      nombre: 'Mochila',
      precio: 119,
      enOferta: true,
      fechaLanzamiento: new Date(2025, 11, 20),
      stock: 5
    }
  ];

  trackByProductoId(index: number, producto: Producto) {
    return producto.id;
  }

  formatoSimplePrecio(n: number) {
    return n.toFixed(2);
  }
}
