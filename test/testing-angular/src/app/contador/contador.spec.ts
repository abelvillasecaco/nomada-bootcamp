import { ComponentFixture, TestBed } from '@angular/core/testing';
import { Contador } from './contador';

describe('Contador', () => {
  let component: Contador;
  let fixture: ComponentFixture<Contador>; // DOM + TS

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [Contador],
    }).compileComponents(); // Compila HTML + CSS

    fixture = TestBed.createComponent(Contador);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('debería crear el componente correctamente', () => {
    expect(component).toBeTruthy();
  });

  it('debería tener un valor inicial de 0', () => {
    const compiled = fixture.nativeElement as HTMLElement;
    const h1 = compiled.querySelector('.display-valor');
    expect(h1?.textContent).toContain('Valor actual: 0');
  });

  it('debería incrementar el valor cuando se haga click en el botón "+1"', () => {
    const compiled = fixture.nativeElement as HTMLElement;
    const buttonIncrementar = compiled.querySelector('.btn-incrementar') as HTMLButtonElement;
    buttonIncrementar.click();
    fixture.detectChanges();
    const h1 = compiled.querySelector('.display-valor');
    expect(h1?.textContent).toContain('Valor actual: 1');
  });
});
