import { procesarDatos } from "./callback-demo";

describe('Mocks y Spies', () => {

  it('Debería llamar al callback con los datos procesados', () => {
    const miMock = jest.fn(); // función falsa => mock

    const datos = ['Angular', 'React', 'Vue'];

    procesarDatos(datos, miMock);

    expect(miMock).toHaveBeenCalled();
    expect(miMock).toHaveBeenCalledTimes(1);
    expect(miMock).toHaveBeenCalledWith('Angular - React - Vue');
  });
});
