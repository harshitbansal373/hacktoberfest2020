import tkinter as tk 

def play():
    x = entry_1.get()
    y = entry_2.get()
    import turtle
    import time
    import random
    root=turtle.TurtleScreen(canvas)
    root.bgcolor('black')
    root.bgpic('ladder_game_images/ladder.gif')
    cutie=turtle.RawTurtle(root)
    cutie.color(str(x))
    cutie.shape('circle')
    cutie.penup()
    cutie.speed(2)
    cutie.setposition(-230,-235)
    lutie=turtle.RawTurtle(root)
    lutie.color(str(y))
    lutie.shape('circle')
    lutie.penup()
    lutie.speed(2)
    lutie.setposition(-230,-235)

    pen=turtle.RawTurtle(root)
    pen.pensize(2)

    dice=turtle.RawTurtle(root)
    dice.color('white')
    dice.speed(0)
    dice.penup()
    dice.setposition(300,100)
    dice.hideturtle()




    position={2:[2,-179,-235],3:[3,-128,-235],4:[4,-77,-235],5:[5,-26,-235],6:[6,25,-235],7:[7,76,-235],8:[8,127,-235],9:[9,178,-235],10:[10,229,-235]
    ,11:[11,229,-184],12:[12,178,-184],13:[13,127,-184],14:[14,76,-184],15:[15,25,-184],16:[16,-26,-184],17:[17,-77,-184],18:[18,-128,-184],19:[19,-179,-184],20:[20,-230,-184]
    ,21:[21,-230,-133],22:[22,-179,-133],23:[23,-128,-133],24:[24,-77,-133] ,25:[25,-26,-133] ,26:[26,25,-133] ,27:[27,76,-133] ,28:[28,127,-133] ,29:[29,178,-133] ,30:[30,229,-133]
    ,31:[31,229,-82],32:[32,178,-82],33:[33,127,-82],34:[34,76,-82],35:[35,25,-82],36:[36,-26,-82],37:[37,-77,-82],38:[38,-128,-82],39:[39,-179,-82],40:[40,-230,-82]
    ,41:[41,-230,-31],42:[42,-179,-31],43:[43,-128,-31],44:[44,-77,-31] ,45:[45,-26,-31] ,46:[46,25,-31] ,47:[47,76,-31] ,48:[48,127,-31] ,49:[49,178,-31] ,50:[50,229,-31]
    ,51: [51, 229, 20], 52: [52, 178, 20], 53: [53, 127, 20], 54: [54, 76, 20], 55: [55, 25, 20],56: [56, -26, 20], 57: [57, -77, 20], 58: [58, -128, 20], 59: [39, -179, 20], 60: [60,-230,20]
    ,61:[61,-230,71],62:[62,-179,71],63:[63,-128,71],64:[64,-77,71] ,65:[65,-26,71] ,66:[66,25,71] ,67:[67,76,71] ,68:[68,127,71] ,69:[69,178,71] ,70:[70,229,71]
    ,71: [71, 229, 122], 72:[72, 178, 122],73: [73, 127, 122], 74: [74, 76, 122], 75: [75, 25, 122],76: [76, -26, 122],77:[77, -77, 122],78:[78, -128, 122],79: [79, -179, 122],80: [80,-230,122]
    ,81:[81,-230,173],82:[82,-179,173],83:[83,-128,173],84:[84,-77,173] ,85:[85,-26,173] ,86:[86,25,173] ,87:[87,76,173] ,88:[88,127,173] ,89:[89,178,173] ,90:[90,229,173]
    ,91:[91, 229, 224], 92:[92, 178, 224],93:[93, 127, 224],94:[94, 76, 224], 95: [95, 25, 224],96: [96, -26, 224],97:[97, -77, 224],98:[98, -128, 224],99: [99, -179, 224],100: [100,-230,224]}
    def movement(comand,pos):
        dice_number=random.randint(1,6)
        dice.write(dice_number,font=('verdana',26,'bold'))
        time.sleep(1)
        new_pos=pos+dice_number
        if(new_pos==100):
            root.clear()
            pen.write('GAME OVER',font=('Arial',26,'normal'))

        if(new_pos>100):
            if(comand==1):
                cutie.setposition(-230,224)
                time.sleep(0.5)
            if (comand == 2):
                lutie.setposition(-230, 224)
                time.sleep(0.5)
            number=new_pos-100
            new_pos=100-number
        lol=position.get(new_pos)
        return lol
    ladder_turtle={2:[38,-128, -82], 4:[14,76, -184], 9:[31,229, -82], 33:[85,-26, 173], 52:[88,127,173], 80:[99,-179, 224]}
    snake_turtle={51:[11,229,-184],56:[15,25,-184],62:[57,-77,20],92:[53,127,20],98:[8,127,-235]}
    curves={-235:229,-184:-230,-133:229,-82:-230,-31:229,20:-230,71:229,122:-230,173:229,224:-230}
    def curves_function(number,y_cod):
        bam=curves.get(y_cod)
        if(number==1):
            cutie.setposition(bam,y_cod)
            cutie.setheading(90)
            cutie.fd(51)
        else:
            lutie.setposition(bam, y_cod)
            lutie.setheading(90)
            lutie.fd(51)



    ply_1_pos=1
    ply_2_pos=1

    #game loop

    while((ply_1_pos or ply_2_pos)!=100):
        dice.clear()
        time.sleep(0.5)
        cutie_baby=turtle.RawTurtle(root)
        cutie_baby.speed(0)
        cutie_baby.penup()
        cutie_baby.turtlesize(2)
        cutie_baby.shape('square')
        cutie_baby.color(str(x))
        cutie_baby.setposition(315,200)
        time.sleep(1)

        ply_1_array=movement(1,ply_1_pos)
        if(cutie.ycor()!=ply_1_array[2]):
            curves_function(1,cutie.ycor())
        ply_1_pos=ply_1_array[0]
        cutie.setposition(ply_1_array[1],ply_1_array[2])
        time.sleep(1)
        new_ply_1_pos=ladder_turtle.get(ply_1_pos,ply_1_pos)
        if(new_ply_1_pos!=ply_1_pos):
            cutie.color('green')
            time.sleep(0.5)
            cutie.color(str(x))
            cutie.setposition(new_ply_1_pos[1],new_ply_1_pos[2])
            ply_1_pos=new_ply_1_pos[0]
            time.sleep(1)
        new_ply_1_pos = snake_turtle.get(ply_1_pos, ply_1_pos)
        if (new_ply_1_pos != ply_1_pos):
            cutie.color('red')
            time.sleep(0.5)
            cutie.color(str(x))
            cutie.setposition(new_ply_1_pos[1], new_ply_1_pos[2])
            ply_1_pos = new_ply_1_pos[0]
            time.sleep(1)
        cutie_baby.hideturtle()
        time.sleep(1)
        #2nd player

        dice.clear()
        time.sleep(0.5)
        lutie_baby = turtle.RawTurtle(root)
        lutie_baby.speed(0)
        lutie_baby.penup()
        lutie_baby.turtlesize(2)
        lutie_baby.shape('square')
        lutie_baby.color(str(y))
        lutie_baby.setposition(315, 200)
        time.sleep(1)

        ply_2_array = movement(2,ply_2_pos)
        if (lutie.ycor() != ply_2_array[2]):
            curves_function(2, lutie.ycor())
        ply_2_pos = ply_2_array[0]
        lutie.setposition(ply_2_array[1], ply_2_array[2])
        time.sleep(1)
        new_ply_2_pos = ladder_turtle.get(ply_2_pos, ply_2_pos)
        if (new_ply_2_pos != ply_2_pos):
            lutie.color('green')
            time.sleep(0.5)
            lutie.color(str(y))
            lutie.setposition(new_ply_2_pos[1], new_ply_2_pos[2])
            ply_2_pos = new_ply_2_pos[0]
            time.sleep(1)
        new_ply_2_pos = snake_turtle.get(ply_2_pos, ply_2_pos)
        if (new_ply_2_pos != ply_2_pos):
            lutie.color('red')
            time.sleep(0.5)
            lutie.color(str(y))
            lutie.setposition(new_ply_2_pos[1], new_ply_2_pos[2])
            ply_2_pos = new_ply_2_pos[0]
            time.sleep(1)
        lutie_baby.hideturtle()
        time.sleep(1)
    root.mainloop()
def quit():
    canvas.quit()

    
from tkinter import *
root=Tk()
canvas=Canvas(root,width=700,height=700)
canvas.pack(side=RIGHT)
root.config(bg='BLACK')
photo=PhotoImage(file='ladder_game_images/start.gif')
photo_1=PhotoImage(file='ladder_game_images/stop.gif')
pic=PhotoImage(file='ladder_game_images/snake.gif')
pic_1=PhotoImage(file='ladder_game_images/ladder1.gif')
label=Label(root,text='Snake n Ladder',font=('Andalus',20,'bold'),bg='black',fg='light blue',pady=50)

label.pack(side=TOP)
frame_1=Frame(root,bg='black',pady=20)
frame_1.pack(side=TOP)
label_1=Label(frame_1,text='Snake n Ladder',font=('Andalus',20,'bold'),bg='black',fg='light blue',pady=50,image=pic)
label_1.pack(side=TOP)

frame=Frame(root)
frame.pack(side=TOP)
label_1=Label(frame,text='Player 1 enter your colour ',font=('verdana',10),bg='black',fg='light green',pady=10,padx=5)
label_2=Label(frame,text='Player 2 enter your colour ',font=('verdana',10),bg='black',fg='light green',pady=10,padx=5)
entry_1=Entry(frame,bg='light grey',fg='black')
entry_2=Entry(frame,bg='light grey')
label_1.grid(row=3,column=0)
entry_1.grid(row=3,column=1)
label_2.grid(row=7,column=0)
entry_2.grid(row=7,column=1)
button_1=Button(root,text='',font=('verdana',15),image=photo,padx=50,height=100,width=100,pady=50,compound=LEFT,bg='black',command=play)
button_2=Button(root,text='',font=('verdana',15),image=photo_1,padx=30,pady=10,height=100,width=100,compound=LEFT,bg='black',command=quit)

button_1.pack(side=LEFT)
button_2.pack(side=RIGHT)
#frame_1.pack(side=LEFT)


root.mainloop()
