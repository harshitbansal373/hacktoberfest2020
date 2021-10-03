import sys


def c_pattern(z):
    pattern = ''
    for i in range (65,91):
        pattern += pattern.join(chr(i))+str(chr(97))+str(chr(97))+str(chr(97))    

    pattern = pattern[:z]
    
    return pattern


def repeat(y):
    z = y
    string = str(c_pattern(z))
    while(len(string) < z):
        string += string

    print(len(string))
    print(string)
    

    return string
if __name__ == '__main__':
    try:
        repeat(int(sys.argv[1]))
    except:
        print("[*] Please enter the size of the pattern !!!\n\n\n")