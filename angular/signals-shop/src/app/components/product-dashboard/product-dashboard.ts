import { Component, inject } from '@angular/core';
import { CurrencyPipe, SlicePipe } from '@angular/common';
import { ProductService } from '../../services/product';
import { AuthService } from '../../services/auth';

@Component({
  selector: 'app-product-dashboard',
  imports: [CurrencyPipe, SlicePipe],
  templateUrl: './product-dashboard.html',
  styleUrl: './product-dashboard.css',
})
export class ProductDashboard {
  public productService = inject(ProductService);
  public authService = inject(AuthService);
}
