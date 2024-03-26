import socket

SELF_IP = "0.0.0.0"  # Listen on all available interfaces
UDP_PORT = 4210
ESP_IP = "192.168.137.164"
MESSAGE = "Hello from Python to NodeMCU" #Message to be sent from Laptop to NodeMCU

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((SELF_IP, UDP_PORT))

print("UDP server listening...")

while True:
    data, addr = sock.recvfrom(1024)  # Buffer size is 1024 bytes
    print("Received message:", data.decode())

    print("UDP target IP:", ESP_IP)
    print("UDP target port:", UDP_PORT)
    print("message:", MESSAGE)

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.sendto(bytes(MESSAGE, "utf-8"), (UDP_IP, UDP_PORT))

