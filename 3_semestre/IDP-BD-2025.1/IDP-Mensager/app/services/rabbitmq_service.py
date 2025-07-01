import os
import pika
import json
import time

_rabbitmq_url = os.getenv('RABBITMQ_URL')
_connection = None
_channel = None

def _get_connection():
    global _connection, _channel
    if _connection is None or _connection.is_closed:
        max_retries = 5
        for attempt in range(max_retries):
            try:
                params = pika.URLParameters(_rabbitmq_url)
                _connection = pika.BlockingConnection(params)
                _channel = _connection.channel()
                _channel.queue_declare(queue='messages', durable=True)
                print("✅ Conexão com RabbitMQ estabelecida")
                break
            except Exception as e:
                print(f"❌ Tentativa {attempt + 1} de conexão com RabbitMQ falhou: {e}")
                if attempt < max_retries - 1:
                    time.sleep(2)
                else:
                    raise e
    return _connection, _channel

def publish_message(payload: dict):
    try:
        connection, channel = _get_connection()
        body = json.dumps(payload)
        channel.basic_publish(
            exchange='',
            routing_key='messages',
            body=body,
            properties=pika.BasicProperties(delivery_mode=2)
        )
        print(f"✅ Mensagem publicada: {payload['text']}")
    except Exception as e:
        print(f"❌ Erro ao publicar mensagem: {e}")
        # Reset connection for next attempt
        global _connection, _channel
        _connection = None
        _channel = None
        raise e
