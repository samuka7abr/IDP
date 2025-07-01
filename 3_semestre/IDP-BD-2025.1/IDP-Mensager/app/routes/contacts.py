from flask import Blueprint, request, jsonify
from services.mongo_service import get_db

contacts_bp = Blueprint('contacts', __name__)

@contacts_bp.route('/contacts/<username>', methods=['POST'])
def add_contact(username):
    data = request.get_json()
    contact = data.get('contact_username')
    if not contact:
        return jsonify({'error': 'contact_username é obrigatório'}), 400
    db = get_db()
    user = db.users.find_one({'username': username})
    if not user:
        return jsonify({'error': 'usuário não encontrado'}), 404
    if not db.users.find_one({'username': contact}):
        return jsonify({'error': 'contato não existe'}), 404
    if contact in user.get('contacts', []):
        return jsonify({'error': 'contato já adicionado'}), 409
    db.users.update_one({'username': username}, {'$push': {'contacts': contact}})
    return jsonify({'message': 'contato adicionado com sucesso'}), 200
