num=int(input("enter number:"))
if num==1:
    Print("1 is neither a prime number nor a composite number")
else:
    count=0
    for i in range(1,num+1):
        if num%i==0:
            count=count+1
    if count<=2:
        print("prime number")
    else:
        print("composite number")
