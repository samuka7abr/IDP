import requests
import json
import time

BASE_URL = "http://localhost:5000"

def test_create_users():
    """Testa a criação de usuários"""
    print("🧪 Testando criação de usuários...")
    
    users = [
        {"username": "alice", "name": "Alice Silva"},
        {"username": "bob", "name": "Bob Santos"},
        {"username": "carol", "name": "Carol Costa"}
    ]
    
    for user in users:
        response = requests.post(f"{BASE_URL}/users", json=user)
        if response.status_code == 201:
            print(f"✅ Usuário {user['username']} criado com sucesso")
        elif response.status_code == 409:
            print(f"⚠️ Usuário {user['username']} já existe")
        else:
            print(f"❌ Erro ao criar usuário {user['username']}: {response.text}")

def test_login():
    """Testa o login de usuários"""
    print("\n🧪 Testando login...")
    
    # Teste de login válido
    response = requests.post(f"{BASE_URL}/login", json={"username": "alice"})
    if response.status_code == 200:
        user_data = response.json()
        print(f"✅ Login bem-sucedido para {user_data['username']}")
    else:
        print(f"❌ Erro no login: {response.text}")
    
    # Teste de login inválido
    response = requests.post(f"{BASE_URL}/login", json={"username": "usuario_inexistente"})
    if response.status_code == 404:
        print("✅ Login inválido tratado corretamente")
    else:
        print(f"❌ Erro no tratamento de login inválido: {response.text}")

def test_add_contacts():
    """Testa a adição de contatos"""
    print("\n🧪 Testando adição de contatos...")
    
    # Alice adiciona Bob como contato
    response = requests.post(f"{BASE_URL}/contacts/alice", 
                           json={"contact_username": "bob"})
    if response.status_code == 200:
        print("✅ Alice adicionou Bob como contato")
    else:
        print(f"❌ Erro ao adicionar contato: {response.text}")
    
    # Bob adiciona Alice como contato
    response = requests.post(f"{BASE_URL}/contacts/bob", 
                           json={"contact_username": "alice"})
    if response.status_code == 200:
        print("✅ Bob adicionou Alice como contato")
    else:
        print(f"❌ Erro ao adicionar contato: {response.text}")

def test_get_chats():
    """Testa a busca de chats"""
    print("\n🧪 Testando busca de chats...")
    
    response = requests.get(f"{BASE_URL}/chats/alice")
    if response.status_code == 200:
        chats = response.json()
        print(f"✅ Chats de Alice: {chats}")
    else:
        print(f"❌ Erro ao buscar chats: {response.text}")

def test_send_messages():
    """Testa o envio de mensagens"""
    print("\n🧪 Testando envio de mensagens...")
    
    messages = [
        {"chat_id": "alice_bob", "sender": "alice", "receiver": "bob", "text": "Olá Bob!"},
        {"chat_id": "alice_bob", "sender": "bob", "receiver": "alice", "text": "Oi Alice! Como vai?"},
        {"chat_id": "alice_bob", "sender": "alice", "receiver": "bob", "text": "Tudo bem, e você?"}
    ]
    
    for message in messages:
        response = requests.post(f"{BASE_URL}/messages", json=message)
        if response.status_code == 202:
            print(f"✅ Mensagem enviada: {message['text']}")
        else:
            print(f"❌ Erro ao enviar mensagem: {response.text}")
        
        time.sleep(1)  

def test_get_messages():
    """Testa a busca de mensagens"""
    print("\n🧪 Testando busca de mensagens...")
    
    response = requests.get(f"{BASE_URL}/messages/alice_bob")
    if response.status_code == 200:
        messages = response.json()
        print(f"✅ Mensagens encontradas: {len(messages)}")
        for msg in messages:
            print(f"   {msg['sender']}: {msg['text']}")
    else:
        print(f"❌ Erro ao buscar mensagens: {response.text}")

def main():
    """Executa todos os testes"""
    print("🚀 Iniciando testes do sistema de mensageria...")
    print("=" * 50)
    
    try:
        test_create_users()
        test_login()
        test_add_contacts()
        test_get_chats()
        test_send_messages()
        test_get_messages()
        
        print("\n" + "=" * 50)
        print("🎉 Todos os testes concluídos!")
        
    except requests.exceptions.ConnectionError:
        print("❌ Erro: Não foi possível conectar ao servidor.")
        print("   Certifique-se de que o servidor está rodando em http://localhost:5000")
    except Exception as e:
        print(f"❌ Erro inesperado: {e}")

if __name__ == "__main__":
    main() 