import { ComponentFixture, TestBed } from '@angular/core/testing';

import { BoardView } from './board-view';

describe('BoardView', () => {
  let component: BoardView;
  let fixture: ComponentFixture<BoardView>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [BoardView]
    })
    .compileComponents();

    fixture = TestBed.createComponent(BoardView);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
