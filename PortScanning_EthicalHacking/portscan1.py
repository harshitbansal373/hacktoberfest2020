#!/usr/bin/python

import socket
#tells wheter host is up or down

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#AF_inet= IPv4 address, SOCK_STREAM=Tcp packets
socket.setdefaulttimeout(5)
#setting the time it takes to scan the port

host = raw_input("[*] Enter the host to scan: ")
port = int(raw_input("[*] Enter the port to scan: "))
#entering the value of the host and port

def portscanner(port):
	if sock.connect_ex((host,port)):
		print "port %d is closed" % (port)
	else:
		print "port %d is open" % (port)
portscanner(port)
#defined a function portscanner with argument port
#sock.connect_ex checks if there is error in the host and port specified then port is closed
#%d writes the value i.e. % port
#port scanner(port) calls the function

