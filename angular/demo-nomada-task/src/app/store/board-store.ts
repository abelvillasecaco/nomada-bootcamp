import { Injectable, inject, signal } from '@angular/core';
import { Board, Column } from '../models/board';
import { BoardRepositoryService } from '../services/board-repository';
import { moveItemInArray, transferArrayItem } from '@angular/cdk/drag-drop';

@Injectable({
  providedIn: 'root',
})
export class BoardStore {

  private repo = inject(BoardRepositoryService);

  boards = signal<Board[]>([]);

  currentBoard = signal<Board | null>(null);

  constructor() {
    this.loadBoards();
  }

  private loadBoards() {
    this.repo.getBoards().subscribe(data => this.boards.set(data));
  }

  createBoard(title: string) {
    const newBoard: Board = {
      id: crypto.randomUUID(),
      title,
      createdAt: new Date(),
      columns: [
        { id: 'todo', title: 'Por Hacer', tasks: [] },
        { id: 'doing', title: 'En Proceso', tasks: [] },
        { id: 'done', title: 'Hecho', tasks: [] },
      ]
    };

    this.boards.update(current => [...current, newBoard]);
    this.saveState();
  }

  selectBoard(id: string) {
    const found = this.boards().find(b => b.id === id) || null;
    this.currentBoard.set(found);
  }

  addTask(columnId: string, title: string) {
    const board = this.currentBoard();
    if (!board) return;

    const column = board.columns.find(c => c.id === columnId);
    if(column){
      column.tasks.push({ id: crypto.randomUUID(), title });
      this.currentBoard.update(b => ({ ...b! }));
      this.saveState();
    }
  }

  moveTask(prevColId: string, currColId: string, prevIndex: number, currIndex: number) {
     const board = JSON.parse(JSON.stringify(this.currentBoard()));
     if(!board) return;

     const prevCol = board.columns.find((c : Column) => c.id === prevColId);
     const currCol = board.columns.find((c : Column) => c.id === currColId);

     if(prevColId === currColId) {
       moveItemInArray(currCol.tasks, prevIndex, currIndex);
     }else {
       transferArrayItem(prevCol.tasks, currCol.tasks, prevIndex, currIndex);
     }

     this.currentBoard.set(board);
     this.boards.update(all => all.map(b => b.id === board.id ? board : b));
     this.saveState();
  }

  private saveState() {
    this.repo.saveBoards(this.boards());
  }
}
