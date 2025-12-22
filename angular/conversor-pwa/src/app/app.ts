import { Component, computed, signal } from '@angular/core';
import { CommonModule } from '@angular/common';
import { Currency } from './services/currency';

type CurrencyResult = {
  PEN: number;
  EUR: number;
}

@Component({
  selector: 'app-root',
  imports: [CommonModule],
  providers: [Currency],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {

  amount = signal(0);
  online = signal(navigator.onLine);
  result = signal<CurrencyResult | null>(null);

  currencyKey = computed<(keyof CurrencyResult)[]>(() =>
    this.result() ? (Object.keys(this.result()!) as (keyof CurrencyResult)[]) : []
  );

  constructor(private currency: Currency) {
    window.addEventListener('online', () => this.online.set(true));
    window.addEventListener('offline', () => this.online.set(false));
  }

  onAmountChange(event: Event) {
    const input = event.target as HTMLInputElement;
    this.amount.set(Number(input.value));
  }

  convert() {
    this.result.set(this.currency.convert(this.amount()));
  }
}
