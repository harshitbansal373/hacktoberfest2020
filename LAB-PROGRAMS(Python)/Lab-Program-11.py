
import pygame

import math

import sys

pygame.init()

#setting screen size

screen = pygame.display.set_mode((600, 300)) 

#setting caption

pygame.display.set_caption("Elliptical orbit")

#creating clock variable

clock=pygame.time.Clock() 

while(True):

    for event in pygame.event.get():

        if event.type == pygame.QUIT:

            sys.exit()

# setting x and y radius of ellipse    

    xRadius = 250

    yRadius = 100

    for degree in range(0,360,10):

        x1 = int(math.cos(degree * 2 * math.pi/360) * xRadius)+300

        y1 = int(math.sin(degree * 2 * math.pi/360) * yRadius)+150

        screen.fill((0, 0, 0))

        pygame.draw.circle(screen, (255, 69, 0), [300, 150], 40)

        pygame.draw.ellipse(screen,(255,255,255),[50,50,500,200],1)

        pygame.draw.circle(screen, (0, 255, 0), [x1, y1], 20)

        pygame.display.flip()

        clock.tick(5)# screen refresh rate

