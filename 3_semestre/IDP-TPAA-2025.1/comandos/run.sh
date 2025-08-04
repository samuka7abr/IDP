#!/bin/bash

cd ../

read -p "Digite (C/S) num_lista num_questao: " tipo numero questao
tipo=$(echo "$tipo" | tr '[:upper:]' '[:lower:]')

if [ "$tipo" == "c" ]; then
  tipo="casa"
elif [ "$tipo" == "s" ]; then
  tipo="sala"
else
  echo "Erro: Tipo inválido. Use C para casa ou S para sala."
  exit 1
fi

base_dir="A2/listas_${tipo}/lista${numero}/$(printf '%02d' "$questao")"
file_letter=$(printf "\\$(printf '%03o' $((64 + questao)))")

if [ ! -d "$base_dir" ]; then
  echo "Erro: Pasta da questão não encontrada em $base_dir"
  exit 1
fi

g++ "$base_dir/${file_letter}.cpp" -o "$base_dir/exec"

"$base_dir/exec" < "$base_dir/args/input" > "$base_dir/args/output"

if diff -p <(sed 's/[[:space:]]\+$//' "$base_dir/args/output") \
          <(sed 's/[[:space:]]\+$//' "$base_dir/args/expected"); then
  echo -e "\033[1;32mSucesso: As saídas coincidem!\033[0m"
else
  echo -e "\033[1;31mErro: Saídas diferentes!\033[0m"
fi
