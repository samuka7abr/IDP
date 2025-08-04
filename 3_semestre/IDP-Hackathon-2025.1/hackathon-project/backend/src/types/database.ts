export interface User {
  id: number;
  name: string;
  email: string;
  password: string;
  role: 'psychologist' | 'admin';
  created_at: Date;
  updated_at: Date;
}

export interface Patient {
  id: number;
  name: string;
  email: string;
  psychologist_id: number;
  created_at: Date;
  updated_at: Date;
}

export interface Session {
  id: number;
  patient_id: number;
  date: Date;
  status: 'pending' | 'completed';
  transcription?: string;
  audioUrl?: string;
  analysis?: {
    SPEC?: {
      S?: string;
      P?: string;
      E?: string;
      C?: string;
    };
    distortions?: Array<{
      type: string;
      text: string;
    }>;
  };
  created_at: Date;
  updated_at: Date;
} 