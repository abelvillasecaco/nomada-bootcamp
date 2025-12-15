import { Component, inject } from '@angular/core';
import { HasRoleDirective } from '../../directives/has-role';
import { AuthService } from '../../services/auth';

@Component({
  selector: 'app-admin-dashboard',
  standalone: true,
  imports: [HasRoleDirective],
  templateUrl: './admin-dashboard.html',
  styleUrls: ['./admin-dashboard.css'],
})
export class AdminDashboardComponent {
  public authService = inject(AuthService);
}
