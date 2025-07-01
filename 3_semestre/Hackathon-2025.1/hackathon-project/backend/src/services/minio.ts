import * as Minio from 'minio';
import { Readable } from 'stream';

const minioClient = new Minio.Client({
  endPoint: process.env.MINIO_ENDPOINT || 'localhost',
  port: Number(process.env.MINIO_PORT) || 9000,
  useSSL: process.env.MINIO_USE_SSL === 'true',
  accessKey: process.env.MINIO_ACCESS_KEY || 'minioadmin',
  secretKey: process.env.MINIO_SECRET_KEY || 'minioadmin123'
});

const BUCKET_NAME = 'audio-sessions';

export const minioService = {
  async initialize() {
    try {
      const exists = await minioClient.bucketExists(BUCKET_NAME);
      if (!exists) {
        await minioClient.makeBucket(BUCKET_NAME);
        console.log(`Bucket ${BUCKET_NAME} criado com sucesso`);
      }
    } catch (error) {
      console.error('Erro ao inicializar MinIO:', error);
      throw error;
    }
  },

  async uploadAudio(sessionId: string, fileStream: Readable, fileName: string): Promise<string> {
    try {
      const objectName = `${sessionId}/${fileName}`;
      
      await minioClient.putObject(
        BUCKET_NAME,
        objectName,
        fileStream
      );

      // Retorna a URL do arquivo
      return `${process.env.MINIO_ENDPOINT || 'localhost'}:${process.env.MINIO_PORT || 9000}/${BUCKET_NAME}/${objectName}`;
    } catch (error) {
      console.error('Erro ao fazer upload para o MinIO:', error);
      throw error;
    }
  },

  async getAudioUrl(objectName: string): Promise<string> {
    try {
      // Gera uma URL pré-assinada válida por 1 hora
      const url = await minioClient.presignedGetObject(BUCKET_NAME, objectName, 3600);
      return url;
    } catch (error) {
      console.error('Erro ao gerar URL do áudio:', error);
      throw error;
    }
  },

  async downloadAudio(sessionId: string, fileName: string): Promise<Buffer> {
    return new Promise((resolve, reject) => {
      const objectName = `${sessionId}/${fileName}`;
      minioClient.getObject(BUCKET_NAME, objectName, (err, dataStream) => {
        if (err) return reject(err);
        const chunks: Buffer[] = [];
        dataStream.on('data', (chunk) => chunks.push(chunk));
        dataStream.on('end', () => resolve(Buffer.concat(chunks)));
        dataStream.on('error', reject);
      });
    });
  }
}; 