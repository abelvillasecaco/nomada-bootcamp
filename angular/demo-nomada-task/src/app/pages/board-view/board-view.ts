import { Component, inject, OnInit, input } from '@angular/core';
import { ActivatedRoute, RouterLink } from '@angular/router';
import { BoardStore } from '../../store/board-store';
import { CdkDragDrop, DragDropModule } from '@angular/cdk/drag-drop';
import { TaskCardComponent } from '../../components/task-card/task-card';

@Component({
  selector: 'app-board-view',
  standalone: true,
  imports: [DragDropModule, TaskCardComponent, RouterLink],
  templateUrl: './board-view.html',
  styleUrls: ['./board-view.css']
})
export class BoardView implements OnInit {
  private route = inject(ActivatedRoute);
  store = inject(BoardStore);

  ngOnInit() {
    // Obtenemos el ID de la URL
    const id = this.route.snapshot.paramMap.get('id');
    if (id) {
      this.store.selectBoard(id);
    }
  }

  drop(event: CdkDragDrop<any[]>) {
    this.store.moveTask(
      event.previousContainer.id,
      event.container.id,
      event.previousIndex,
      event.currentIndex
    );
  }

  addTask(columnId: string) {
    const title = prompt('Nueva tarea:');
    if (title) {
      this.store.addTask(columnId, title);
    }
  }
}
