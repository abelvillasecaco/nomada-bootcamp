import { TestBed } from '@angular/core/testing';

import { BoardRepository } from './board-repository';

describe('BoardRepository', () => {
  let service: BoardRepository;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(BoardRepository);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
