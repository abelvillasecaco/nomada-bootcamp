import { TestBed } from '@angular/core/testing';
import { Product } from './product';
import { provideHttpClient } from '@angular/common/http';
import { HttpTestingController, provideHttpClientTesting } from '@angular/common/http/testing';

describe('ProductService (HTTP Test)', () => {
  let service: Product;
  let httpMock: HttpTestingController;

  beforeEach(() => {
    TestBed.configureTestingModule({
      providers: [
        Product,
        provideHttpClient(),
        provideHttpClientTesting()
      ],
    });
    service = TestBed.inject(Product);
    httpMock = TestBed.inject(HttpTestingController);
  });

  afterEach(() => {
    httpMock.verify();
  });

  it('debería hacer una petición GET y devolver los productos simulados', () => {
    const dummyProducts = [
      { id: 1, name: 'Laptop Gamer' },
      { id: 2, name: 'Mouse' },
    ];

    service.getProducts().subscribe(products => {
      expect(products.length).toBe(2);
      expect(products).toEqual(dummyProducts);
    });

    const req = httpMock.expectOne('https://api.fake-store.com/products');

    expect(req.request.method).toBe('GET');

    req.flush(dummyProducts);
  });
});
