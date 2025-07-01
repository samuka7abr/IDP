import { Knex } from 'knex';
import dotenv from 'dotenv';

dotenv.config();

const config: { [key: string]: Knex.Config } = {
  development: {
    client: 'postgresql',
    connection: {
      host: process.env.DB_HOST || 'localhost',
      port: Number(process.env.DB_PORT) || 5432,
      database: process.env.DB_NAME || 'mydb',
      user: process.env.DB_USER || 'admin',
      password: process.env.DB_PASSWORD || 'admin123'
    },
    migrations: {
      directory: './src/database/migrations',
      extension: 'ts'
    }
  }
};

export default config; 