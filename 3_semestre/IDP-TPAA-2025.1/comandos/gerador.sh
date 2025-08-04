#!/bin/bash

echo "Iniciando a construção da estrutura de pastas e scripts básicos..."

# --- Estrutura A1 ---
mkdir -p A1/listas_casa
mkdir -p A1/listas_sala
mkdir -p A1/prova_1 # Mantendo a pasta da prova_1, pois não é uma lista dinâmica

# --- Estrutura A2 ---
mkdir -p A2/listas_casa
mkdir -p A2/listas_sala
mkdir -p A2/prova_2 # Mantendo a pasta da prova_2, pois não é uma lista dinâmica

# --- Estrutura Comandos e Criação dos Scripts `.sh` ---
mkdir -p comandos/prova

# exclui.sh
cat << 'EOF' > comandos/exclui.sh
#!/bin/bash

# Este script remove arquivos executáveis nomeados como "exec"
# Ele busca dentro do diretório do projeto.
# ATENÇÃO: Verifique o caminho TARGET_DIR para garantir que está correto para seu ambiente.
TARGET_DIR="/home/samuelabrao/VSCODE/IDP/3° Semestre/TPAA-IDP"

echo "Buscando e removendo arquivos 'exec' em: $TARGET_DIR"
find "$TARGET_DIR" -type f -name "exec" -exec rm -v {} +

echo "Remoção finalizada."
EOF
chmod +x comandos/exclui.sh

# lista.sh
cat << 'EOF' > comandos/lista.sh
#!/bin/bash

# Este script cria a estrutura de pastas e arquivos para uma nova lista de exercícios.
# Ele espera ser executado a partir do diretório 'comandos' ou similar,
# pois ele sobe um nível para a raiz do projeto.
cd "$(dirname "$0")/.."

read -p "A lista é pra casa ou sala? (c/s): " tipo
read -p "Número da lista: " numero
read -p "Quantas questões? " questoes

tipo=$(echo "$tipo" | tr '[:upper:]' '[:lower:]')
if [ "$tipo" == "c" ]; then
  tipo="casa"
elif [ "$tipo" == "s" ]; then
  tipo="sala"
else
  echo "Erro: Tipo inválido. Use 'c' para casa ou 's' para sala."
  exit 1
fi

base_dir="A2/listas_${tipo}/lista${numero}" # Note que aqui está fixo em A2, talvez você queira flexibilizar para A1 também.

echo "Criando estrutura para $base_dir com $questoes questões..."
mkdir -p "$base_dir"

template_code='#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18; 
const int MOD = 1000000007;

int main(){
    otim;
    
    return 0;
}'

for ((i=1; i<=questoes; i++)); do
  pasta_num=$(printf "%02d" "$i")
  # Converte o número para letra (1=A, 2=B, etc.)
  letra=$(printf "\\$(printf '%03o' $((64 + i)))") 

  mkdir -p "$base_dir/$pasta_num"
  echo "$template_code" > "$base_dir/$pasta_num/${letra}.cpp"

  mkdir -p "$base_dir/$pasta_num/args"
  touch "$base_dir/$pasta_num/args/input"
  touch "$base_dir/$pasta_num/args/expected"
done

mkdir -p "$base_dir/questoes" # Cria a pasta de questões, sem PDFs

echo "Lista criada com sucesso em: $base_dir"
EOF
chmod +x comandos/lista.sh

# run.sh
cat << 'EOF' > comandos/run.sh
#!/bin/bash

# Este script executa um programa C++ e compara sua saída com a esperada.
# Ele espera ser executado a partir do diretório 'comandos' ou similar,
# pois ele sobe um nível para a raiz do projeto.
cd "$(dirname "$0")/.."

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

base_dir="A2/listas_${tipo}/lista${numero}/$(printf '%02d' "$questao")" # Note aqui o A2 fixo

if [ ! -d "$base_dir" ]; then
  echo "Erro: Pasta da questão não encontrada em $base_dir"
  exit 1
fi

# Converte o número da questão para letra (1=A, 2=B, etc.)
file_letter=$(printf "\\$(printf '%03o' $((64 + questao)))")

echo "Compilando $base_dir/${file_letter}.cpp..."
g++ "$base_dir/${file_letter}.cpp" -o "$base_dir/exec"

echo "Executando e comparando saídas..."
"$base_dir/exec" < "$base_dir/args/input" > "$base_dir/args/output"

if diff -p <(sed 's/[[:space:]]\+$//' "$base_dir/args/output") \
          <(sed 's/[[:space:]]\+$//' "$base_dir/args/expected"); then
  echo -e "\033[1;32mSucesso: As saídas coincidem!\033[0m"
else
  echo -e "\033[1;31mErro: Saídas diferentes!\033[0m"
  # Para ver as diferenças mais claramente
  echo "--- Diff ---"
  diff "$base_dir/args/output" "$base_dir/args/expected"
  echo "------------"
fi
EOF
chmod +x comandos/run.sh

# commit.sh
cat << 'EOF' > comandos/commit.sh
#!/bin/bash
# Script para padronizar mensagens de commit.
# Navega para a raiz do repositório Git.
cd "$(dirname "$0")"/..

echo "Preparando commit em: $(pwd)"
echo "Selecione o tipo de commit:"
echo "1 - Study (Estudos, testes, anotações)"
echo "2 - Docs (Documentação, READMEs, comentários)"
echo "3 - LEE (Implementação/correção de Lista de Exercícios de Casa)"
echo "4 - LEA (Implementação/correção de Lista de Exercícios de Sala)"
echo "5 - Refactoring (Refatoração de código)"
read -p "Digite o número correspondente: " tipo

case $tipo in
  1) prefixo="Study" ;;
  2) prefixo="Docs" ;;
  3) prefixo="LEE" ;;
  4) prefixo="LEA" ;;
  5) prefixo="Refactoring" ;;
  *) echo "Tipo de commit inválido. Saindo."
     exit 1 ;;
esac

read -p "Mensagem do commit (curta e descritiva): " msg
if [ -z "$msg" ]; then
  echo "A mensagem do commit não pode estar vazia. Por favor, forneça uma mensagem."
  exit 1
fi

echo "Adicionando todos os arquivos modificados/novos ao stage..."
git add .
echo "Criando commit: \"$prefixo: $msg\""
git commit -m "$prefixo: $msg" || {
  echo "Erro ao tentar commitar. Verifique se há alterações a serem commitadas ou regras de pre-commit."
  exit 1
}
echo "Enviando alterações para o repositório remoto..."
git push || {
  echo "Erro ao tentar enviar as alterações (push). Verifique sua conexão ou permissões."
  exit 1
}
echo "Commit e push concluídos com sucesso!"
EOF
chmod +x comandos/commit.sh

# comandos/gerador.sh (este é o script que o README mencionaria para gerar a estrutura)
# Se este script atual (gerador_completo.sh) for o seu "gerador",
# você pode mover o conteúdo deste arquivo para comandos/gerador.sh.
# Por enquanto, estou criando um placeholder em comandos/gerador.sh.
cat << 'EOF' > comandos/gerador.sh
#!/bin/bash
# Este script deve conter a lógica para criar a estrutura completa do repositório,
# incluindo as pastas e os scripts iniciais.
# O conteúdo que você está executando agora (o script 'gerador.sh' externo)
# deve ser copiado para dentro deste arquivo para que ele funcione.
echo "Este é o script 'gerador.sh' localizado em comandos/."
echo "Para que ele funcione como o gerador completo do projeto,"
echo "o conteúdo do script principal que você executou deve ser colocado aqui."
echo "Ex: copie o conteúdo do 'gerador_completo.sh' para este arquivo."
EOF
chmod +x comandos/gerador.sh


# comandos/prova/run.sh
cat << 'EOF' > comandos/prova/run.sh
#!/bin/bash
# Script simplificado para rodar questões de prova.
# Assume que você está no diretório da prova (ex: A2/prova_2).

read -p "Número da questão: " q
q_padded=$(printf "%02d" "$q") 

if [ ! -d "$q_padded" ]; then
    echo "Erro: Diretório da questão '$q_padded' não encontrado."
    exit 1
fi

cpp_file=$(find "$q_padded" -maxdepth 1 -type f -name "*.cpp" -print -quit)

if [ -z "$cpp_file" ]; then
    echo "Erro: Nenhum arquivo .cpp encontrado em '$q_padded'."
    exit 1
fi

echo "Compilando $(basename "$cpp_file")..."
g++ "$cpp_file" -o "$q_padded"/exec || { echo "Erro de compilação!"; exit 1; }

echo "Executando e comparando saída..."
"$q_padded"/exec < "$q_padded"/args/input > "$q_padded"/args/output

diff -qs "$q_padded"/args/output "$q_padded"/args/expected && echo -e "\033[1;32mSucesso\033[0m" || echo -e "\033[1;31mErro\033[0m"

# Opcional: mostrar diff em caso de erro
if ! diff -qs "$q_padded"/args/output "$q_padded"/args/expected >/dev/null; then
    echo "--- Diferenças ---"
    diff "$q_padded"/args/output "$q_padded"/args/expected
    echo "------------------"
fi
EOF
chmod +x comandos/prova/run.sh


# comandos/prova/prova.sh
cat << 'EOF' > comandos/prova/prova.sh
#!/bin/bash
# Script para criar a estrutura básica de questões dentro de um diretório de prova.
# Execute este script estando DENTRO do diretório da prova (ex: A2/prova_2).

read -p "Quantas questões? " q

template='#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18; 

int main(){
    otim;
    
    return 0;
}'

for ((i=1; i<=q; i++)); do
  qn=$(printf "%02d" "$i")
  letra=$(printf "\\$(printf '%03o' $((64 + i)))") 
  mkdir -p "$qn/args"
  echo "$template" > "$qn/${letra}.cpp"
  touch "$qn/args/input"
  touch "$qn/args/expected"
done

echo "Base da prova criada na pasta atual: $(pwd)"
EOF
chmod +x comandos/prova/prova.sh

# Criando as pastas 'slides'
mkdir -p slides/A1
mkdir -p slides/A2

# Criando as pastas e arquivos vazios do diretório `study`
mkdir -p study/A1
touch study/A1/bitWiseOps.cpp
touch study/A1/bubbleSort.cpp
touch study/A1/EDA.cpp
mkdir -p study/A1/pontos_fracos/Fortinaite
touch study/A1/pontos_fracos/Fortinaite/main.cpp
mkdir -p study/A1/pontos_fracos/maioresNotas
touch study/A1/pontos_fracos/maioresNotas/main.cpp
mkdir -p study/A1/pontos_fracos/planejamento
touch study/A1/pontos_fracos/planejamento/main.cpp
mkdir -p study/A1/Revis\303\243oP1 # RevisãoP1 (escapando o 'ã')
touch study/A1/Revis\303\243oP1/revisao.md
touch study/A1/Sort_Search.cpp

mkdir -p study/A2/Algoritmos/Sorting/Counting\ Sort # Escapando o espaço
touch study/A2/Algoritmos/Sorting/Counting\ Sort/CountingSort.md
touch study/A2/Algoritmos/Sorting/Counting\ Sort/main.cpp
touch study/A2/grafos.cpp
touch study/A2/hashes.cpp

echo "Estrutura básica de pastas e scripts criada com sucesso!"
echo "As subpastas das listas (ex: lista1, 01, args) serão criadas pelos scripts 'lista.sh' e 'prova.sh'."