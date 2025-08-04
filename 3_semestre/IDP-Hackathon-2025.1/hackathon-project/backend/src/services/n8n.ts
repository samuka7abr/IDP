import axios from 'axios';

const N8N_BASE_URL = process.env.N8N_BASE_URL || 'http://localhost:5678';
const N8N_WEBHOOK_PATH = process.env.N8N_WEBHOOK_PATH || '/webhook/consulta';

export const n8nService = {
  async transcribeAudio(sessionId: string, fileName: string): Promise<string> {
    try {
      const response = await axios.post(
        `${N8N_BASE_URL}${N8N_WEBHOOK_PATH}`,
        {
          sessionId,
          fileName
        }
      );

      return response.data.transcription;
    } catch (error) {
      console.error('Erro ao enviar áudio para o N8N:', error);
      if (axios.isAxiosError(error)) {
        console.error('Detalhes da resposta:', error.response?.data);
      }
      throw new Error('Falha ao transcrever áudio');
    }
  }
}; 