def sum(num1,num2):
    print(num1+num2)
def subtract(num1,num2):
    print(num1-num2)
def into(num1,num2):
    print(num1*num2)
def divide(num1,num2):
    print(num1/num2)
a=float(input("Enter the first number: "))
b=float(input("Enter the second number: "))
op=int(input(" Enter 1 for addition \n Enter 2 for substraction \n Enter 3 for multiplication \n Enter 4 for division \n Enter 5 for remainder : "))
if op==1:
    sum(a,b)
elif op==2:
    subtract(a,b)
elif op==3:
    into(a,b)
elif op==4:
    divide(a,b)
else:
    print("Please Enter a valid input!")
