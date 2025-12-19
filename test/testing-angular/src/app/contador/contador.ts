import { Component } from '@angular/core';

@Component({
  selector: 'app-contador',
  imports: [],
  templateUrl: './contador.html',
  styleUrl: './contador.css',
})
export class Contador {

  valor: number = 0;

  incrementar(): void {
    this.valor += 1;
  }

  decrementar(): void {
    this.valor -= 1;
  }
}
