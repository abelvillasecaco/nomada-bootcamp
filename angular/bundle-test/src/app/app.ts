import { Component } from '@angular/core';
import moment from 'moment';
import 'moment/locale/es';

@Component({
  selector: 'app-root',
  template: `<h1>Análisis de Bundle: {{ fecha }}</h1>`,
})
export class App {
  fecha = moment().locale('es').format('MMMM Do YYYY, h:mm:ss a');
}
