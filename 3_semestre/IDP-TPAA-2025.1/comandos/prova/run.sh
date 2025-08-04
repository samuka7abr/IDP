read -p "Num da questao: " q
q_padded=$(printf "%02d" "$q") 
g++ "$q_padded"/*.cpp -o "$q_padded"/exec
"$q_padded"/exec < "$q_padded"/args/input > "$q_padded"/args/output
diff -qs "$q_padded"/args/output "$q_padded"/args/expected && echo "Sucesso" || echo "Erro"