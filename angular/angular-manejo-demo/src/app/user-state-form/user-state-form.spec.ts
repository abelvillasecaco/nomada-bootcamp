import { ComponentFixture, TestBed } from '@angular/core/testing';

import { UserStateForm } from './user-state-form';

describe('UserStateForm', () => {
  let component: UserStateForm;
  let fixture: ComponentFixture<UserStateForm>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [UserStateForm]
    })
    .compileComponents();

    fixture = TestBed.createComponent(UserStateForm);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
