import sys
from socket import *
import threading

serverPort = int(sys.argv[1])
UserName = sys.argv[2]
serverName = '127.0.0.1'
DISCONNECT_MESSAGE = "Disconnected!"

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))

def msginput(UserName, Terminate):
    print("To disconnect from server type: 'Disconnected!'")
    print("Messages:")
    while True:
        msg = raw_input()
        UN = UserName + ": "
        if (str(msg) == 'Disconnected!'):
            Terminate = True
            return
        clientSocket.send(UN.encode())
        clientSocket.send(msg.encode())
        UN = UserName

def display(Terminate):
    while True:
        if (Terminate):
            return
        recievedmsg = clientSocket.recv(1024).decode()
        if(recievedmsg):
            print(recievedmsg)

if __name__ == "__main__":
    Terminate = False
    t1 = threading.Thread(target = msginput, args=(UserName,Terminate))
    t1.start()
    t2 = threading.Thread(target = display, args=(Terminate, ))
    t2.start()
