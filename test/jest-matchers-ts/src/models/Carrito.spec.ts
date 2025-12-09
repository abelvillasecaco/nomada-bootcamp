import { Carrito } from "./Carrito";

// beforeEach()
describe('Clase carrito de compras', () => {
  let carrito: Carrito;

  beforeEach(() => {
    carrito = new Carrito();
  });

  it('debería inicializarse vacío', () => {
    expect(carrito.items).toHaveLength(0);
  });

  it('debería agregar un item correctamente (Comprobación de Objeto)', () => {
    const item = { nombre: 'Laptop', precio: 1000 };
    carrito.agregarItem(item);

    expect(carrito.items).toHaveLength(1);
    expect(carrito.items[0]).toEqual({ nombre: 'Laptop', precio: 1000 });
  });
});
