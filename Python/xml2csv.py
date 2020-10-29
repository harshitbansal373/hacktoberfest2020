import xml.etree.ElementTree as ET
from tkinter.filedialog import askopenfilename
import os
import csv

def readFile(filename):

	if not os.path.exists(filename): return
	tree = ET.parse(filename)
	root = tree.getroot()

	#############################################
	dict_keys = []
	dict_keys = [item for item in input("Enter the key values:\n").split()]
	#############################################
	
	mdlist = []
	for child in root:
		temp = []
		for key in dict_keys:
			temp.append(child.find(key).text)
		mdlist.append(temp)
	return mdlist

def to_CSV(mdlist):

	newfilename = os.path.abspath("./ConvertedXML.csv")
	fh = open(newfilename, "w")
	writer = csv.writer(fh, delimiter=',') 
	for row in mdlist:
		writer.writerow(row)
	fh.close()
	print("complete")

result = readFile(askopenfilename())
if result:
	to_CSV(result)
