import { obtenerUsuario } from "./async-demo";

describe('Pruebas asíncronas', () => {

  it('Debería obtener el usuario correctamente con async/await', async ()=> {
    const usuario = await obtenerUsuario(1);
    expect(usuario).toEqual({ id: 1, nombre: "Abel Villaseca" });
  });

  it('Debería resolverse con el usuario correcto', async ()=> {
    await expect(obtenerUsuario(1)).resolves.toEqual({ id: 1, nombre: "Abel Villaseca" });
  });

});
