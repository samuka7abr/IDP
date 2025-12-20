from scapy.all import *
import time

def send_icmp_hello_world(destination_ip, message="Hello World"):
    """
    Envia um pacote ICMP Echo Request (ping) com uma mensagem personalizada no payload.
    
    Args:
        destination_ip (str): IP de destino (ex: "192.168.1.100").
        message (str): Mensagem a ser incluída no payload (padrão: "Hello World").
    """
    # Cria o pacote ICMP Echo Request com payload personalizado
    packet = IP(dst=destination_ip)/ICMP()/message.encode('utf-8')
    
    # Envia o pacote
    send(packet, verbose=True)
    print(f"\n✅ Pacote ICMP enviado para {destination_ip} com payload: '{message}'")

if __name__ == "__main__":
    # Configuração
    target_ip = "192.168.10.2"  # Substitua pelo IP da VM alvo
    custom_message = "Hello World"
    
    # Envia o pacote
    send_icmp_hello_world(target_ip, custom_message)