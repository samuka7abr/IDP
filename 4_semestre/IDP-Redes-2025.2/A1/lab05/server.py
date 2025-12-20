from socket import *
import base64

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(("", serverPort))

print("Servidor pronto para recebimento de mensagens")

while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    print(message)
    modifiedMessage = base64.b64encode(message).decode()
    print(modifiedMessage)
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)

