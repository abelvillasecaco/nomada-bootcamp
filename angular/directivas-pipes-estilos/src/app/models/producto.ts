export interface Producto {
  id: number;
  nombre: string;
  precio: number;
  enOferta: boolean;
  fechaLanzamiento: Date;
  stock?: number;
}
