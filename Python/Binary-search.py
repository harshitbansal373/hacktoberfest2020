def b(a,x,l,h):
    mid=(l+h)//2
    if(l>h):
        return 0
    elif(x==a[mid]):
        return mid
    elif x>a[mid]:
        return b(a,x,mid+1,h) 
    else:
        return b(a,x,l,mid-1)
    

n=int(input("Enter the size of array:"))
a=input("Enter the elements in space separated form:").split()
a=[int(x) for x in a]
x=int(input("Enter the element to be searched:"))
low=0
high=len(a)-1
if(b(a,x,low,high)):
    print("\nThe element is found at index:",b(a,x,low,high))
else:
    print("\nElement not found")
