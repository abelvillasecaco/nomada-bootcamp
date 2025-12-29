import { Injectable, inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { toSignal } from '@angular/core/rxjs-interop';

export interface Link {
  title: string;
  url: string;
}

export interface Profile {
  name: string;
  role: string;
  bio: string;
  links: Link[];
}

@Injectable({
  providedIn: 'root',
})
export class ProfileService {
  private http = inject(HttpClient);
  private profile$ = this.http.get<Profile>('/data.json');

  profileSignal = toSignal(this.profile$);
}
