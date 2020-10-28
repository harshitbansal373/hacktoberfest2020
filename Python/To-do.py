from tkinter import *

root = Tk()
root.title("TO-DO")

# :title:
title = Label(root, text="TO-DO LIST",
              bg="yellow", height=2, width=43,
              font="Comfortaa 14 bold")
title.pack()

# :checkbuttons:
C1 = Checkbutton(root, text="Task1",
                 height=3, font="Comfortaa 10")
C1.pack()

C2 = Checkbutton(root, text="Task2",
                 height=3, font="Comfortaa 10")
C2.pack()

C3 = Checkbutton(root, text="Task3",
                 height=3, font="Comfortaa 10")
C3.pack()

# :geometry and runtime:
root.geometry("300x400")
root.mainloop()
