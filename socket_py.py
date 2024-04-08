import socket

SELF_IP = "0.0.0.0"  # Listen on all available interfaces
UDP_PORT = 4210

class UDP_connection:
    def __init__(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((SELF_IP, UDP_PORT))
        self.addr = "" #TODO: Add the IP Address of the WiFi Module Access Point from Aditya's Laptop
        print("UDP server listening...")

    def receive(self):
        data, _ = self.sock.recvfrom(1024)
        return data.decode()

    def send(self, MESSAGE):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
        sock.sendto(bytes(MESSAGE, "utf-8"), (self.addr, UDP_PORT))
