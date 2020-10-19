from tkinter import *

def male():
    print("Gender is Male")
def female():
    print("Gender is Female")

root=Tk()
root.title("Aman Gaud 18I5171 Lab 2 Asssignment")
root.geometry("550x650")
L1= Label(root, text="FORM").grid(row=1,column=2)
l2=Label(root,text="What is your NAME ?").grid(row=2,column=1)
l3=Label(root,text="Wat is your GENDER?").grid(row=3,column=1)
namevalue=StringVar()
name=Entry(root,text=namevalue).grid(row=2,column=2)
var = IntVar()
R1 = Radiobutton(root, text="MALE", variable=var, value=1,command=male).grid(row=4,column=1)
R2 = Radiobutton(root, text="FEMALE", variable=var, value=2,command=female).grid(row=5,column=1)

l4=Label(root,text="Which Programming Languages do you Know ?").grid(row=6,column=1)
CheckVar1 = IntVar()
CheckVar2 = IntVar()
CheckVar3 = IntVar()
CheckVar4 = IntVar()
C1 = Checkbutton(root, text = "Python", variable = CheckVar1, onvalue = 1, offvalue = 0, height=5, width = 20).grid(row=7,column=1)
C2 = Checkbutton(root, text = "Java", variable = CheckVar2, onvalue = 1, offvalue = 0, height=5, width = 20).grid(row=8,column=1)
C3 = Checkbutton(root, text = "C++", variable = CheckVar3, onvalue = 1, offvalue = 0, height=5, width = 20).grid(row=9,column=1)
C4 = Checkbutton(root, text = "Javascript", variable = CheckVar4, onvalue = 1, offvalue = 0, height=5, width = 20).grid(row=10,column=1)

def Print():
    print("Name:",namevalue.get())
    
Button(root, text="Submit", command=Print).grid(row=11, column=2)
root.mainloop()
