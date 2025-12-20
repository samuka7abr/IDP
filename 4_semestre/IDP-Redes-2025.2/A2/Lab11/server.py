
import socket

HOST = "127.0.0.1"
PORT = 12345

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind((HOST, PORT))
    s.listen(1)
    conn, addr = s.accept()
    with conn:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            msg = data.decode().strip()
            conn.sendall(data)
            if msg.lower() == "sair":
                break
