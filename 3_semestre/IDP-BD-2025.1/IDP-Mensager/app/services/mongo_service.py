from pymongo import MongoClient
import os
from dotenv import load_dotenv

load_dotenv()
_client = MongoClient(os.getenv('MONGO_URI'))

def get_db():
    return _client.get_default_database()
