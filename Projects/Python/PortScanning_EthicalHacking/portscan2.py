#!/usr/bin/python

import socket
from termcolor import colored
#imported library to give colour to the output 

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

socket.setdefaulttimeout(0.1)

host = input("[*]Enter the host to scan: ")

def portscanner(port):
	if sock.connect_ex((host,port)):
		print (colored("[!!]port %d is closed" % (port),'red'))
	else:
		print (colored("[+]port %d is open" % (port),'green'))

for port in range(1,100):
	portscanner(port)
#calling function for 100 ports and can change the range
