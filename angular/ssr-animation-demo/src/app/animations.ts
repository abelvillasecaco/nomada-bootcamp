import { trigger, style, transition, animate, query, stagger, keyframes } from '@angular/animations';
import { of } from 'rxjs';

export const listAnimations = trigger('listAnimation', [
  transition('* => *', [
    query(':enter', [
      style({ opacity: 0, transform: 'translateY(20px)' }),
      stagger('100ms', [
        animate('500ms cubic-bezier(0.35, 0, 0.25, 1)', style({ opacity: 1, transform: 'none' }))
      ])
    ], { optional: true })
  ])
]);

export const hoverAnimation = trigger('hoverAnimation', [
  transition(':enter', []),
  transition('* => hover', [
    animate('200ms', keyframes([
      style({ transform: 'scale(1)', offset: 0 }), // 0% of animation has transform applied
      style({ transform: 'scale(1.05)', offset: 0.5 }), // 50% of animation has transform applied
      style({ transform: 'scale(1.02)', offset: 1 }) // 100% of animation has transform applied
    ]))
  ]),

  transition('hover => *', [
    animate('200ms', style({ transform: 'scale(1)' }))
  ])
]);
