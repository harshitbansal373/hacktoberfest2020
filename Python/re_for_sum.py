import re

handle = input('Enter text file name for count sum: ')
name = open(handle)
lst = list()
for line in name :
    num = re.findall('[0-9]+', line)
    for i in num :
        if len(i) >= 1 :
            n = int(i)
            lst.append(n)
print(lst)
print(sum(lst))
