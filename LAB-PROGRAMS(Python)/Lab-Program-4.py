
import sys
file=sys.argv[1:]
wordcount={ }
for word in sys.argv[1:]:
      if word not in wordcount:
           wordcount[word]=1
      else:
           wordcount[word]+=1

for key in wordcount:
      print("Frequency of "+key+" is "+str(wordcount[key]))
