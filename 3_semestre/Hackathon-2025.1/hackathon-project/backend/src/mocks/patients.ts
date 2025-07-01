import { Patient } from '../types/database';

export const mockPatients: Patient[] = [
  {
    id: 1,
    name: "Maria Oliveira",
    email: "maria@exemplo.com",
    psychologist_id: 1,
    created_at: new Date(),
    updated_at: new Date()
  },
  {
    id: 2,
    name: "João Pereira",
    email: "joao@exemplo.com",
    psychologist_id: 1,
    created_at: new Date(),
    updated_at: new Date()
  },
  {
    id: 3,
    name: "Ana Santos",
    email: "ana@exemplo.com",
    psychologist_id: 2,
    created_at: new Date(),
    updated_at: new Date()
  }
]; 