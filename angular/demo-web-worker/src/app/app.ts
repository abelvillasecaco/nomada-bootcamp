import { Component, signal } from '@angular/core';

@Component({
  selector: 'app-root',
  template: `
    <h1>Web Workers</h1>
    <button (click)="runHeavyTask()">Ejecutar tarea pesada</button>
  `,
})
export class App {
  runHeavyTask() {
    if (typeof Worker !== 'undefined') {
      // Create a new
      const worker = new Worker(new URL('./app.worker', import.meta.url));
      worker.onmessage = ({ data }) => {
        console.log(`Cálculo terminado: ${data}`);
        worker.terminate();
      };
      worker.postMessage(40);
    } else {
      console.warn('Web Workers no soportados.');
    }
  }
}


// performance.now()
