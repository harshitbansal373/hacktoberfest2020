n = int(input())
assert (n >= 0 and n <= 10 ^ 7), "n should be in range 0 ≤ n ≤ 10^7 "

def fib(n):
    a = 0
    b = 1
    for i in range(n):
        a, b = b, a + b
    return a
    
print fib(n)
