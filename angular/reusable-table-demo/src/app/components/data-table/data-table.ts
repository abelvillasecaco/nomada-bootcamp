import { Component, ChangeDetectionStrategy, input, output, contentChildren } from '@angular/core';
import { ColumnDirective } from './column';

@Component({
  selector: 'app-data-table',
  imports: [],
  templateUrl: './data-table.html',
  styleUrl: './data-table.css',
  changeDetection: ChangeDetectionStrategy.OnPush
})
export class DataTable {

  //INPUTS
  data = input.required<any[]>();

  //OUTPUTS
  rowClick = output<any>();

  columns = contentChildren(ColumnDirective);

  handleRowClick(item: any) {
    this.rowClick.emit(item);
  }
}
