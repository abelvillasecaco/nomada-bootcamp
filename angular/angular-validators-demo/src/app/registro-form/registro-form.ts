import { Component } from '@angular/core';
import { ReactiveFormsModule, FormBuilder, Validators } from '@angular/forms';

@Component({
  selector: 'app-registro-form',
  imports: [ReactiveFormsModule],
  templateUrl: './registro-form.html',
  styleUrl: './registro-form.css',
})
export class RegistroForm {
  form;

  constructor(private fb: FormBuilder) {
    this.form = this.fb.group({
      username: [
        '',
        {
          validators: [
            Validators.required,
            Validators.minLength(3),
            Validators.pattern('^[a-zA-Z0-9]+$'),
          ],
          updateOn: 'blur',
        },
      ],
      email: [
        '',
        {
          validators: [Validators.required, Validators.email],
          updateOn: 'blur',
        },
      ],
      password: [
        '',
        {
          validators: [Validators.required, Validators.minLength(8)],
          updateOn: 'blur',
        },
      ],
      age: [
        '',
        {
          validators: [Validators.min(14), Validators.max(120)],
          updateOn: 'blur',
        },
      ],
      acceptTerms: [
        false,
        {
          validators: [Validators.requiredTrue],
          updateOn: 'blur',
        },
      ],
    });
  }

  onSubmit() {
    if (this.form.valid) {
      console.log('Formulario válido');
    } else {
      console.log('Formulario inválido');
      this.form.markAllAsTouched();
    }
  }

  get usernameControl() {
    return this.form.get('username');
  }
}
