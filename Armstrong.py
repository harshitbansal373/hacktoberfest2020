'''
    1634 is an armstrong number because
    1**4+6**4+3**4+4**4 == 1634
    153 :-> 1**3 + 5**3 + 3**3

'''

num = int(input("Enter a number: "))
sum = 0
temp = num
while temp > 0:
   digit = temp % 10
   sum += digit ** len(str(num))    #power should be len of number not 3
   temp //= 10
if num == sum:
   print(num,"is an Armstrong number")
else:
   print(num,"is not an Armstrong number")
