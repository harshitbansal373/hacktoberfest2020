from tkinter import *
root=Tk()
root.title('My Calculator')
root.config(bg='gainsboro')

list=[]

e=Entry(root,bg='azure',fg='black',font='times 35 italic',justify='right')
e.grid(row=0,column=0,padx=5,pady=5,sticky='nswe',columnspan=4) #columnspan imp in grid for giving size of two or more buttons

l=['C','DEL']

def Display1(event):
    b['bg']='sky blue'
def Display2(event):
    b['bg']='gray66'

for i in range(0,4,2):
    b=Button(root,text=l.pop(),bg='gray70',fg='black',font='times 20 ')
    b.grid(row=1,column=i,padx=5,pady=5,sticky='nswe',columnspan=2)

l1=['789/','456X','123=','.0+-']

for i in range(4):
    for j in range(4):
        list.append(Button(root,text=l1[i][j],bg='gray66',fg='black',font='times 20 bold',commad=lambda x=l[i][j]:Display(x)))
        list[-1].grid(row=i+2,column=j,padx=5,pady=5,sticky='nswe')

for i in range(7):
    root.grid_rowconfigure(i,weight=1)
for j in range(4):
    root.grid_columnconfigure(j,weight=1)
root.mainloop()
