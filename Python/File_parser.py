#parse a file and return a list with numbers only, discard if the line starts with text
def parser(filename):
  lines = []
  num_list = []
  fh = None
  try:
    fh = open(filename, encoding = "utf8")
    lines = fh.readlines()
    num_lines = len(lines)
    #print(num_lines) #-> checking how many lines get printed, remove # before print
    i = 0
    while i < num_lines:
        line = lines[i].strip()

        #print (type(line)) #-> checking each line type() that was read in lines variable above,whether it's an integer or string remove # before print, you might notice even a number from a file is read as string
        # this means we cannot apply a logic where we identify if in a given line there is a number or letter, we might need to use regex
        if line.isdigit():
            print ('Hurray! Found a number')
            #print(line)  # -> each line that was read in lines variable above, remove # before print
            num_list.append(line)
        else:
            pass
            #print(line)  # -> each line that was read in lines variable above, remove # before print
        i+=1

  except (IOError, OSError):
    print("FileNotFound")
  finally:
    if fh is not None:
      fh.close()
    else:
        print ('Input file is empty')
    return num_list

print (parser('<path to file>/d1.txt'))
