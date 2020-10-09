def compute_hcf(x, y):

# choose the smaller number
    if x > y:
        smaller = y
    else:
        smaller = x
    for i in range(1, smaller+1):
        if((x % i == 0) and (y % i == 0)):
            hcf = i 
    return hcf

num1 = int(input("enter a number : ") 
num2 = int(input("enter a number : ")

print("The H.C.F. is", compute_hcf(num1, num2))
