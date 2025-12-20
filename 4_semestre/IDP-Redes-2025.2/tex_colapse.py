from pathlib import Path
import re
from datetime import datetime
import sys

def normalizar_lab(s):
    d = ''.join(ch for ch in s if ch.isdigit())
    if not d:
        return None
    return f"lab{int(d):02d}"

def escolher_tex(lab_dir):
    tex_files = sorted(lab_dir.rglob("*.tex"))
    if not tex_files:
        return None
    for f in tex_files:
        if f.name.lower() == "main.tex":
            return f
    return tex_files[0]

def remover_comentarios_e_colapsar(texto):
    sem_coment = re.sub(r'(?<!\\)%.*', '', texto)
    colapsado = re.sub(r'\s+', ' ', sem_coment).strip()
    return colapsado

# A função backup_path e a sua chamada serão removidas.
# def backup_path(p):
#     b = p.with_suffix(p.suffix + ".bak")
#     if not b.exists():
#         return b
#     ts = datetime.now().strftime("%Y%m%d%H%M%S")
#     return p.with_suffix(p.suffix + f".{ts}.bak")

def main():
    raiz = Path(__file__).resolve().parent
    base = raiz / "A1"
    if not base.is_dir():
        print("Pasta A1 não encontrada na raiz do projeto.")
        sys.exit(1)
    lab_in = input("Número do lab (ex: 1, 01, lab01): ").strip()
    lab_norm = normalizar_lab(lab_in)
    if not lab_norm:
        print("Entrada inválida.")
        sys.exit(1)
    lab_dir = base / lab_norm
    if not lab_dir.is_dir():
        disponiveis = ", ".join(sorted(p.name for p in base.iterdir() if p.is_dir() and p.name.lower().startswith("lab")))
        print(f"Pasta {lab_dir} não encontrada. Labs disponíveis: {disponiveis}")
        sys.exit(1)
    alvo = escolher_tex(lab_dir)
    if not alvo:
        print("Nenhum arquivo .tex encontrado no diretório do lab.")
        sys.exit(1)
    original = alvo.read_text(encoding="utf-8")
    colapsado = remover_comentarios_e_colapsar(original)
    # bkp = backup_path(alvo)
    # bkp.write_text(original, encoding="utf-8")
    alvo.write_text(colapsado, encoding="utf-8")
    try:
        rel = alvo.relative_to(raiz)
    except ValueError:
        rel = alvo
    print(f"OK: {rel} colapsado em uma única linha.")

if __name__ == "__main__":
    main()