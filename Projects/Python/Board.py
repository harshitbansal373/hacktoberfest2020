import pygame, sys , time , random
from pygame.locals import QUIT,K_UP,K_ESCAPE,KEYDOWN, K_LEFT, K_RIGHT,K_a,K_d
PURPLE = ((170,0,255))
BOX_SIZE = 20
SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480
BOARD_WIDTH = 10
score = 0
blue = ((0,255,255))
green = ((0,255,0))
pink = ((255,0,101))
yellow = ((255,255,0))
found=0

S_SHAPE = [['.....',
                     '.....',
                     '..cc.',
                     '.cc..',
                     '.....'],
                    ['.....',
                     '..c..',
                     '..cc.',
                     '...c.',
                     '.....']]

I_SHAPE = [['..c..',
                     '..c..',
                     '..c..',
                     '..c..',
                     '.....'],
                    ['.....',
                     '.....',
                     'cccc.',
                     '.....',
                     '.....']]
O_SHAPE = [['.....',               #2d array o_shape[0] will be used further to draw shape {to be more specific otherwise koi random sa shape aayega}
                     '.....',
                     '.cc..',
                     '.cc..',
                     '.....']]
Z_SHAPE = [['.....',
                     '.....',
                     '.cc..',
                     '..cc.',
                     '.....'],
                    ['.....',
                     '...c.',
                     '..cc.',
                     '..c..',
                     '.....']]
def pieces_dict(): #to show all the available pieces
    return {
        'S':S_SHAPE,
        'I':I_SHAPE, #returning a  dictionary
        'O':O_SHAPE,
        'Z':Z_SHAPE
    }

def color_dict(): #to show all the available colors
    return {
        'P':pink,
        'B':blue, #returning a  dictionary
        'Y':yellow,
        'G':green
    }

def run_tetris_game(name):
    score = 0
    pygame.init()  # start the game engine
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT) ) # create a window
    pygame.display.set_caption('My TetrisGame') # give title to the window
    game_matrix = create_game_matrix() #main game matrix 20 X 10
    last_time_piece_moved = time.time()  # time.time() is used to find the seconds passed since last action
    piece = create_piece()


    while True: #start loop to take input from user

        screen.fill((  0,   0,   0)) #makes the colour of the screen black

       # MOVE THE PIECE ONE CELL DOWN AFTER 1 SECOND
        if (time.time() - last_time_piece_moved > 0.5):
            piece['row'] = piece['row'] + 1 # we move to the next row if current time exceeds  by 1s from prev move
            last_time_piece_moved = time.time() # and update it each time with current time

        # DISPLAY PIECE IN THE BOARD
        draw_moving_piece(screen, piece)

        pygame.draw.rect(  # inbuilt func of pygame with 4 parameters
            screen,  # window where game will be displayed
            PURPLE,  # color of rect box
            [100, 50, 10 * BOX_SIZE + 10, 20 * BOX_SIZE + 10 ], 5)  # point  where the rect should be drawn first-hor second-vert----- {+10 to remove screen error which is coming}
        # parameters showing box width and height where 10*20 is 10cols and 20boxsize
        # last parameter is line thickness

        draw_board(screen, game_matrix , piece)
        draw_score(screen, score , name)


        listen_to_user_input(game_matrix, piece) #to move left-right
        # CHECK IF PIECE REACHES THE END
        if (not isValidPosition(game_matrix, piece, adjRow=1)):
            game_matrix = update_game_matrix(game_matrix, piece)  #updating which all cell are no longer empty and block has occupied the cell now
            lines_removed = remove_completed_lines(game_matrix)
            score += lines_removed
            piece = create_piece()  #start with a new piece again

        # STATEMENT REPLACED---if (piece['row'] == 19 or game_matrix[piece['row'] + 1][piece['column']] != '.'): in update function #box needs to stop when either we have reached just above the last row or when the next coming cell is occupied
        if not game_over(screen, game_matrix):
            draw_over(screen)

        pygame.display.update() #updates the screen everytime
        for event in pygame.event.get(QUIT): #pygame.event contains the list of events the user do like leftclick,close etc
            pygame.quit()
            sys.exit() # terminate if any QUIT events are present

def isOnBoard(row, column):
    return column >= 0 and column < 10 and row < 20

def draw_score(screen, score,name): #screen is the window where we want to display the text
    # DRAW THE SCORE TEXT
    #create font object
    font = pygame.font.Font('freesansbold.ttf', 18)  #parameters- font type with extension .ttf and size
    #create an image of text
    textsurface = font.render('Score: %s' % score, True, (255,255,255))  #parameters- text to display, antialias, color
    #add text image to game window
    Name = font.render('PLAYER: %s' % name, True, (255, 255, 255))
    screen.blit(textsurface, (640 - 150, 20))  # parameters- textimage window and loc to start drawing
    screen.blit(Name, (640 - 150, 60))

def remove_completed_lines(game_matrix):
    lines_removed = 0 #to keep track of score
    for row in range(20):
        if(is_line_completed(game_matrix,row)):
            for row_to_move_down in range(row, 0, -1): # Loop from the completed row to the top row
                for col in range(10):
                    game_matrix[row_to_move_down][col] = game_matrix[row_to_move_down-1][col] # Move each cell one row down and removing the row which is completed
            # Set very top line to blank.
            for x in range(10):
                game_matrix[0][x] = '.'
            lines_removed += 1
    return lines_removed

def is_line_completed(game_matrix, row):
    # Return True if the line filled with boxes with no gaps.
    for column in range(10):
        if game_matrix[row][column] == '.':
            return False
    return True

def listen_to_user_input(game_matrix,piece):
    for event in pygame.event.get(): #loop over each event (check when will it come out of loop}
        if event.type == KEYDOWN: #checking kedown events
            if (event.key == K_LEFT ) and isValidPosition(game_matrix,piece,adjColumn=-1): #if left key presses then decrease col by 1
                piece['column'] -= 1
            elif (event.key == K_RIGHT ) and isValidPosition(game_matrix,piece,adjColumn=1): #checking whether the next updated col is valid or not
                # *initially for single cell-- isValidPosition(game_matrix,piece['row'],piece['column']+1) *
                piece['column'] += 1
            elif (event.key == K_UP): #up key to increment rotations each time
                piece['rotation'] = (piece['rotation'] + 1) % len(pieces_dict()[piece['shape']])
                # eg- 0%2=0, 1%2=1, 2%2=0, 3%2=1 ... 2 as len(pieces_dict()[ shape randomly selected ]) for s and i
                #0-normal piece 1-rotated piece version
                if not isValidPosition(game_matrix, piece):
                    piece['rotation'] = (piece['rotation'] - 1) % len(pieces_dict()[piece['shape']]) #if position is not valid then we will undue the roattion pro done

#REFER isValidPosition -- think adjrow and adj col (got it though)

def isValidPosition(game_matrix, piece, adjColumn=0, adjRow=0):
    # Return True if the every block of the piece is within the board and not colliding
    piece_matrix = pieces_dict()[piece['shape']][piece['rotation']] # in each drawmovingpiece updategame and isval function we replace 0 with the rotationpiece options
    for row in range(5):
        for col in range(5):
            if piece_matrix[row][col] == '.': #if cell is empty do nothing
                continue
            if not isOnBoard(piece['row']+ row + adjRow, piece['column']+ col + adjColumn): # to check if piece is moving within board
                return False
            if game_matrix[piece['row']+ row + adjRow][piece['column'] +col + adjColumn] != '.': # Check if piece is moving at empty pos
                return False

    return True
def create_piece():
    piece = {} #create a piece using dictionary
    random_shape = random.choice(list(pieces_dict().keys())) #choose randomly from available list of shape lables extracted in form keys only
    random_color= random.choice(list(color_dict().keys()))
    piece['shape'] = random_shape
    piece['color'] = random_color
    piece['rotation'] = 0 #to keep track of rotations *0 means the show the normal rotated piece
    piece['row'] = 0 #set its location to (0,2)
    piece['column'] = 2
    return piece

def draw_board(screen, matrix,piece):  #drawing the board respective to what is there on the matrix
            game_matrix_columns = 10
            game_matrix_rows = 20

            for row in range(game_matrix_rows):
                for column in range(game_matrix_columns):
                    if (matrix[row][column] != '.'):  #call the draw tetris function if the cell has anything else than .
                        draw_single_tetris_box(screen, row, column, (255, 255, 255), (180, 180, 180))


def draw_moving_piece(screen, piece):
    shape_to_draw = pieces_dict()[piece['shape']][piece['rotation']]
    color= color_dict()[piece['color']]
    # the shape which is selected in piece['shape'] usko key ki tarah use karke value extract kari h jismein shape aajaye..
    # [piece['rotation']] is to extract the element of the 2d array in shape value acc to the rotated shpe options {*used rotating prop to see which matrix should be used*}
    for row in range(5): #since shape's matrix is of 5 X 5
        for col in range(5):
            if shape_to_draw[row][col] !='.': #will draw a single tetris whenevr there is c and finally we can get full req shape using this single tetriss
                draw_single_tetris_box(screen,piece['row']+row,piece['column']+col,color, (255, 255, 255))

def update_game_matrix(matrix, piece): #to make the corresponding changes in the game matrix acc to shape encountered
    for row in range(5):
        for col in range(5):
            if(pieces_dict()[piece['shape']][piece['rotation']][row][col] != '.'):
                matrix[piece['row']+row][piece['column']+col] = 'c' # *we get the pos at which we have to write c at shape-matrix row + piece-matrix row i.e pieceloc + piececell *
    return matrix

def draw_single_tetris_box(screen, matrix_cell_row, matrix_cell_column, color, shadow_color):
    # board margin(100,50) + line thickness + (column {using value stored in dict in create peice func} * box_size)
    origin_x = 100 + 5 +( matrix_cell_column*20+1)  #add 1 to leave 1 pixel space btw the squares
    origin_y = 50 + 5 + ( matrix_cell_row*20+1)

    pygame.draw.rect(screen, shadow_color , [origin_x, origin_y, 20*1, 20*1]) #a grey box of size 1 X 1 be started on (x,y)
    pygame.draw.rect(screen, color ,[origin_x, origin_y,18,18]) #no thickness by default 0 { this white box is entirely and not for a single block }

    #box size means size of each block and height and width specify how many such blocks horizontally and vertically

def create_game_matrix(): #creating matrix of 20 rows 10 cols witch each entry as . initially
    game_matrix_columns = 10
    game_matrix_rows = 20
    matrix = []
    for row in range(game_matrix_rows):
        new_row = []
        for column in range(game_matrix_columns):
            new_row.append('.')
        matrix.append(new_row)
    return matrix

def game_over(screen, matrix):
    found=0
    game_matrix_columns = 10
    game_matrix_rows = 20
    for row in range(game_matrix_rows):
        for column in range(game_matrix_columns):
            if (matrix[row][column] != '.'):
                found+=1
                break
    if found==20:
        return False
    else:
        return True


def draw_over(screen):  # screen is the window where we want to display the text
    font = pygame.font.Font('freesansbold.ttf', 20)
    ts = font.render('GAME OVER', True, (255, 255, 255))
    screen.blit(ts, (640 - 150, 100))


name = input("ENTER YOUR NAME")
run_tetris_game(name)
