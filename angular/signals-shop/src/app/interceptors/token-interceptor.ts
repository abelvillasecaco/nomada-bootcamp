import { HttpInterceptorFn } from '@angular/common/http';

export const tokenInterceptor: HttpInterceptorFn = (req, next) => {
  const authReq = req.clone({
    setHeaders: {
      Authorization: `Bearer angular-20-super-secret-token}`
    }
  });

  console.log(`[Interceptor] Añadido token a petición: ${req.url}`);

  return next(authReq);
};
