S="farmer jack realized that big yellow quilts were expensive"
s2="a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z"
c=0
for i in s2:
    if i in S:
        c+=1
if c==26:
    print("is pangram")
else:
    print("not panagram")
