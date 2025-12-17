import { Injectable, inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root',
})
export class Product {
  private http = inject(HttpClient);
  private apiUrl = 'https://api.fake-store.com/products';

  getProducts(): Observable<any> {
    return this.http.get<any[]>(this.apiUrl);
  }
}
