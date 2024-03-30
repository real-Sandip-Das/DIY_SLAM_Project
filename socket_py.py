import socket

SELF_IP = "0.0.0.0"  # Listen on all available interfaces
UDP_PORT = 4210
#ESP_IP = "192.168.137.164" #Windows Hotspot
#ESP_IP = "10.42.0.106" #Linux Hotspot

class UDP_connection:
    def __init__(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((SELF_IP, UDP_PORT))
        print("UDP server listening...")

    def receive(self):
        data, addr = self.sock.recvfrom(1024)
        self.addr = addr
        return data.decode()

    def send(self, MESSAGE):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
        sock.sendto(bytes(MESSAGE, "utf-8"), (self.addr, UDP_PORT))
