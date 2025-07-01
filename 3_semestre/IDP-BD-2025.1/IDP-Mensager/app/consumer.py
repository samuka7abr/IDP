import os
import pika
import json
import time
from services.mongo_service import get_db

def setup_rabbitmq_connection():
    """Configura conexão com RabbitMQ com retry logic"""
    rabbit_url = os.getenv('RABBITMQ_URL')
    max_retries = 10
    
    for attempt in range(max_retries):
        try:
            print(f"🔄 Tentativa {attempt + 1} de conexão com RabbitMQ...")
            params = pika.URLParameters(rabbit_url)
            conn = pika.BlockingConnection(params)
            chan = conn.channel()
            chan.queue_declare(queue='messages', durable=True)
            print("✅ Conexão com RabbitMQ estabelecida")
            return conn, chan
        except Exception as e:
            print(f"❌ Tentativa {attempt + 1} falhou: {e}")
            if attempt < max_retries - 1:
                print("⏳ Aguardando 3 segundos antes da próxima tentativa...")
                time.sleep(3)
            else:
                print("❌ Todas as tentativas de conexão falharam")
                raise e

def callback(ch, method, properties, body):
    try:
        data = json.loads(body)
        print(f"📨 Mensagem consumida: {data['text']}")
        
        db = get_db()
        db.messages.insert_one({
            'chat_id': data['chat_id'],
            'sender': data['sender'],
            'receiver': data['receiver'],
            'text': data['text'],
            'timestamp': data['timestamp']
        })
        print(f"✅ Mensagem salva no banco de dados")
        ch.basic_ack(delivery_tag=method.delivery_tag)
    except Exception as e:
        print(f"❌ Erro ao processar mensagem: {e}")
        ch.basic_nack(delivery_tag=method.delivery_tag, requeue=False)

def main():
    print("🚀 Iniciando consumer...")
    
    try:
        conn, chan = setup_rabbitmq_connection()
        
        chan.basic_qos(prefetch_count=1)
        chan.basic_consume(queue='messages', on_message_callback=callback)
        
        print(' [*] Consumer aguardando mensagens. Para sair, Ctrl+C')
        chan.start_consuming()
        
    except KeyboardInterrupt:
        print("\n👋 Consumer interrompido pelo usuário")
    except Exception as e:
        print(f"❌ Erro fatal no consumer: {e}")
    finally:
        if 'conn' in locals() and conn.is_open:
            conn.close()
            print("🔌 Conexão com RabbitMQ fechada")

if __name__ == '__main__':
    main()
