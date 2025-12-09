import { Injectable, inject, signal, computed } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { toSignal } from '@angular/core/rxjs-interop';
import { Product } from '../interfaces/product';
import { catchError, of } from 'rxjs';

@Injectable({
  providedIn: 'root',
})
export class ProductService {

  private http = inject(HttpClient);
  private apiUrl = 'https://fakestoreapi.com/products';

  private products$ = this.http.get<Product[]>(this.apiUrl).pipe(
    catchError(err => {
      console.log(`[ProductService] Error al obtener productos: ${err}`);
      return of([]);
    })
  );

  products = toSignal(this.products$, { initialValue: [] });

  selectedCategory = signal<string>('all');

  filteredProducts = computed(() => {
    const category = this.selectedCategory();
    const allProducts = this.products();

    if (category === 'all') {
      return allProducts;
    }

    return allProducts.filter(p => p.category === category);
  });

  setCategory(category: string) {
    this.selectedCategory.set(category);
  }
}
