
import socket

HOST = "127.0.0.1"
PORT = 12345

with socket.create_connection((HOST, PORT)) as sock:
    while True:
        msg = input("> ")
        sock.sendall(msg.encode())
        data = sock.recv(1024)
        print(data.decode())
        if msg.lower() == "sair":
            break
