import { ComponentFixture, TestBed } from '@angular/core/testing';
import { Component } from '@angular/core';
import { DataTable } from './data-table';
import { By } from '@angular/platform-browser';

@Component({
  template: `
    <app-data-table
      [data]="testData"
      (rowClick)="onRowClick($event)">
    </app-data-table>
  `,
  standalone: true,
  imports: [DataTable]
})

class TestComponent {
  testData: string[] = [];
  selectedItem: string = '';

  onRowClick(item: string) {
   this.selectedItem = item;
  }
}

describe('DataTable (Integración)', () => {

  let fixture: ComponentFixture<TestComponent>;
  let hostComponent: TestComponent;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [TestComponent, DataTable]
    })
    .compileComponents();

    fixture = TestBed.createComponent(TestComponent);
    hostComponent = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('debería mostrar mensaje "Sin datos" cuando el array está vacío', () => {
    const msg = fixture.nativeElement.querySelector('.empty-msg');
    expect(msg).toBeTruthy();
    expect(msg.textContent).toBe('Sin datos');
  });

  it('debería renderizar tantas filas como datos recibe', () => {
    hostComponent.testData = ['Angular', 'React', 'Svelte'];
    fixture.detectChanges();
    const rows = fixture.nativeElement.querySelectorAll('.data-row');
    expect(rows.length).toBe(3);
  });

  it('debería emitir el evento al hacer click en una fila', () => {
    hostComponent.testData = ['Angular', 'React'];
    fixture.detectChanges();
    const firstRow = fixture.debugElement.query(By.css('.data-row'));
    firstRow.triggerEventHandler('click', null);
    expect(hostComponent.selectedItem).toBe('Angular');
  });
});
