import { User } from '../types/database';

export const mockUsers: User[] = [
  {
    id: 1,
    name: "Dra. Ana Silva",
    email: "ana.silva@exemplo.com",
    password: "senha123", // Em produção, isso seria um hash
    role: "psychologist",
    created_at: new Date(),
    updated_at: new Date()
  },
  {
    id: 2,
    name: "Dr. Carlos Santos",
    email: "carlos.santos@exemplo.com",
    password: "senha123",
    role: "psychologist",
    created_at: new Date(),
    updated_at: new Date()
  }
]; 