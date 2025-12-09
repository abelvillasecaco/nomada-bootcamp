import { Component, signal } from '@angular/core';
import { TitleCasePipe } from '@angular/common';
import { BudgetForm } from './components/budget-form/budget-form';

@Component({
  selector: 'app-root',
  imports: [BudgetForm, TitleCasePipe],
  templateUrl: './app.html',
  styleUrl: './app.css',
})
export class App {
  protected readonly title = signal('Gastos');
}
