#!/bin/bash

PROJ_DIR="$(cd "$(dirname "$0")/.." && pwd)"

echo "Num lista (ex: 01):"
read lista_num

echo "Num exercício (ex: 01):"
read ex

LISTA_DIR="A1/lista$lista_num"
MAKEFILE="$PROJ_DIR/$LISTA_DIR/Makefile"

if [ ! -d "$PROJ_DIR/$LISTA_DIR" ]; then
  echo "❌ Lista 'lista$lista_num' não encontrada em A1/"
  exit 1
fi

if [ ! -f "$MAKEFILE" ]; then
  echo "❌ Makefile não encontrado em $LISTA_DIR"
  exit 1
fi

sed -i "s/^TARGET=.*/TARGET=$ex/" "$MAKEFILE"

docker run -it --rm \
  -v "$PROJ_DIR":/home/riscv \
  -w "/home/riscv/$LISTA_DIR" \
  risc-v-dev \
  make run

