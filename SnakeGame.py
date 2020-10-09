import turtle
import time
import random


delay = 0.1
queue =[]

#Calculate the score and high score
pen = turtle.Turtle()
pen.shape('square')
pen.penup()
pen.speed(0)
pen.color('White')

pen.hideturtle()
pen.goto(0,210)
pen.write("Score: 0    High score: 0   ",align='center',font=('Arial',25,'bold'))


# First , we create the snake window
window = turtle.Screen()
window.bgcolor('Black')
window.title('Snake_Game by Mariam Mostafa')
window.setup(width=600,height=500)
window.tracer(0)

#Next, we will create the snake head
Snake_Head = turtle.Turtle()
Snake_Head.speed(0)
Snake_Head.shape('circle')
Snake_Head.color('Beige')
Snake_Head.penup()
Snake_Head.goto(0,0) # by default it is in the center of the screen
Snake_Head.direction ='stop'

#Next, we will create the snake food
Snake_Food = turtle.Turtle()
Snake_Food.speed(0)
Snake_Food.shape('circle')

Snake_Food.color('green')
Snake_Food.penup()
Snake_Food.goto(0,150) # by default it is in the center of the screen



########################################################################
# Then , we will create all functions that we need to make snake move
def Move_Snake():
    if Snake_Head.direction == 'up':
        y = Snake_Head.ycor()
        Snake_Head.sety(y + 10)
    if Snake_Head.direction == 'down':
        y = Snake_Head.ycor()
        Snake_Head.sety(y - 10)
    if Snake_Head.direction == 'left':
        x = Snake_Head.xcor()
        Snake_Head.setx(x - 10)
    if Snake_Head.direction == 'right':
        x = Snake_Head.xcor()
        Snake_Head.setx(x + 10)


def go_up():
    Snake_Head.direction = 'up'


def go_down():
    Snake_Head.direction = 'down'


def go_left():
    Snake_Head.direction = 'left'


def go_right():
    Snake_Head.direction = 'right'


def Food_Collision():
    if Snake_Head.distance(
            Snake_Food) < 15:  # I choose 10 or 15 based on the incremental that we use to make the snakehead move
        Snake_Food.goto(random.randint(-290, 290), random.randint(-249, 249))
        """ here we use random numbers in order to move the snake food. that range because of the width and the height of the screen   """
        Snake_body = turtle.Turtle()  # after eating the food the snake became bigger so i create one more turtle and add all in list
        Snake_body.speed(0)
        Snake_body.shape('circle')
        Snake_body.color('yellow')
        Snake_body.penup()
        queue.append(Snake_body)
        return True
    return False


def Border_Collision():
    # Border collision
    if Snake_Head.xcor() > 290 or Snake_Head.xcor() < -290 or Snake_Head.ycor() > 249 or Snake_Head.ycor() < -249:
        time.sleep(1)
        Snake_Head.goto(0, 0)
        Snake_Head.direction = 'stop'
        for segment in queue:
            segment.goto(1000, 1000)
        queue.clear()
        return True

    return False
def Body_Collision():
    # body collisions
    for segment in queue:
        if segment.distance(Snake_Head) < 10:  # overlapping
            time.sleep(1)
            Snake_Head.goto(0, 0)
            Snake_Head.direction = 'stop'
            for segment in queue:
                segment.goto(1000, 1000)
            queue.clear()
            return True
    return False


def Add_Snake_Body():
    # add body to the snake because i don't know the length so i iterate from the last one in the list
    for i in range(len(queue) - 1, 0, -1):
        if i % 5 == 0:
            queue[i].goto(queue[i - 1].xcor(), queue[i - 1].ycor())
            queue[i].color('green')
            continue
        queue[i].goto(queue[i - 1].xcor(), queue[i - 1].ycor())
    if len(queue) > 0:
        queue[0].goto(Snake_Head.xcor(), Snake_Head.ycor())



# after that , i want to direct the snake head by using the keyboard so i should use keyboard bindings  so we use listen function in order to listen to the keypress
window.listen()
window.onkeypress(go_up, 'Up')
window.onkeypress(go_down, 'Down')
window.onkeypress(go_left, 'Left')
window.onkeypress(go_right, 'Right')

####################################################################################
    # Game loop
score = 0
High_Score = 0
while True:

    window.update()
    Move_Snake()
    if Food_Collision():
        score += 10
        High_Score += 10
        if score > High_Score:
            High_Score = score
        pen.clear()
        pen.write('Score:{}    High score:{}  '.format(score, High_Score), align='center', font=('Arial', 25, 'bold'))

    if Body_Collision() or Border_Collision():
        score = 0
        pen.clear()
        pen.write('Score:{}    High score:{}  '.format(score, High_Score), align='center', font=('Arial', 25, 'bold'))
    time.sleep(delay)
    Add_Snake_Body()


# this keep the window open
window.mainloop()
=======
import math
import random
import pygame
import random
import tkinter as tk
from tkinter import messagebox

width = 500
height = 500

cols = 25
rows = 20


class cube():
    rows = 20
    w = 500
    def __init__(self, start, dirnx=1, dirny=0, color=(255,0,0)):
        self.pos = start
        self.dirnx = dirnx
        self.dirny = dirny # "L", "R", "U", "D"
        self.color = color

    def move(self, dirnx, dirny):
        self.dirnx = dirnx
        self.dirny = dirny
        self.pos  = (self.pos[0] + self.dirnx, self.pos[1] + self.dirny)
            

    def draw(self, surface, eyes=False):
        dis = self.w // self.rows
        i = self.pos[0]
        j = self.pos[1]
        
        pygame.draw.rect(surface, self.color, (i*dis+1,j*dis+1,dis-2,dis-2))
        if eyes:
            centre = dis//2
            radius = 3
            circleMiddle = (i*dis+centre-radius,j*dis+8)
            circleMiddle2 = (i*dis + dis -radius*2, j*dis+8)
            pygame.draw.circle(surface, (0,0,0), circleMiddle, radius)
            pygame.draw.circle(surface, (0,0,0), circleMiddle2, radius)
        


class snake():
    body = []
    turns = {}
    
    def __init__(self, color, pos):
        #pos is given as coordinates on the grid ex (1,5)
        self.color = color
        self.head = cube(pos)
        self.body.append(self.head)
        self.dirnx = 0
        self.dirny = 1
    
    def move(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            keys = pygame.key.get_pressed()

            for key in keys:
                if keys[pygame.K_LEFT]:
                    self.dirnx = -1
                    self.dirny = 0
                    self.turns[self.head.pos[:]] = [self.dirnx,self.dirny]
                elif keys[pygame.K_RIGHT]:
                    self.dirnx = 1
                    self.dirny = 0
                    self.turns[self.head.pos[:]] = [self.dirnx,self.dirny]
                elif keys[pygame.K_UP]:
                    self.dirny = -1
                    self.dirnx = 0
                    self.turns[self.head.pos[:]] = [self.dirnx,self.dirny]
                elif keys[pygame.K_DOWN]:
                    self.dirny = 1
                    self.dirnx = 0
                    self.turns[self.head.pos[:]] = [self.dirnx,self.dirny]
        
        for i, c in enumerate(self.body):
            p = c.pos[:]
            if p in self.turns:
                turn = self.turns[p]
                c.move(turn[0], turn[1])
                if i == len(self.body)-1:
                    self.turns.pop(p)
            else:
                c.move(c.dirnx,c.dirny)
        
        
    def reset(self,pos):
        self.head = cube(pos)
        self.body = []
        self.body.append(self.head)
        self.turns = {}
        self.dirnx = 0
        self.dirny = 1

    def addCube(self):
        tail = self.body[-1]
        dx, dy = tail.dirnx, tail.dirny

        if dx == 1 and dy == 0:
            self.body.append(cube((tail.pos[0]-1,tail.pos[1])))
        elif dx == -1 and dy == 0:
            self.body.append(cube((tail.pos[0]+1,tail.pos[1])))
        elif dx == 0 and dy == 1:
            self.body.append(cube((tail.pos[0],tail.pos[1]-1)))
        elif dx == 0 and dy == -1:
            self.body.append(cube((tail.pos[0],tail.pos[1]+1)))

        self.body[-1].dirnx = dx
        self.body[-1].dirny = dy
    
    def draw(self, surface):
        for i,c in enumerate(self.body):
            if i == 0:
                c.draw(surface, True)
            else:
                c.draw(surface)



def redrawWindow():
    global win
    win.fill((0,0,0))
    drawGrid(width, rows, win)
    s.draw(win)
    snack.draw(win)
    pygame.display.update()
    pass



def drawGrid(w, rows, surface):
    sizeBtwn = w // rows

    x = 0
    y = 0
    for l in range(rows):
        x = x + sizeBtwn
        y = y +sizeBtwn

        pygame.draw.line(surface, (255,255,255), (x, 0),(x,w))
        pygame.draw.line(surface, (255,255,255), (0, y),(w,y))
    


def randomSnack(rows, item):
    positions = item.body

    while True:
        x = random.randrange(1,rows-1)
        y = random.randrange(1,rows-1)
        if len(list(filter(lambda z:z.pos == (x,y), positions))) > 0:
               continue
        else:
               break

    return (x,y)


def main():
    global s, snack, win
    win = pygame.display.set_mode((width,height))
    s = snake((255,0,0), (10,10))
    s.addCube()
    snack = cube(randomSnack(rows,s), color=(0,255,0))
    flag = True
    clock = pygame.time.Clock()
    
    while flag:
        pygame.time.delay(50)
        clock.tick(10)
        s.move()
        headPos = s.head.pos
        if headPos[0] >= 20 or headPos[0] < 0 or headPos[1] >= 20 or headPos[1] < 0:
            print("Score:", len(s.body))
            s.reset((10, 10))

        if s.body[0].pos == snack.pos:
            s.addCube()
            snack = cube(randomSnack(rows,s), color=(0,255,0))
            
        for x in range(len(s.body)):
            if s.body[x].pos in list(map(lambda z:z.pos,s.body[x+1:])):
                print("Score:", len(s.body))
                s.reset((10,10))
                break
                    
        redrawWindow()

main()
