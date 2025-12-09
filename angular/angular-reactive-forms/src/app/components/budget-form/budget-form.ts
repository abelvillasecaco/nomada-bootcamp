import { Component, signal } from '@angular/core';
import { ReactiveFormsModule, FormBuilder, FormGroup, FormArray, FormControl, Validators, Form } from '@angular/forms';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-budget-form',
  imports: [ReactiveFormsModule, CommonModule],
  templateUrl: './budget-form.html',
  styleUrl: './budget-form.css',
})
export class BudgetForm {
  budgetForm: FormGroup;

  constructor(private fb: FormBuilder) {
    this.budgetForm = this.fb.group({
      owner: new FormControl('', [Validators.required, Validators.minLength(3)]),
      month: new FormControl('', Validators.required),
      expenses: this.fb.array([this.createExpensesGroup()]),
    });
  }

  private createExpensesGroup(): FormGroup {
    return this.fb.group({
      id: this.generateId(),
      description: new FormControl('', Validators.required),
      amount: new FormControl(0, [Validators.required, Validators.min(0.01)]),
      category: new FormControl(''),
    });
  }

  private generateId(): FormControl {
    const uid = `${Date.now().toString(36)}-${Math.floor(Math.random() * 1e6).toString(36)}`;
    return new FormControl(uid);
  }

  get expenses(): FormArray {
    return this.budgetForm.get('expenses') as FormArray;
  }

  addExpense() {
    this.expenses.push(this.createExpensesGroup());
  }

  removeExpense(index: number) {
    if (this.expenses.length > 1) {
      this.expenses.removeAt(index);
    } else {
      const g = this.expenses.at(0) as FormGroup;
      g.patchValue({ decription: '', amount: 0, category: '' });
    }
  }

  getTotal(): number {
    return this.expenses.controls.reduce((sum, grp) => {
      const val = grp.get('amount')?.value;
      return sum + (Number(val) || 0);
    }, 0);
  }

  submitted = signal(false);

  onSubmit() {
    if (this.budgetForm.invalid) {
      this.budgetForm.markAllAsTouched();
      this.submitted.set(false); // Asegura que el JSON no se muestre si hay errores
      return;
    }

    this.submitted.set(true);

    console.log('Budget saved: ', this.budgetForm.value);
    // this.budgetForm.reset();
    // this.expenses.clear();
    // this.expenses.push(this.createExpensesGroup());
  }

  control(path: string) {
    return this.budgetForm.get(path) as FormControl;
  }

  expenseControl(i: number, name: string) {
    return (this.expenses.at(i) as FormGroup).get(name) as FormControl;
  }
}
