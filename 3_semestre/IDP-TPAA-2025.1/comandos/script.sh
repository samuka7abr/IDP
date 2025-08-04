#!/bin/bash
cd "$(dirname "$0")"/..

echo "Commitando em: $(pwd)"
echo "Selecione o tipo de commit:"
echo "1 - Study"
echo "2 - Docs"
echo "3 - LEE (casa)"
echo "4 - LEA (sala)"
echo "5 - Refactoring"
read -p "Digite o número correspondente: " tipo

case $tipo in
  1) prefixo="Study" ;;
  2) prefixo="Docs" ;;
  3) prefixo="LEE" ;;
  4) prefixo="LEA" ;;
  5) prefixo="Refactoring" ;;
  *) echo "Tipo inválido"; exit 1 ;;
esac

read -p "Mensagem do commit: " msg
if [ -z "$msg" ]; then
  echo "A mensagem do commit não pode estar vazia."
  exit 1
fi

git add .
git commit -m "$prefixo: $msg" || {
  echo "Erro ao tentar commitar. Verifique se há validações ou hooks ativos."
  exit 1
}
git push
