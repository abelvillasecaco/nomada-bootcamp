import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RegistroForm } from './registro-form';

describe('RegistroForm', () => {
  let component: RegistroForm;
  let fixture: ComponentFixture<RegistroForm>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [RegistroForm]
    })
    .compileComponents();

    fixture = TestBed.createComponent(RegistroForm);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
