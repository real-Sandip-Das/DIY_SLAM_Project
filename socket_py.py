import socket

SELF_IP = "0.0.0.0"  # Listen on all available interfaces
UDP_PORT = 4210
#ESP_IP = "192.168.137.164" #Windows Hotspot
ESP_IP = "10.42.0.106" #Linux Hotspot

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((SELF_IP, UDP_PORT))

print("UDP server listening...")

def receive():
    data, addr = sock.recvfrom(1024)
    return data.decode()

def send(MESSAGE):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.sendto(bytes(MESSAGE, "utf-8"), (ESP_IP, UDP_PORT))
