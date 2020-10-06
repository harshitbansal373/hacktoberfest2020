from tkinter import *
import sqlite3
import tkinter.messagebox as tmsg


window = Tk()

#geometry section 
window.geometry("900x500+100+100")
window.minsize(200,100)
window.title("CODERNATION.COM")
window.iconbitmap('C:/Users/rk995/Downloads/myicon3.ico')

def hide():
  window.withdraw()
  
def back_to_home():
  pass

def unit1_window():
  window=Tk()
  window.title("CoderNation")
  window.geometry("900x500+100+100")
  window.minsize(200,100)
  window.iconbitmap('C:/Users/rk995/Downloads/myicon3.ico')
  label=Label(window,text="Programming Stuff",bg="orange",fg="black",relief=SUNKEN,font=("aerial",30,"bold"),width=100)
  label.pack()
  label=Label(window,text="{<code your destiny today>}",bg="black",fg="white",relief=GROOVE,font=("forte",23,"italic"),width=100)
  label.pack()

  f1=Frame(window,bg="yellow",borderwidth=10,relief=RAISED)
  f1.pack(side=LEFT,fill=Y)
 
  b1=Button(f1,text="History of python",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
  b1.pack()
  b2=Button(f1,text="features of python",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=features_window)
  b2.pack()
  b3=Button(f1,text="major use of python",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=majoruse_window)
  b3.pack()
  b3=Button(f1,text="organization using python",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=organization_window)
  b3.pack()
  b4=Button(f1,text="python syntax",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=syntax_window)
  b4.pack()
  b5=Button(f1,text="Reserve word",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=reserve_window)
  b5.pack()
  b6=Button(f1,text="python indentation",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=pythonindentation_window)
  b6.pack()
  b7=Button(f1,text="Variables",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=variables_window)
  b7.pack()
  b8=Button(f1,text="hide",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=hide)
  b8.pack()
  backbutton=Button(f1,text="Back",fg="white",bg="black",relief=RAISED,font=("aerial",15,"bold"),width=140,command=window.destroy)
  backbutton.pack(pady=3)
  

  window.mainloop()
  
    
def unit2_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.minsize(200,100)
    window.title("CoderNation")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",bg="orange",fg="black",relief=GROOVE,font=("aerial",30,"bold"))
    label.pack(fill=X)
    label1=Label(window,text="{<code your destiny today>}",fg="white",bg="black",font=("forte",23,"italic"))
    label1.pack(fill=X)
    f1=Frame(window,bg="yellow",borderwidth=8,relief=RAISED)
    f1.pack(side=LEFT,fill=Y)
    b1=Button(f1,text="Identifier",fg="white",bg="blue",font=("aerial",15,"bold"),relief=SOLID,width=140,command=identifier_window)
    b1.pack()
    b2=Button(f1,text="Testing If An Indentifier is Valid",fg="white",bg="blue",font=("aerial",15,"bold"),relief=SOLID,width=140,command=valididentifier_window)
    b2.pack()
    b3=Button(f1,text="Statement",fg="white",bg="blue",font=("aerial",15,"bold"),relief=SOLID,width=140,command=statement_window)
    b3.pack()
    b4=Button(f1,text="comments",fg="white",bg="blue",font=("aerial",15,"bold"),relief=SOLID,width=140,command=comment_window)
    b4.pack()

    backbutton=Button(f1,text="Back",fg="white",bg="black",font=("aerial",15,"bold"),relief=SOLID,width=140,command=window.destroy)
    backbutton.pack(pady=3)


    

def unit3_window():
    window=Tk()
    window.title("CODERNATION")
    window.geometry("900x500+100+100")
    window.minsize(200,100)
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')
    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE)
    label.pack(fill=X)
    label1=Label(window,text="{<code your destiny today>}",fg="white",bg="black",font=("forte",23,"italic"),relief=GROOVE)
    label1.pack(fill=X)
    label2=Label(window,text="Data types in python",fg="white",bg="#324459",font=("aerial",23,"bold"),relief=SUNKEN)
    label2.pack(fill=X)
    frame=Frame(window,bg="yellow",borderwidth=8,relief=RAISED)
    frame.pack(side=LEFT,fill=Y)

    b1=Button(frame,text="Booleans",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
    b1.pack()

    b2=Button(frame,text="Numbers",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
    b2.pack()

    b3=Button(frame,text="string",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
    b3.pack() 

    b4=Button(frame,text="List",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
    b4.pack() 

    b5=Button(frame,text="Tuples",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
    b5.pack()

    b6=Button(frame,text="SET",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
    b6.pack()
 
    b7=Button(frame,text="Dictionary",bg="#001adb",fg="white",font=("aerial",15,"bold"),relief=SOLID,width=140,command=history_window)
    b7.pack()
    backbutton=Button(frame,text="Back",fg="white",bg="black",relief=RIDGE,font=("aerial",15,"bold"),width=200,command=window.destroy)
    backbutton.pack(fill=X)



def main_window():
  window01=Tk()
  window01.geometry("900x500+100+100")
  window01.title("CODERNATION.COM")
  window01.minsize(200,100)
  window01.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

  label=Label(window01,text=" Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
  label.pack()
  f1=Frame(window01,bg="#8f5b8b",borderwidth=10,relief=RIDGE)
  f1.pack(side=LEFT,fill=Y)

  f2=Frame(window01,bg="red",borderwidth=8,width=900,relief=RIDGE)
  f2.configure(height=50)
  f2.pack(side=BOTTOM,fill=X)
  label1=Label(window01,text="{<Code your Destiny today>}",fg="white",bg="black",relief=GROOVE,font=("forte",23,"italic"))
  label1.pack(fill=X)
  label2=Label(window01,text='''Welcome 
    to 

    Python 

  World'''
    ,fg="#ffff03",bg="#2200ff",relief=GROOVE,font=("lobster",60,"bold"))
  label2.pack(fill=X)


  #buttons
  unit1button=Button(f1,text="UNIT 1",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8,command=unit1_window)
  unit1button.pack()

  unit2button=Button(f1,text="UNIT 2",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8,command=unit2_window)
  unit2button.pack()

  unit3button=Button(f1,text="UNIT 3",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8,command=unit3_window)
  unit3button.pack()

  unit4button=Button(f1,text="UNIT 4",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8)
  unit4button.pack()

  unit5button=Button(f1,text="UNIT 5",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8)
  unit5button.pack()

  unit6button=Button(f1,text="UNIT 6",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8)
  unit6button.pack()

  unit7button=Button(f1,text="UNIT 7",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8)
  unit7button.pack()

  unit8button=Button(f1,text="UNIT 8",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8)
  unit8button.pack()

  unit9button=Button(f1,text="UNIT 9",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8)
  unit9button.pack()

  unit10button=Button(f1,text="UNIT 10",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8)
  unit10button.pack()

  backbutton=Button(f2,text="Back",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8,command=window01.destroy)
  backbutton.pack()




#app function   
def history_window():
    window02=Tk()
    window02.title("CODERNATION.COM")
    window02.geometry("900x500+100+100")
    window02.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    mymenu=Menu(window02)
    m1=Menu(mymenu,tearoff=0)
    m1.add_command(label="home",command=back_to_home)
    window02.config(menu=mymenu)
    mymenu.add_cascade(label="HOME",command=main_window)

    #frames
    f1=Frame(window02,bg="grey",borderwidth=10,relief=RIDGE)
    f1.configure(height=10)
    f1.pack(side=BOTTOM,fill=X)

    #labels
    label001=Label(window02,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label001.pack()
    label002=Label(window02,text="History of Python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label002.pack(fill=X)


    label1=Label(window02,text='''The name Python was selected from "Monty Python's Flying Circus"which was a
     British sketch comedy series created by the comedy group Monty Python and broadcast by the BBC from1969 to 1974.
     Python was created in the early 1990s by Guido van Rossum at the National Research Institute for Mathematics
     and Computer Science in Netherlands. 
     Python was created as a successor of a language called ABC (All Basic Code) and released publicly in1991.
     Guido remains Python's principal author, although it includes many contributions from active user community.

     Between 1991 and 2001 there are several versions released, current stable release is 3.2.
     In 2001 the Python Software Foundation (PSF) was formed, a non-profit organization created specifically
     to own Python-related Intellectual Property. Zope Corporation is a sponsoring member of the PSF. 
     Features  ''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label1.pack(fill=X)
    

  
    backbutton=Button(f1,text="Back",fg='white',bg='black',relief=SOLID,width=140,font=("aerial",15,"bold"),command=window02.destroy)
    backbutton.pack(fill=X)






def features_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Features of Python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text='''                        ->Open source: Python is publicly available open source software, any one can use source code that doesn't cost anything. 

-> Easy-to-learn: Popular (scripting/extension) language, clear and easy syntax, no type declarations, 
    automatic memory management, high-level data types and operations, design to read (more English like syntax) 
                              and write (shorter code compared to C, C++, and Java) fast. 

    ->High-level Language: High-level language (closer to human) refers to the higher level of concept from machine 
    language (for example assembly languages). Python is an example of a high-level language like C, C++, Perl, and 
    Java with low-level optimization.

    ->Portable: High level languages are portable, which means they are able to run across all major hardware and software platforms
    with few or no change in source code. Python is portable and can be used on Linux, Windows, Macintosh, Solaris, FreeBSD, OS/2, 
    Amiga, AROS, AS/400 and many more.

                     ->Object-Oriented: Python is a full-featured object-oriented programming language, with features such as classes, inheritance, 
    and overloading.   
    ->Libraries : Databases, web services, networking, numerical packages, graphical user interfaces, 3D graphics, others

    ->Interpreted : Python programs are interpreted, takes source code as input, and then compiles (to portable byte-code) 
    each statement and executes it immediately. No need to compiling or linking''',fg="black",bg="white",font=("aerial",17),relief=GROOVE,width=100)
    label.pack(fill=X)




def majoruse_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Features of Python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=SOLID,width=140,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text=''' 
                                             
     1.System utilities (system admin tools, command line programs). 
     2.Web Development. 
     3.Graphical User Interfaces (Tkinter, gtk, Qt). 
     4.Internet scripting. 
     5.Embedded scripting. 
     6.Database access and programming. 
     7.Game programming. 
     8.Rapid prototyping and development. 
     9.Distributed programming ''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label.pack(fill=X)    



def organization_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="organization using python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=SOLID,width=140,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text=''' 
    1.Web Development : Yahoo Maps, Yahoo Groups, Google, Zope Corporation, Ultraseek, Linux Weekly News,ElasticHosts Cloud
    Mojam.com, hunch, Shopzilla, Movieplayer.it, Multiplayer.it. 

    2.Games: Battlefield 2, Crystal Space, Star Trek Bridge Commander, The Temple of Elemental Evil, Vampire: The Masquerade: 
    Bloodlines, Civilization 4, QuArK (Quake Army Knife) 

    3.Graphics : Industrial Light & Magic, Walt Disney Feature Animation, HKS, Inc. (ABAQUS/CAE), RoboFog, Caligari Corporation,
    Blender 3D, Jasc Software, Paint Shop Pro. 

    4.Financial : Altis Investment Management, ABN AMRO Bank, Treasury Systems, Bellco Credit Union, Journyx Timesheet and Resource
    Management Software. 

    5.Science : National Weather Service, Radar Remote Sensing Group, Applied Maths, Biosoft, The National Research Council of Canada, 
    Los Alamos National Laboratory (LANL) Theoretical Physics Division, AlphaGene, Inc., LLNL, NASA, Swedish Meteorological and 
    Hydrological Institute (SMHI), Environmental Systems Research Institute (ESRI), Objexx Engineering, Nmag Computational 
    Micromagnetics 

    6.Electronic Design Automation: Ciranova, Productivity Design Tools, Object Domain, Pardus, Red Hat, SGI, Inc., 
    MCI Worldcom, Nokia.

    7.Education : University of California, Irvine, Smeal College of Business, The Pennsylvania State University, 
    New Zealand Digital Library, IT Certification Exam preparation, SchoolTool.

    8.Business Software : Raven Bear Systems Corporation, Thawte Consulting, Advanced Management Solutions Inc., M, Arakn<E9>,
    RealNetworks, dSPACE, Escom, The Tiny Company, Nexedi, Piensa Technologies - Bufete Consultor de Mexico, Nektra, 
    WuBook. ''',fg="black",bg="white",font=("aerial",13),relief=GROOVE,width=100)
    label.pack(fill=X)  




def pythonindentation_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="python indentation",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text=''' 
    Indentation refers to the spaces at the beginning of a code line. Where in other programming languages the 
    indentation in code is for readability only, the indentation in Python is very important. Python uses 
    indentation to indicate a block of code. 
    ex if 5 > 2:
                                                   print("Five is greater than two!") 
 
    Python will give you an error if you skip the indentation. 
    Syntax Error if 5 > 2: 
                                                         print("Five is greater than two!")''',fg="black",bg="white",font=("aerial",13),relief=GROOVE,width=100)
    label.pack(fill=X)      
    


def variables_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Variables in  Python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text=''' 
    Variables are nothing but reserved memory locations to store values. This means that when you create a variable 
    you reserve some space in memory. 
    Based on the data type of a variable, the interpreter allocates memory and decides what can be stored in the 
    reserved memory. 
    Therefore, by assigning different data types to variables, you can store integers, decimals or characters in these variables 
    we can easily assigning  a values to the different variale.example
    x=19 #int value
    x=19.87 #float value
    x="python is damn easy" #string value 
    Assign same value to multiple variables.example
    a=b=c=d=10
    a,b,c=12,23,"rohan" ''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label.pack(fill=X)    






def syntax_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Syntax importance in Python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text='''When writing code, using correct syntax is super important.
       Even a small typo, like a missing parentheses or an extra comma, can cause a syntax error
       and the code won't execute at all. Yikes. If your code results in an error or an exception,
       pay close attention to syntax and watch out for minor mistakes.

       If your syntax is correct, but the script has unexpected behavior or output, this may be due
       to a semantic problem. Remember that syntax is the rules of how code is constructed, while
       semantics are the overall effect the code has. It is possible to have syntactically correct
       code that runs successfully, but doesn't do what we want it to do.

       When working with the code blocks in exercises for this course, be mindful of syntax errors,
       along with the overall result of your code. Just because you fixed a syntax error doesn't mean
       that the code will have the desired effect when it runs! Once you’ve fixed an error in your code,
       don't forget to submit it to have your work checked 

       Python syntax can be executed by writing directly in the Command Line: 
       >>> print("Hello, World!") 
       Output=Hello, World
       >>> print('hello, world ')
       Output=hello, world''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label.pack(fill=X)


def reserve_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Reserve word & keyword",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text='''
    The following list shows the Python keywords. These are reserved words and you cannot use them as constant or 
    variable or any other identifier names.All the Python keywords contain lowercase letters only. 

And            exec          not 
Assert        finally         or 
Break          for           pass 
Class         from          print 
Continue      global        raise 
Def            if          return 
Del          import         try 
Elif          in           while 
Else          is            with 
Except       lambda         yield ''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label.pack(fill=X)




def string_window():
    window03=Tk()
    window03.geometry("900x500+100+100")
    window03.title("CODERNATION.COM")
    window03.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label001=Label(window03,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label001.pack()
    label002=Label(window03,text="String in Python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label002.pack(fill=X)
    f2=Frame(window03,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    f2.configure(height=50)
    f2.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label01=Label(window03,text='''You can do this by using square brackets and the location, or index,
      of the character you want to access. 
      It's important to remember that Python starts indexes at 0. So to access the first character in a string,
      you would use the index [0]. If you try to access an index that’s larger than the length of your string, 
      you’ll get an IndexError. This is because you’re trying to access something that doesn't exist! You can 
      also access indexes from the end of the string going towards the start of the string by using negative values.
      The index [-1] would access the last character of the string, and the index [-2] would access the second-to-last.
      character ''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label01.pack(fill=X)




def identifier_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Identifiers in python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=45)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text=''' 
    Python Identifiers are user-defined names to represent a variable, function, class, module or any other object. If you 
    assign some name to a programmable entity in Python, then it is nothing but technically called an identifier. 
    Python language lays down a set of rules for programmers to create meaningful identifiers.
    Giudelines for creating identifier in python.

    1. To form an identifier, use a sequence of letters either in lowercase (a to z) or uppercase (A to Z). However, you can
    also mix up digits (0 to 9) or an underscore (_) while writing an identifier. For example – Names like shapeClass, shape_1,
    and upload_shape_to_db are all valid identifiers.

    2. You can’t use digits to begin an identifier name. It’ll lead to the syntax error. For example – The name, 0Shape is 
    incorrect, but shape1 is a valid identifier.

    3. Also, the Keywords are reserved, so you should not use them as identifiers.
    >>> for=1 SyntaxError: invalid syntax >>> True=1 SyntaxError: can't assign to keyword 

    4. Python Identifiers can also not have special characters [‘.’, ‘!’, ‘@’, ‘#’, ‘$’, ‘%’] in their formation. These symbols
    are forbidden. >>> @index=0 SyntaxError: invalid syntax >>> isPython?=True SyntaxError: invalid syntax 

    5. Python doc says that you can have an identifier with unlimited length. But it is just the half truth. Using a large name 
    (more than 79 chars) would lead to the violation of a rule set by the (Python Enhancement Proposal) PEP-8 standard. It says.
    Limit all lines to a maximum of 79 characters''',fg="black",bg="white",font=("aerial",17),relief=GROOVE,width=100)
    label.pack(fill=X) 
    


def valididentifier_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Features of Python",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text=''' 
    You can test whether a Python identifier is valid or not by using the keyword.iskeyword() function. 
    It returns “True” if the keyword is correct or “False” otherwise. Please refer the below snippet
    >>> import keyword 
    >>> keyword.iskeyword("techbeamers") 
    False 
    >>> keyword.iskeyword("try") 
    True 
    Another useful method to check if an identifier is valid or not is by calling the str.isidentifier() function.
    But it is only available in Python 3.0 and onwards. 
    True ''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label.pack(fill=X)


def statement_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="Python statements",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text=''' 
    What Is A Statement? 
    A statement in Python is a logical instruction which Python interpreter can read and execute. In Python, 
    it could be an expression or an assignment statement. 
    The assignment statement is fundamental to Python. It defines the way an expression creates objects and 
    preserve them.
    What Is An Expression? 
    An expression is a type Python statement which contains a logical sequence of numbers, strings, objects,
    and operators. The value in itself is a valid expression and so is a variable. 
    Using expressions, we can perform operations like addition, subtraction, concatenation and so on. It can 
    also have a call to a function which evaluates results. 
    Examples 
    # Using Arithmetic expressions 
    >>> ((10 + 2) * 100 / 5 - 200) 
    40.0 
    # Using functions in an expression 
    >>> pow(2, 10) 
    1024 
    # Using eval in an expression 
    >>> eval( "2.5+2.5" ) 
    5.0 ''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label.pack(fill=X) 



def comment_window():
    window=Tk()
    window.geometry("900x500+100+100")
    window.title("CODERNATION.COM")
    window.iconbitmap('C:/Users/rk995/Downloads/myicon2.ico')

    label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
    label.pack()
    label=Label(window,text="comment",bg="#324459",fg="white",font=("aerial",23,"bold"),relief=SUNKEN)
    label.pack(fill=X)
    frame=Frame(window,bg="grey",borderwidth=8,width=900,relief=RIDGE)
    frame.configure(height=50)
    frame.pack(side=BOTTOM,fill=X)
    backbutton=Button(frame,text="Back",fg='white',bg='black',relief=RAISED,font=("aerial",15,"bold"),command=window.destroy)
    backbutton.pack(fill=X)
    label=Label(window,text='''
    Single line python comment  
    You  use a single line Python comment when there is need of short, quick comments for debugging. 
    Single-line comments begin with a pound (#) symbol that's called hash.

    # Every thing has code behind it!. 
      print("Learn Python Step by Step!") 
    While putting a comment, make sure your comment is at the sameindent level as the code beneath it.

    #define list of friends with 3 arg.
      friends=["Rohan","vipin","udit"]
    def showmyfriends_list(friends):
for x in friends:
    print(x)
  showmyfriends_list(friends)

  Rohan
  vipin
  udit''',fg="black",bg="white",font=("aerial",17,"bold"),relief=GROOVE,width=100)
    label.pack(fill=X)



#first window elements     

label=Label(window,text="Programming Stuff",fg="black",bg="orange",font=("aerial",30,"bold"),relief=GROOVE,width=100)
label.pack()
label1=Label(window,text="{<Code your Destiny today>}",fg="white",bg="black",relief=GROOVE,font=("forte",23,"italic"))
label1.pack(fill=X)

label2=Label(window,text="Welcome to Programming world",fg="black",bg="#b1fc03",relief=GROOVE,font=("forte",50,"bold"))
label2.pack(fill=X)

label3=Label(window,text="Take a single step towards coding world",fg="black",bg="#fc5a03",relief=GROOVE,font=("lobster",50,"bold"))
label3.pack(fill=X)


label3=Label(window,text='''
Just click on the 
NEXT
Button''',fg="black",bg="#03fc67",relief=GROOVE,font=("aerial",50,"bold"))
label3.pack(fill=X)


f2=Frame(window,bg="red",borderwidth=8,width=900,relief=RIDGE)
f2.configure(height=50)
f2.pack(side=BOTTOM,fill=X)

#buttons
nextbutton=Button(f2,text="NEXT",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8,command=main_window)
nextbutton.pack()

exitbutton=Button(f2,text="EXIT",fg="black",bg="yellow",font=("aerial",12,"bold"),relief=SOLID,width=8,command=window.destroy)
exitbutton.pack()


        


window.mainloop()
