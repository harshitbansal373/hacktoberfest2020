# Python3 program to reverse a string 
# s = input()
#given string
s = "i.like.open.source.contribution.very.much"
words = s.split('.') 

string=[]
for x in words:
    string.insert(0,x)
result="."
result=result.join(string)
print(result)
#solution is :
#much.very.contribution.source.open.like.i
               

# Solution  by Rohan kumar 
