import Fastify from 'fastify';
import cors from '@fastify/cors';
import dotenv from 'dotenv';
import { routes } from './routes';

// Carrega as variáveis de ambiente
dotenv.config();

const fastify = Fastify({
  logger: true
});

// Registra o CORS
fastify.register(cors, {
  origin: true
});

// Registra as rotas
fastify.register(routes);

// Rota de teste
fastify.get('/', async () => {
  return { status: 'API is running' };
});

const start = async () => {
  try {
    // Inicia o servidor
    await fastify.listen({ 
      port: Number(process.env.PORT) || 3333,
      host: '0.0.0.0'
    });
    console.log(`🚀 Server listening on http://localhost:${process.env.PORT || 3333}`);
  } catch (err) {
    fastify.log.error(err);
    process.exit(1);
  }
};

// Tratamento de erros não capturados
process.on('unhandledRejection', (err) => {
  console.error('Unhandled Rejection:', err);
  process.exit(1);
});

start();
