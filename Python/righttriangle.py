n=int(input("Enter the number of rows of triangle to print"))
for i in range(0,n+1):
    for j in range(0,i):
        print("*",end='')
    print("")