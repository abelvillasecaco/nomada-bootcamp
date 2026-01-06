import { Routes } from '@angular/router';
import { Dashboard } from './pages/dashboard/dashboard';
import { BoardView } from './pages/board-view/board-view';

export const routes: Routes = [
  { path: '', component: Dashboard },
  { path: 'board/:id', component: BoardView },
  { path: '**', redirectTo: '' },
];
