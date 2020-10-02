import numpy as np
import math as math
x1=np.array([0,0,1,1])
x2=np.array([0,1,0,1])
y0=np.array([0,0,0,0])
y=np.array([0,0,0,0])
n=2
for i in range (len(x1)):
    y0[i]=x1[i] and x2[i]
print(y0)
w1=int(input("Enter w1: "))
w2=int(input("Enter w2: "))
p=0
if(w1<0):
    p=p+1
if(w2<0):
    p=p+1
print("Value of p is: ")
print(p)
theta=((n*max(w1,w2))-p)
print("Value of theta is: ",theta)
for i in range (len(x1)):
    yin=(x1*w1)+(x2*w2)
print("Value of yin: ")
print(yin)
if(yin[i]>=theta):
    print("Neuron can be fired at theta= ",yin[i])
for i in range (len(x1)):
    if(yin[i]>=theta):
        y[i]=1;
print("Value of y: ")
print(y)
print("x1  x1  y0  yin  y")
for i in range (len(x1)):
    print(x1[i]," ",x2[i]," ",y0[i]," ",yin[i]," ",y[i])
if(y0[i]==y[i]):
    print("Correct weights")
