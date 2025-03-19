import socket


ip = input("Enter IP address: ")


for port in range(1, 65536):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(0.1)
        result = sock.connect_ex((ip, port))
        if result == 0:
            print(f"Port {port} is open")
        sock.close()
    except KeyboardInterrupt:
        print("Scan terminated by user")
        exit()
    except:
        pass

