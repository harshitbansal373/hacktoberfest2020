l1=[]
c=0
n=int(input("enter the number of strings you want to enter:"))
for i in range(n):
	l1.append(input("enter string:"))
i=0
while i<len(l1):
	if l1.count(l1[i])>1:
		c=i+1
		for j in range(c):
			if l1[i]==l1[j]:
				del l1[j]
	else:
		i=i+1
print(l1)
