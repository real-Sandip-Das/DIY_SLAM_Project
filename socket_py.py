import socket

UDP_IP = "127.0.0.1"  # Listen on all available interfaces
UDP_PORT = 4210
MESSAGE = "Hello from Python to NodeMCU" #Message to be sent from Laptop to NodeMCU

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print("UDP server listening...")

while True:
    data, addr = sock.recvfrom(1024)  # Buffer size is 1024 bytes
    print("Received message:", data.decode())

    print("UDP target IP:", UDP_IP)
    print("UDP target port:", UDP_PORT)
    print("message:", MESSAGE)

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.sendto(bytes(MESSAGE, "utf-8"), (UDP_IP, UDP_PORT))

