import { Session } from '../types/database';

export const mockSessions: Session[] = [
  {
    id: 1,
    patient_id: 1,
    date: new Date('2024-03-20'),
    status: 'completed',
    transcription: "Sessão de terapia com foco em ansiedade...",
    analysis: {
      SPEC: {
        S: "Apresentação em público",
        P: "Vou fazer tudo errado",
        E: "Ansiedade extrema",
        C: "Evitar apresentações"
      },
      distortions: [
        {
          type: "catastrofização",
          text: "Vou fazer tudo errado"
        }
      ]
    },
    created_at: new Date(),
    updated_at: new Date()
  },
  {
    id: 2,
    patient_id: 1,
    date: new Date('2024-03-27'),
    status: 'pending',
    created_at: new Date(),
    updated_at: new Date()
  },
  {
    id: 3,
    patient_id: 2,
    date: new Date('2024-03-21'),
    status: 'completed',
    transcription: "Sessão sobre relacionamentos...",
    analysis: {
      SPEC: {
        S: "Conflito com colega de trabalho",
        P: "Ninguém me entende",
        E: "Frustração",
        C: "Isolamento social"
      },
      distortions: [
        {
          type: "generalização excessiva",
          text: "Ninguém me entende"
        }
      ]
    },
    created_at: new Date(),
    updated_at: new Date()
  }
]; 