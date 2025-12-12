export function obtenerUsuario(id: number): Promise<{ id: number, nombre: string }> {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve({ id, nombre: "Abel Villaseca" });
    }, 1000);
  });
}
