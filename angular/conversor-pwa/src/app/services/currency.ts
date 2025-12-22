import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root',
})
export class Currency {
  private rates = {
    PEN: 3.75,
    EUR: 0.92
  };

  convert(amount: number){
    return {
    PEN: amount * this.rates.PEN,
    EUR: amount * this.rates.EUR
    };
  }
}
