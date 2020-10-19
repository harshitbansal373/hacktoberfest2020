
#Enter year of birth
#Get their ages on a line
while True:
    x = 0

    a = input("input your year of birth: ")
    b = a.split()
    for i in b:
        print(2020 - int(i),  end=" ")
        print("\n")
    
    x += 1
