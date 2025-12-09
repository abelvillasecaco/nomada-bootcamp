import { ComponentFixture, TestBed } from '@angular/core/testing';

import { OrderForm } from './order-form';

describe('OrderForm', () => {
  let component: OrderForm;
  let fixture: ComponentFixture<OrderForm>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [OrderForm]
    })
    .compileComponents();

    fixture = TestBed.createComponent(OrderForm);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
