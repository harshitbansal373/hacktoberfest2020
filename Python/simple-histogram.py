# a simple program which creates a histogram based on a given amount of inputs

am = input()

i = 0
while i < am:
    numb = raw_input()
    hist = int(numb) * "*"
    print hist
    i = i + 1
