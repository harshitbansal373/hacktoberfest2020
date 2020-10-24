# Python program to find the largest among three numbers

# taking input from user
try:  
  num1 = float(input("Enter 1st number: "))
  num2 = float(input("Enter 2nd number: "))
  num3 = float(input("Enter 3rd number: "))

  # more efficient way using ternary operator
  largest = (num1 if (num1 > num2 and num1 > num3 ) else (num2 if (num2 > num3) else num3))
  print("The largest number is", largest)
  if num1==num2==num3:
    print('All numbers are same')
    
except ValueError as err:
  print(err)
  print('Hey, Please enter a number.')
