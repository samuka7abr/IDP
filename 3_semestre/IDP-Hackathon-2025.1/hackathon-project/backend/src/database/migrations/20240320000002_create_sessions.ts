import type { Knex } from 'knex';

export async function up(knex: Knex): Promise<void> {
  return knex.schema.createTable('sessions', (table) => {
    table.increments('id').primary();
    table.integer('patient_id').unsigned().notNullable();
    table.date('date').notNullable();
    table.enum('status', ['pending', 'completed']).notNullable();
    table.text('transcription');
    table.jsonb('analysis');
    table.timestamps(true, true);

    table.foreign('patient_id')
      .references('id')
      .inTable('patients')
      .onDelete('CASCADE');
  });
}

export async function down(knex: Knex): Promise<void> {
  return knex.schema.dropTable('sessions');
} 