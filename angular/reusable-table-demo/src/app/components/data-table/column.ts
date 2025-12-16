import { Directive, input } from '@angular/core';

@Directive({
  selector: 'app-column' // <app-column></app-column>
})
export class ColumnDirective {

  header = input.required<string>();

  // {id: 1, name: "Laptop"}
  key = input.required<string>();

}
