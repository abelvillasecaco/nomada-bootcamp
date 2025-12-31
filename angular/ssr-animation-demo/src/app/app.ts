import { Component, signal } from '@angular/core';
import { CommonModule } from '@angular/common';
import { listAnimations, hoverAnimation } from './animations';

@Component({
  selector: 'app-root',
  imports: [CommonModule],
  templateUrl: './app.html',
  styleUrl: './app.css',
  animations: [listAnimations, hoverAnimation],
})
export class App {
  products = signal([
    { id: 1, name: 'Laptop Gamer', price: 4000, state: 'normal' },
    { id: 2, name: 'Smartphone', price: 5000, state: 'normal' },
    { id: 3, name: 'Tablet', price: 2000, state: 'normal' },
    { id: 4, name: 'Headphones', price: 500, state: 'normal' },
    { id: 5, name: 'Smart Watch', price: 1200, state: 'normal' },
  ]);

  setHoverState(index: number, state: string) {
    this.products.update((items) => {
      const newItems = [...items];
      newItems[index].state = state;
      return newItems;
    });
  }
}
