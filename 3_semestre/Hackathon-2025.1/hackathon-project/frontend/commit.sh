#!/usr/bin/env bash

# Sobe dois níveis até a raiz do repositório
dir="$(dirname "$0")"
cd "$dir/../.."

echo ""
echo "📁 Commitando em: $(pwd)"
echo ""

echo "Selecione o tipo de commit:"
echo "1 - feat"
echo "2 - chore"
echo "3 - fix"
echo "4 - delete"
echo "5 - style"
echo "6 - docs"
echo ""

read -p "Digite o número correspondente: " tipo
case $tipo in
  1) prefixo="feat" ;;
  2) prefixo="chore" ;;
  3) prefixo="fix" ;;
  4) prefixo="delete" ;;
  5) prefixo="style" ;;
  6) prefixo="docs" ;;
  *) echo "❌ Tipo inválido"; exit 1 ;;
esac

echo ""
prompt="Front-End $prefixo"
read -p "Mensagem do commit: " msg

if [ -z "$msg" ]; then
  echo "❌ A mensagem do commit não pode estar vazia."
  exit 1
fi

echo ""
echo "🚀 Comitando com: $prompt: $msg"
echo ""

git add .
git commit -m "$prompt: $msg" || {
  echo "❌ Erro ao tentar commitar. Verifique se há validações ou hooks ativos."
  exit 1
}

git push && echo "✅ Push feito com sucesso!"
