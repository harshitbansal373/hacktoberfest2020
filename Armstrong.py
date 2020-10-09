print("Armstrong number checker(within interval)")
print("**Here you can check Armstrong numbers available within your desired interval**")
no_range = list(map(int,input('Enter range').split()))

print("Armstrong numbers between",no_range[0],"&",no_range[1],"is: \n")
for num in range(no_range[0], no_range[1] + 1):
   # initialize sum
    sum = 0
    temp = num
    while temp > 0:
        digit = temp % 10
        sum += digit ** 3
        temp //= 10
    if sum == num:
        print(num)
