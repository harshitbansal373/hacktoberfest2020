print("Armstrong number checker(within interval)")
print()

print()

print("**Here you can check Armstrong numbers available within your desired interval**")

print()

print()
l_range = int(input("Enter a lower range of your interval: "))
u_range=int(input("Enter a upper range of your interval: "))

for num in range(l_range, u_range + 1):

   # order of number
   order = len(str(num))
    
   # initialize sum
   sum = 0

   temp = num
   while temp > 0:
       digit = temp % 10
       sum += digit ** order
       temp //= 10

   if num == sum:
       print("Armstrong numbers between",l_range,"&",u_range,"is: \n")
       print(num)
   
