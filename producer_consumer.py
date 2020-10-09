
def producer(i):
	global Buflist, mutex,pronum
	mutex = wait(mutex)
	Buflist.append(i)
	mutex = signal(mutex)
	pronum=pronum+1
	print("\n\nProduced process number is: ",pronum)
	
def consumer(i):
	global Buflist,mutex,connum
	mutex = wait(mutex)
	value = Buflist.pop(Buflist.index(i))
	mutex = signal(mutex)
	connum=connum+1
	print("\n\nConsumed process number is: ",connum)

def wait(w):
		while(w<0):
			pass
		w-=1
		return(w)
def signal(s):
		s+=1
		return(s)
	
n = int(input("Enter the buffer size: "))
Buflist= []
mutex = 1
pronum=0
connum=0
while(1):
	print("\n1.Produce\n2.Consume\n3.Exit:\n")
	choice = int(input("Enter: "))
	if(choice==1):
		if(mutex==1 and len(Buflist)!=n):
			producer(1)
			
			

		else:
			print("\nBuffer is now full\n")
	elif(choice==2):
		if(mutex==1 and len(Buflist)!=0):
			consumer(1)
		else:
			print("\nBuffer is now empty\n")

	elif(choice==3):
		display()
	else:
		exit()