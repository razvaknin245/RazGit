import socket
import threading

ip = input("Enter IP address: ")
port = int(input("Enter port number: "))

def scan(ip, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(1)
    result = sock.connect_ex((ip, port))
    if result == 0:
        print(f"Port {port} is open on {ip}")
    else:
        print(f"Port {port} is closed on {ip}")
    sock.close()

try:
    for i in range(0, 255):
        for j in range(0, 255):
            for k in range(0, 255):
                try:
                    thr = threading.Thread(target=scan, args=(f"{ip}.{i}.{j}.{k}", port))
                    thr.start()
                except Exception as e:
                    print(f"An error occurred: {e}")
                    pass
except KeyboardInterrupt:
    thr.join()

