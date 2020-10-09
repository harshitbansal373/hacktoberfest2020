#!/usr/bin/python

import socket 


def retBanner(ip,port):
	try:
		socket.setdefaulttimeout(2)
		s = socket.socket()
		s.connect((ip,port))
		banner = s.recv(1024)
		return banner
	except:
		return
#this program uses scoket program to get information about the open ports



def main():
	ip = raw_input ("[+] Enter Target IP: ")
	for port in range (1,100):
		banner = retBanner(ip,port)
		if banner:
			print "[+]" + ip + "/" + str(port) +  ": " + banner.strip('/n')
main()

#main functions call the retBanner function and prints the output on screen

