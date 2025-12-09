import { Component, OnInit, inject } from '@angular/core';
import { ReactiveFormsModule, FormBuilder, FormGroup, FormArray, Validators, AbstractControl, ValidationErrors } from '@angular/forms';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-order-form',
  imports: [ReactiveFormsModule, CommonModule],
  templateUrl: './order-form.html',
  styleUrl: './order-form.css',
})
export class OrderForm implements OnInit {
  private fb = inject(FormBuilder);

  form!: FormGroup;
  liveValue: any = {};
  liveStatus: string = 'PENDING';

  ngOnInit(): void {
    this.form = this.fb.group({
      customerName: ['', [Validators.required, Validators.minLength(3)]],
      orderLines: this.fb.array<FormGroup>([], { validators: [this.minOneLineValidator] }),
    });

    this.addLine();

    this.form.valueChanges.subscribe(v => this.liveValue = v);
    this.form.statusChanges.subscribe(s => this.liveStatus = s);
  }

  get orderLines(): FormArray {
      return this.form.get('orderLines') as FormArray;
  }

  private createLine(): FormGroup {
    return this.fb.group({
      product: ['', [Validators.required]],
      quantity: [1, [Validators.required, Validators.min(1)]],
    });
  }

  addLine(): void {
    this.orderLines.push(this.createLine());
    this.form.updateValueAndValidity();
  }

  removeLine(index: number): void {
    this.orderLines.removeAt(index);
    this.form.updateValueAndValidity();
  }

  minOneLineValidator(control: AbstractControl): ValidationErrors | null {
    const arr = control as FormArray;
    return arr && arr.length > 0 ? null : { minOne: true };
  }

  customerNameControl() { return this.form.get('customerName'); }
  lineControl(i: number) { return (this.orderLines.at(i) as FormGroup); }

  onSubmit(): void {
    if (this.form.invalid) {
      this.form.markAllAsTouched();
      return;
    }

    console.log('Pedido enviado: ', this.form.value);
    alert('Pedido enviado, revisa la consola');

    this.form.reset();
    this.orderLines.clear();
    this.addLine();

  }
}
