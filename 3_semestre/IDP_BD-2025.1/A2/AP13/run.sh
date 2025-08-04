DB="atividade"

for dir in 01_ddl 02_dml 03_dql; do
  for sql in "$dir"/*.sql; do
    echo ">> Executando $sql…"
    sudo mysql "$DB" < "$sql"
  done
done