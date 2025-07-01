import { User, Patient, Session } from '../types/database';
import { mockUsers } from './users';
import { mockPatients } from './patients';
import { mockSessions } from './sessions';

// Serviço de usuários (psicólogos)
export const userService = {
  getUsers: async (): Promise<User[]> => {
    return mockUsers;
  },

  getUser: async (id: number): Promise<User | undefined> => {
    return mockUsers.find(u => u.id === id);
  },

  createUser: async (userData: Omit<User, 'id' | 'created_at' | 'updated_at'>): Promise<User> => {
    const newUser = {
      ...userData,
      id: mockUsers.length + 1,
      created_at: new Date(),
      updated_at: new Date()
    };
    mockUsers.push(newUser);
    return newUser;
  },

  updateUser: async (id: number, userData: Partial<User>): Promise<User> => {
    const index = mockUsers.findIndex(u => u.id === id);
    if (index === -1) {
      throw new Error('Usuário não encontrado');
    }
    mockUsers[index] = {
      ...mockUsers[index],
      ...userData,
      updated_at: new Date()
    };
    return mockUsers[index];
  },

  deleteUser: async (id: number): Promise<void> => {
    const index = mockUsers.findIndex(u => u.id === id);
    if (index === -1) {
      throw new Error('Usuário não encontrado');
    }
    mockUsers.splice(index, 1);
  }
};

// Serviço de pacientes
export const patientService = {
  getPatients: async (): Promise<Patient[]> => {
    return mockPatients;
  },

  getPatient: async (id: number): Promise<Patient | undefined> => {
    return mockPatients.find(p => p.id === id);
  },

  createPatient: async (patientData: Omit<Patient, 'id' | 'created_at' | 'updated_at'>): Promise<Patient> => {
    const newPatient = {
      ...patientData,
      id: mockPatients.length + 1,
      created_at: new Date(),
      updated_at: new Date()
    };
    mockPatients.push(newPatient);
    return newPatient;
  },

  updatePatient: async (id: number, patientData: Partial<Patient>): Promise<Patient> => {
    const index = mockPatients.findIndex(p => p.id === id);
    if (index === -1) {
      throw new Error('Paciente não encontrado');
    }
    mockPatients[index] = {
      ...mockPatients[index],
      ...patientData,
      updated_at: new Date()
    };
    return mockPatients[index];
  },

  deletePatient: async (id: number): Promise<void> => {
    const index = mockPatients.findIndex(p => p.id === id);
    if (index === -1) {
      throw new Error('Paciente não encontrado');
    }
    mockPatients.splice(index, 1);
  }
};

// Serviço de sessões
export const sessionService = {
  getSessions: async (): Promise<Session[]> => {
    return mockSessions;
  },

  getSession: async (id: number): Promise<Session | undefined> => {
    return mockSessions.find(s => s.id === id);
  },

  createSession: async (sessionData: Omit<Session, 'id' | 'created_at' | 'updated_at'>): Promise<Session> => {
    const newSession = {
      ...sessionData,
      id: mockSessions.length + 1,
      created_at: new Date(),
      updated_at: new Date()
    };
    mockSessions.push(newSession);
    return newSession;
  },

  updateSession: async (id: number, sessionData: Partial<Session>): Promise<Session> => {
    const index = mockSessions.findIndex(s => s.id === id);
    if (index === -1) {
      throw new Error('Sessão não encontrada');
    }
    mockSessions[index] = {
      ...mockSessions[index],
      ...sessionData,
      updated_at: new Date()
    };
    return mockSessions[index];
  },

  deleteSession: async (id: number): Promise<void> => {
    const index = mockSessions.findIndex(s => s.id === id);
    if (index === -1) {
      throw new Error('Sessão não encontrada');
    }
    mockSessions.splice(index, 1);
  }
}; 