'''
Input : 
      two integer with space in between
OutPut : 
        LCM of the number
'''
a, b = input().split(" ")
a = int(a)
b = int(b)
assert (a >= 0 and b >= 0), "a,b should be >= 0"


def lcm(a, b):

    if (a > b):
        for i in range(a, a * b + 1):
            if (i % a == 0 and i % b == 0):
                best = i

    return best


print (lcm(a, b))
