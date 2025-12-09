interface Producto {
  nombre: string;
  precio: number;
}

export class Carrito {
  items: Producto[] = [];

  agregarItem(item: Producto) {
    this.items.push(item);
  }

  removerItem(nombre: string) {
    this.items = this.items.filter(i => i.nombre !== nombre);
  }

  calcularTotal(): number {
    return this.items.reduce((total, item) => total + item.precio, 0);
  }

  aplicarDescuento(porcentaje: number): number {
    if (porcentaje > 100 || porcentaje < 0) {
      throw new Error('El descuento debe estar entre 0 y 100');
    }
    const total = this.calcularTotal();
    return total - (total * (porcentaje / 100));
  }
}
