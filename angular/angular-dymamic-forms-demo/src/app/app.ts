import { Component } from '@angular/core';
import { OrderForm } from './order-form/order-form';

@Component({
  selector: 'app-root',
  imports: [OrderForm],
  template: `
    <div style="padding: 16px;">
      <h1 style="text-align: center; margin-bottom: 16px;">Pedido - FormArray</h1>
      <app-order-form></app-order-form>
    </div>
  `,
})
export class App {}
