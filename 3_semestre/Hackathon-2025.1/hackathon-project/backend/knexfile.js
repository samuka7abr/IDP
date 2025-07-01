module.exports = {
  development: {
    client: 'postgresql',
    connection: {
      host: 'localhost',
      port: 5432,
      database: 'mydb',
      user: 'admin',
      password: 'admin123'
    },
    migrations: {
      directory: './src/database/migrations',
      extension: 'ts'
    }
  }
}; 