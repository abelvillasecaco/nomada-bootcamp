import { Directive, ElementRef, Input, OnChanges, Renderer2, SimpleChanges } from '@angular/core';

@Directive({
  selector: '[stockStatus]',
  standalone: true
})

export class StockStatusDirective implements OnChanges {

  @Input('stockStatus') stock: number | undefined;

  constructor(private el: ElementRef<HTMLElement>, private renderer: Renderer2) { }

  ngOnChanges(chages: SimpleChanges): void {
    const s = this.stock ?? 0;
    if (s < 5) {
      this.renderer.setStyle(this.el.nativeElement, 'color', 'red');
      this.renderer.setAttribute(this.el.nativeElement, 'title', `Bajo stock: ${s}`);
    }else {
      this.renderer.removeStyle(this.el.nativeElement, 'color');
      this.renderer.removeAttribute(this.el.nativeElement, 'title');
    }
  }
}
