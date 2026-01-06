import { Component, inject } from '@angular/core';
import { BoardStore } from '../../store/board-store';
import { RouterLink } from '@angular/router';
import { DatePipe } from '@angular/common';

@Component({
  selector: 'app-dashboard',
  imports: [RouterLink, DatePipe],
  templateUrl: './dashboard.html',
  styleUrl: './dashboard.css',
})
export class Dashboard {
  store = inject(BoardStore);

  create(input: HTMLInputElement) {
    if(!input.value) return;
    this.store.createBoard(input.value);
    input.value = '';
  }
}
