import pygame
import random

# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

SCREEN_WIDTH = 700
SCREEN_HEIGHT = 500
BALL_SIZE = 25


class Ball:
 """
 Class to keep track of a ball's location and vector.
 """
 def __init__(self):
 self.x = 0
 self.y = 0
 self.change_x = 0
 self.change_y = 0


def make_ball():
 """
 Function to make a new, random ball.
 """
 ball = Ball()
 # Starting position of the ball.
 # Take into account the ball size so we don't spawn on the edge.
 ball.x = random.randrange(BALL_SIZE, SCREEN_WIDTH - BALL_SIZE)
 ball.y = random.randrange(BALL_SIZE, SCREEN_HEIGHT - BALL_SIZE)

 # Speed and direction of rectangle
 ball.change_x = random.randrange(-2, 3)
 ball.change_y = random.randrange(-2, 3)

 return ball


def main():
 """
 This is our main program.
 """
 pygame.init()

 # Set the height and width of the screen
 size = [SCREEN_WIDTH, SCREEN_HEIGHT]
 screen = pygame.display.set_mode(size)

 pygame.display.set_caption("Bouncing Balls")

 # Loop until the user clicks the close button.
 done = False
 
 # Used to manage how fast the screen updates
 clock = pygame.time.Clock()

 ball_list = []

 ball = make_ball()
 ball_list.append(ball)

 # -------- Main Program Loop -----------
 while not done:
 # --- Event Processing
 for event in pygame.event.get():
 if event.type == pygame.QUIT:
 done = True
 elif event.type == pygame.KEYDOWN:
 # Space bar! Spawn a new ball.
 if event.key == pygame.K_SPACE:
 ball = make_ball()
 ball_list.append(ball)

 # --- Logic
 for ball in ball_list:
 # Move the ball's center
 ball.x += ball.change_x
 ball.y += ball.change_y

 # Bounce the ball if needed
 if ball.y > SCREEN_HEIGHT - BALL_SIZE or ball.y < BALL_SIZE:
 ball.change_y *= -1
 if ball.x > SCREEN_WIDTH - BALL_SIZE or ball.x < BALL_SIZE:
 ball.change_x *= -1

 # --- Drawing
 # Set the screen background
 screen.fill(BLACK)

 # Draw the balls
 for ball in ball_list:
 pygame.draw.circle(screen, WHITE, [ball.x, ball.y], BALL_SIZE)

 # --- Wrap-up
 # Limit to 60 frames per second
 clock.tick(60)

 # Go ahead and update the screen with what we've drawn.
 pygame.display.flip()

 # Close everything down
 pygame.quit()

if __name__ == "__main__
