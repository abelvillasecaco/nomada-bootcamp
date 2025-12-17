import { Component, input, output } from '@angular/core';

@Component({
  selector: 'app-data-table',
  imports: [],
  templateUrl: './data-table.html',
  styleUrl: './data-table.css',
})
export class DataTable {
  data = input.required<string[]>();
  rowClick = output<string>();
}
