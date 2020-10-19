st=input("Enter String")
r=st.split(" ")
l=[]
s=" "
for i in r:
    d=list(i)
    if d[0]=='i' or d[0]=='o':
        for ele in d:
            s=s+ele
    l.append(s)
    s=" "
vowel=" ".join(l)
print(vowel)
