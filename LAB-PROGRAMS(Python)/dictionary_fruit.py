fruits={'Apple':0,'Banana':0,'Grapes':0}
fruits['Apple']=(int)(input("Enter the cost of 1 Apple:"))
fruits['Banana']=(int)(input("Enter the cost of 1 Banana:"))
fruits['Grapes']=(int)(input("Enter the cost of 1 Grapes:"))

wallet=(int)(input("Enter the Amount in the wallet:"))

number={'Apple':0,'Banana':0,'Grapes':0}
number['Apple']=(int)(input("Enter the number of Apples:"))
number['Banana']=(int)(input("Enter the number of Banana:"))
number['Grapes']=(int)(input("Enter the number of Grapes:"))

a=fruits['Apple']*number['Apple']
if(a>wallet):
	print("Cannot buy "+str(number['Apple'])+" of Apples")
else:
	wallet=wallet-a
	print("Bought "+str(number['Apple'])+" of Apples")
	print("Money Left: "+str(wallet))


b=fruits['Banana']*number['Banana']
if(b>wallet):
	print("Cannot buy "+str(number['Banana'])+" of Banana")
else:
	wallet=wallet-b
	print("Bought "+str(number['Banana'])+" of Banana")
	print("Money Left: "+str(wallet))

c=fruits['Grapes']*number['Grapes']
if(c>wallet):
	print("Cannot buy "+str(number['Grapes'])+" of Grapes")
else:
	wallet=wallet-c
	print("Bought "+str(number['Banana'])+" of Banana")
	print("Money Left: "+str(wallet))