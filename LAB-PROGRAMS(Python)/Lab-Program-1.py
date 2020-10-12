
List=(input("Enter the elements of the list with space in between them:")).split();
print("Printing Elements using for loop without Range.")
for ele in List:
	print(ele)
print("Printing Elements using for Loop with Range.")
for i in range (0,len(List)):
	print(List[i])