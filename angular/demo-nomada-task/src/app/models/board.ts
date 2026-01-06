export interface Task {
  id: string;
  title: string;
  description?: string;
}

export interface Column {
  id: string;
  title: string;
  tasks: Task[];
}

export interface Board {
  id: string;
  title: string;
  createdAt: Date;
  columns: Column[];
}
