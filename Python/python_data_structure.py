name = input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
handle = open(name)
count=dict()
lines=list()
for line in handle:
    line=line.rstrip()
    if not line.startswith("From"):
        continue
    if not line.startswith("From:"):
        continue
    else:
        words=line.split()
        lines.append(words[1])
                    
for name in lines:
    count[name]=count.get(name,0)+1;        
      
bigword=None
bigcount=None
for word,count in count.items():
    if bigcount==None or bigcount<count:
        bigword=word
        bigcount=count
print(bigword,bigcount)







