import { Directive, Input, TemplateRef, ViewContainerRef, inject, effect } from '@angular/core';
import { AuthService } from '../services/auth';

@Directive({
  selector: '[appHasRole]',
  standalone: true
})
export class HasRoleDirective {

  private templateRef = inject(TemplateRef<any>);
  private viewContainer = inject(ViewContainerRef);
  private authService = inject(AuthService);

  @Input('appHasRole') requiredRole: string = '';

  constructor() {

    effect(() => {

      const user = this.authService.currentUser();

      this.viewContainer.clear();

      if (user && user.role === this.requiredRole) {

        this.viewContainer.createEmbeddedView(this.templateRef);

      } else {

      }
    });
  }
}
