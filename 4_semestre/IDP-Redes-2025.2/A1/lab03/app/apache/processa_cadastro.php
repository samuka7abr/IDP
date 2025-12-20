<?php
header('Content-Type: application/json');
// Configurações do banco de dados (ALTERE COM O IP DA VM SERVIDOR)
$servidor_db = "db"; // IP da VM Servidor
$usuario_db = "app_user";
$senha_db = "samuel";
$banco_db = "produtos_db";
// Conexão com o banco
$conexao = new mysqli($servidor_db, $usuario_db, $senha_db, $banco_db);
// Verifica conexão
if ($conexao->connect_error) {
 echo json_encode([ 
 'success' => false,
 'message' => 'Erro de conexão: ' . $conexao->connect_error
 ]);
 exit;
}
// Coleta e sanitiza dados
$nome = $conexao->real_escape_string($_POST['nome'] ?? '');
$descricao = $conexao->real_escape_string($_POST['descricao'] ?? '');
$preco = floatval($_POST['preco'] ?? 0);
$quantidade = intval($_POST['quantidade'] ?? 0);
// Validação
if (empty($nome) || $preco <= 0 || $quantidade < 0) {
 echo json_encode([
 'success' => false,
 'message' => 'Dados inválidos'
 ]);
 exit;
}
// Insere no banco
$sql = "INSERT INTO produtos (nome, descricao, preco, quantidade)
 VALUES ('$nome', '$descricao', $preco, $quantidade)";
if ($conexao->query($sql) === TRUE) {
 echo json_encode([
 'success' => true, 
 'message' => 'Produto cadastrado com sucesso! ID: ' . $conexao->insert_id
 ]);
} else {
 echo json_encode([
 'success' => false,
 'message' => 'Erro ao cadastrar: ' . $conexao->error
 ]);
}
$conexao->close();
?>
