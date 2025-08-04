#!/bin/bash

TARGET_DIR="/home/samuelabrao/VSCODE/IDP/3° Semestre/TPAA-IDP"

find "$TARGET_DIR" -type f -name "exec" -exec rm -v {} +

echo "Remoção finalizada."
