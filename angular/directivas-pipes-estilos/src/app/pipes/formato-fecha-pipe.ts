import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'formatoFecha',
  standalone: true
})

export class FormatoFechaPipe implements PipeTransform {

  transform(value: Date | string | null | undefined): string {

    if (!value) return '';

    const date = (value instanceof Date) ? value : new Date(value);

    const meses = [
      'Enero',
      'Febrero',
      'Marzo',
      'Abril',
      'Mayo',
      'Junio',
      'Julio',
      'Agosto',
      'Septiembre',
      'Octubre',
      'Noviembre',
      'Diciembre'
    ];

    const mes = meses[date.getMonth()];
    const anio = date.getFullYear();

    return `Lanzado en ${mes} de ${anio}`;
  }
}
