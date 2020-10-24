def bubble(L):
    for i in range(len(L)-1):
        print('\nthis is the ',i,'pass')
        time.sleep(1)
        for j in range(len(L)-1-i):
            time.sleep(1)
            print('j is',L[j],'j+1 is',L[j+1])
            if L[j]>L[j+1]:
                print('Swap hoga')
                L[j],L[j+1]=L[j+1],L[j]
                print('After swap',L)
        print('After the pass',L)
    print(L)

l=[]
n=int(input("Enter the size of array"))
for i in range(n):
    l.append(int(input()))
bubble(l)
