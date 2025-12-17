import { ComponentFixture, TestBed } from '@angular/core/testing';
import { Register } from './register';
import { ReactiveFormsModule } from '@angular/forms';

describe('RegisterComponent (Forms)', () => {
  let component: Register;
  let fixture: ComponentFixture<Register>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [Register, ReactiveFormsModule]
    })
    .compileComponents();

    fixture = TestBed.createComponent(Register);
    component = fixture.componentInstance;
    fixture.detectChanges(); // Inicializa el ciclo de vida (ngOnInit)
  });

  it('debería invalidar el formulario si los campos están vacíos', () => {
    expect(component.registerForm.valid).toBeFalse();
  });

  it('debería marcar error en el email si el formato es incorrecto', () => {
    const emailControl = component.registerForm.get('email');
    emailControl?.setValue('no-es-un-email');
    expect(emailControl?.valid).toBeFalse();
    expect(emailControl?.hasError('email')).toBeTrue();
  });

  it('debería habilitar el botón cuando el formulario es válido', () => {
    const btn = fixture.nativeElement.querySelector('button');
    expect(btn.disabled).toBeTrue();

    component.registerForm.patchValue({
      email: 'email@example.com',
      password: '123456',
    });

    fixture.detectChanges();

    expect(btn.disabled).toBeFalse();
  });
});
