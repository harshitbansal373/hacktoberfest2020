print('----Sieve of Eratosthenes----')
n=int(input('Enter the limit Number: '))
arr=[True ]*n

def seive():
    global arr
    global n
    i=2
    while(True):
        if(i**2>=n):
            return
        if arr[i-1]:
            temp=i*2
            while(temp<=n):
                arr[temp-1]=False
                temp=temp+i
        i+=1
        
seive()
print('Prime Numbers:')
for i in range(2,n):
    if arr[i-1]:
        print(i,end=" ")
