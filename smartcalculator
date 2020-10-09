from tkinter import *
import math

def add(a,b):
    return a + b

def sub(a,b):
    return a - b

def mul(a,b):
    return a * b

def div(a,b):
    return a / b

def mod(a,b):
    return a % b

def lcm(a,b):
    L = a if a>b else b
    while L <= a*b:
        if L%a == 0 and L%b == 0:
            return L
        L+=1

def hcf(a,b):
    H = a if a<b else b
    while H >= 1:
        if a%H == 0 and b%H == 0:
            return H
        H-=1

def sqrt(a):
    return math.sqrt(a)

def square(a):
    return a**2

def cube(a):
    return a**3

def sin(x):
    return math.sin(math.pi*x/180)

def cos(x):
    return math.cos(math.pi*x/180)

def tan(x):
    return math.tan(math.pi*x/180) 

def fact(x):
    return math.factorial(int(x))


def extract_from_text(text):
    l = []
    for t in text.split(' '):
        try:
            l.append(float(t))
        except ValueError:
            pass
    return l

def calculate():
    text = textin.get()
    for word in text.split(' '):
        if word.upper() in operations.keys():
            try:
                l = extract_from_text(text)
                if len(l)>1:
                   r = operations[word.upper()](l[0] , l[1])
                else:
                    r = operations[word.upper()](l[0])
                list.delete(0,END)
                list.insert(END,r)
            except:
                list.delete(0,END)
                list.insert(END,'something went wrong\nplease enter again')
            finally:
                break
        elif word.upper() not in operations.keys():
            list.delete(0,END)
            list.insert(END,'something went wrong\nplease enter again')

operations = {'ADD':add , 'ADDITION':add ,'+':add, 'SUM':add , 'PLUS':add ,
                'SUB':sub , 'DIFFERENCE':sub , 'MINUS':sub ,'-':sub, 'SUBTRACT':sub,
                 'LCM':lcm , 'HCF':hcf , 'PRODUCT':mul , 'MULTIPLICATION':mul,
                 'MULTIPLY':mul ,'X':mul, 'DIVISION':div , 'DIV':div ,'DIVIDE':div,'/':div, 'MOD':mod ,
                  'REMAINDER':mod , 'MODULUS':mod ,'ROOT':sqrt ,'SQUARE':square,'CUBE':cube,'SIN':sin,
                  'COS':cos,'TAN':tan, 'TANGENT':tan, 'FACTORIAL':fact , 'FACT':fact}

win = Tk()
win.geometry('500x280')
win.title("Ankhi's Smart Calculator")
win.configure(bg='lightskyblue')

l1 = Label(win , text='Ankhi is smart enough to calculate.',width=27,padx =3)
l1.place(x=150,y=15)
l2 = Label(win , text='Hope,you are interested!' , padx=3)
l2.place(x=180,y=45)
l3 = Label(win , text='What can I help you?' , padx=3)
l3.place(x=180,y=120)

textin = StringVar()
e1 = Entry(win , width=30 , textvariable = textin)
e1.place(x=160,y=160)

b1 = Button(win , text='Just this' ,command=calculate)
b1.place(x=210,y=190)

list = Listbox(win,width=27,height=2)
list.place(x=170,y=230)

win.mainloop()
