from socket import *

serverName = "127.0.0.1"
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)

message = input("Digite sua mensagem: ")
print(f"mensagem enviada {message}")
clientSocket.sendto(message.encode(), (serverName, serverPort))

modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print(f"mensagem recebida {modifiedMessage.decode()}")

clientSocket.close()

