x=int(input())
num=[]
while int(x)>0:
    r=int(x)%2
    x=int(x)/2
    num.append(r)
num.reverse()
result=''.join(str(x) for x in num)
print(result)


