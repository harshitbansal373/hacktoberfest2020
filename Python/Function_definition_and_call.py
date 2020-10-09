#Write functions for addition, subtraction, multiplication and division of all numbers from a list and print the final results of each function. In your main program, ask for number of elements, and actual elements of the list. Pass the list to each function call of arithmetic operations.

N=int(input("Enter N: "))
L1=[]
I=0
def add(L1):
    sum = L1[0]
    elements = 1
    while (elements < len(L1)):
        sum = sum + L1[elements]
        elements += 1
    print("Sum Of Given Numbers In List Are: ", sum)


def subtract(L1):
    sub = L1[0]
    elements = 1
    while (elements < len(L1)):
        sub = sub - L1[elements]
        elements += 1
    print("Subtraction Of Given Numbers In List Are: ",sub)

def multiply(L1):
    mul = L1[0]
    elements = 1
    while (elements < len(L1)):
        mul = mul * L1[elements]
        elements += 1
    print("Multiplication of Given Numbers In List Are : ", mul)
    
def division(L1):
    div = L1[0]
    elements = 1
    while (elements < len(L1)):
        div = div / L1[elements]
        elements += 1
    print("Division of Given Numbers In List Are : ", div)

for I in range(0,N):
    elements=int(input())
    L1.append(elements)
print(L1)

add(L1)
subtract(L1)
multiply(L1)
division(L1)
