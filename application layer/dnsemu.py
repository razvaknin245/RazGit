import socket

url = input("Enter URL: ")
wordsfile = "/home/raz/Documents/all.txt"


with open(wordsfile) as f:
    words = f.readlines()


words = [word.strip() for word in words]


for word in words:
    subdomain = word + '.' + url
    try:
        ips = socket.gethostbyname_ex(subdomain)[2]
        print(f"{subdomain} resolves to {', '.join(ips)}")
    except:
        pass

