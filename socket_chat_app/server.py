import sys
from socket import *
import threading

clients = []
def threadfunction(conn,addr,data): 
    print("New User Joined")
    while True:
        UserName = conn.recv(1024)
        data = conn.recv(1024)
        if data:
            broadcasttoall(data,UserName,conn)
            print(UserName, data)

def broadcasttoall(data,UserName, conn):
    for client in clients:
        if client != conn:
            client.send((str(UserName) + str(data)).encode())
        else:
            client.send(("You: " + data).encode())

if __name__ == "__main__":
    serverPort = int(sys.argv[1])
    serverSocket = socket(AF_INET,SOCK_STREAM)
    serverSocket.bind(('',serverPort))
    serverSocket.listen(1)
    data=""
    while True:
        conn,addr = serverSocket.accept()
        clients.append(conn)
        print("New request recieved from", addr)
        t1 = threading.Thread(target = threadfunction, args = (conn, addr,data))
        t1.start()
    serverSocket.close()
