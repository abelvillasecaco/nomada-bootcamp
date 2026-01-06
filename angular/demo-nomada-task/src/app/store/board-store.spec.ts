import { TestBed } from '@angular/core/testing';

import { BoardStore } from './board-store';

describe('BoardStore', () => {
  let service: BoardStore;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(BoardStore);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
