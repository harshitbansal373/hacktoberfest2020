#!/usr/bin/python

from socket import *
#import everything from socket library ..* means
import optparse
#for specifing ports, getting help,etc
from threading import *
#for giving threads to do the task

def connScan(tgtHost,tgtPort):
	try:
		sock = socket(AF_INET,SOCK_STREAM)
		sock.connect((tgtHost,tgtPort))
		print '[+] %d /tcp open' % tgtPort
	except:
		print '[-] %d /tcp closed' % tgtPort
	finally:
		sock.close()
#this defined  the socket program to check if the port is open or closed


def portscan(tgtHost,tgtPorts):
	try:
		tgtIP = gethostbyname(tgtHost)
	except:
		print 'Unknown Host %s' %tgtHost
#this command gets the IP addr of the host by its dns name or else returns unknown host
	try:
		tgtName = gethostbyaddr(tgtIP)
		print '[+] scan results for:' + tgtIP
		#print '[+] scan results for:' + tgtName[0]
	except:
		print '[+]Scan results for:' + tgtIP
#this command prints the result in the form of domain name or else by its IP
	setdefaulttimeout(1)
#timeout setting for scanning a port on the host ip 

	for tgtPort in tgtPorts:
		t= Thread(target=connScan, args=(tgtHost,int(tgtPort)))
		t.start()
#this takes a single port from all ports scans it and determines whether connection is open or closed
def main():
	parser = optparse.OptionParser('Usage of program:' + '-H <target host> -p <target port>')
	parser.add_option('-H', dest='tgtHost', type='string',help='specify target host')
	parser.add_option('-p', dest='tgtPort', type='string',help='specify target ports separated by comma')
	(options, args) = parser.parse_args()
	tgtHost = options.tgtHost
	tgtPorts = str(options.tgtPort).split(',')
	if (tgtHost == None) | (tgtPorts[0] == None):
		print parser.usage
		exit(0)
#the above parser gives a range of options to show when the scan has happened like help
	portscan(tgtHost,tgtPorts)
#calls the portscan function
if __name__ == '__main__':
	main()

