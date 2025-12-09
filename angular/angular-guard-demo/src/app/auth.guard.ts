import { Inject, inject } from '@angular/core';
import { CanActivateFn, Router, UrlTree } from '@angular/router';
import { Auth } from './services/auth';
import { Observable } from 'rxjs';

export const authGuard: CanActivateFn = () => {
  const authService = inject(Auth);
  const router = inject(Router);

  if (authService.isAuthenticated()) {
    return true;
  } else {
    alert('No está autenticado. Redirigiendo al login...');
    router.navigate(['/login']);
    return false;
  }
};

// @Injectable({ provideIn: 'root' })
// export class AuthGuard implements CanActivate {
//   constructor(private auth: AuthService, private router: Router){ }

//   canActivate(route: ActivatedRouteSnapshot): Observable<boolean | UrlTree> {
//     return this.auth.isLoggedIn().pipe(
//       map(logged => logged ? true : this.router.parseUrl('/login'))
//     );
//   }
// }
