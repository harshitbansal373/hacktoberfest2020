def isprime(x):
    prime = True
    if x ==2:
        prime = True
        return prime
    if x%2 == 0 :
        prime= False
        return prime
    for y in range(3,x,2):
        if x%y ==0:
            prime = False
    return prime

num=int(input("enter number:"))
print(isprime(num))
