import { Injectable, inject, PLATFORM_ID } from '@angular/core';
import { isPlatformBrowser } from '@angular/common';
import { Board } from '../models/board';
import { of, Observable } from 'rxjs';

@Injectable({
  providedIn: 'root',
})
export class BoardRepositoryService {
  private STORAGE_KEY = 'nomada-task-db';

  private platformId = inject(PLATFORM_ID);

  getBoards(): Observable<Board[]> {
    if (isPlatformBrowser(this.platformId)) {
      const data = localStorage.getItem(this.STORAGE_KEY);
      const boards = data ? JSON.parse(data) : [];
      return of(boards);
    }
    return of([]);
  }

  getBoardById(id: string): Observable<Board | undefined> {
    if (isPlatformBrowser(this.platformId)) {
      const data = localStorage.getItem(this.STORAGE_KEY);
      const boards: Board[] = data ? JSON.parse(data) : [];
      return of(boards.find(b => b.id === id));
    }
    return of(undefined);
  }

  saveBoards(boards: Board[]): void {
    if (isPlatformBrowser(this.platformId)) {
      localStorage.setItem(this.STORAGE_KEY, JSON.stringify(boards));
    }
  }
}
