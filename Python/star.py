# Pattern Printing
# Input = Integer n
# Boolean = True or False
#
# True n=5
# *
# **
# ***
# ****
#
# False n=5
# ****
# ***
# **
# *

a = int(input("Please add number of line you want to print:"))
b = bool(int(input("True : 1\nFalse : 0\n:")))


def star(a, b):
    if b == True:
        c = 1
        while c <= a:
            print(c * "*")
            c = c + 1
    else:
        while a > 0:
            print(a * "*")
            a = a - 1


star(a, b)
  