#reviewed by yahav 1/6/23
import logging
from logging.handlers import SysLogHandler
import requests
import socket

def main():
    WarnList = ['emerg', 'alert', 'crit', 'err', 'warning']
    other = ['notice', 'info', 'debug']
    
    serverAddressPort = ("127.0.0.1",9000)
    buffersize =1024
    
    logger = logging.getLogger(__name__)
    logger.setLevel(logging.DEBUG)
    handler = SysLogHandler(
        facility=SysLogHandler.LOG_DAEMON,
        address='/dev/log'
    )

    formatter = logging.Formatter(
        fmt="%(asctime)s - %(filename)s:%(funcName)s:%(lineno)d %(levelname)s - '%(message)s'",
        datefmt="%Y-%m-%d %H:%M:%S"
    )
    handler.setFormatter(formatter)
    logger.addHandler(handler)

    while True:
        check = input()
        if check in WarnList:
            logger.debug(check)
            bytesToSend = str.encode(check)
            UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
            UDPClientSocket.sendto(bytesToSend,serverAddressPort)
            msgback = UDPClientSocket.recvfrom(buffersize)
            msg = "Message from Server {}".format(msgback[0])
            print(msg)
            print(check)
        elif check in other:
            logger.debug(check)
            print(check)
        elif check == 'exit':
            break
        else:
            print('wrong input')

if __name__ == '__main__':
    main()

