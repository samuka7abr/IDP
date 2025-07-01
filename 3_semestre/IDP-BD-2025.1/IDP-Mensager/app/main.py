from flask import Flask, render_template
from flask_socketio import SocketIO, emit, join_room, leave_room
from dotenv import load_dotenv
import os
from pymongo import MongoClient
from routes.users import users_bp
from routes.contacts import contacts_bp
from routes.messages import messages_bp

load_dotenv()

app = Flask(
    __name__,
    static_folder='static',
    template_folder='templates'
)
app.config['SECRET_KEY'] = os.getenv('FLASK_SECRET_KEY')

socketio = SocketIO(app, cors_allowed_origins="*")

app.register_blueprint(users_bp)
app.register_blueprint(contacts_bp)
app.register_blueprint(messages_bp)

mongo_uri = os.getenv('MONGO_URI')
mongo_client = MongoClient(mongo_uri)
db = mongo_client.get_default_database()

@app.route('/')
def index():
    return render_template('index.html')

@socketio.on('connect')
def handle_connect():
    print('Cliente conectado')

@socketio.on('join')
def handle_join(data):
    username = data['username']
    join_room(username)
    print(f'Usuário {username} entrou na sala')

@socketio.on('send_message')
def handle_message(data):
    try:
        # Salvar mensagem no banco
        from services.mongo_service import get_db
        from datetime import datetime, timezone
        
        db = get_db()
        message_data = {
            'chat_id': data['chat_id'],
            'sender': data['sender'],
            'receiver': data['receiver'],
            'text': data['text'],
            'timestamp': datetime.now(timezone.utc).isoformat()
        }
        
        # Salvar no MongoDB
        result = db.messages.insert_one(message_data)
        message_data['_id'] = str(result.inserted_id)
        
        print(f"✅ Mensagem salva: {message_data['text']} de {message_data['sender']} para {message_data['receiver']}")
        
        # Enviar mensagem para o destinatário
        emit('new_message', message_data, room=data['receiver'])
        print(f"📤 Mensagem enviada para {data['receiver']}")
        
        # Enviar confirmação para o remetente
        emit('message_sent', message_data, room=data['sender'])
        print(f"✅ Confirmação enviada para {data['sender']}")
        
    except Exception as e:
        print(f"❌ Erro ao processar mensagem: {e}")
        # Enviar erro para o remetente
        emit('message_error', {'error': 'Erro ao enviar mensagem'}, room=data['sender'])

if __name__ == '__main__':
    socketio.run(app, host='0.0.0.0', port=5000, debug=True, allow_unsafe_werkzeug=True)
