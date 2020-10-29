
def place(symbol):
    print(numpy.matrix(board))
    while(1):
        row = int(input("Enter row number (1,2,3)"))
        col = int(input("Enter col number (1,2,3)"))
        if(board[row-1][col-1]!='_' or row<1 or row>3 or col<1 or col>3):
            print("Invalid Index")
        else:
            board[row-1][col-1] = symbol;
            break

def won(symbol):
    
    return crow(symbol) or ccol(symbol) or cdiag(symbol)

def crow(symbol):
    for i in range(3):
        flag=True
        for j in range (3):
            if(board[i][j]!=symbol):
                flag=False
   
    return flag

def ccol(symbol):
     for i in range(3):
        flag=True
        for j in range (3):
            if(board[j][i]!=symbol):
                flag=False
     
     return flag

def cdiag(symbol):
    flag1=True
    i1=0
    j1=0
    while(i1 < 3 and j1<3):
        if(board[i1][j1]!=symbol):
            flag1=False
        i1=i1+1
        j1=j1+1
    i2=0
    j2=2
    flag2=True 
    while(i2 < 3 and j2>=0):
        if(board[i2][j2]!=symbol):
            flag2=False
        i2=i2+1
        j2=j2-1
   
    return flag1 or flag2
            


def play():
    for turn in range(9):
        if(turn%2==0):
            print("Player 1 ")
            place(p1S)
            
            if(won(p1S)):
                print(numpy.matrix(board))
                print("Player 1 wins")
                break
        else:
            print("Player 2 ")
            place(p2S)
            if(won(p2S)):
                print(numpy.matrix(board))
                print("Player 2 Wins")
                break
        
    if(not(won(p1S)) and not(won(p2S))):
        print("Draw")

import numpy
board =  numpy.array([['_','_','_'],['_','_','_'],['_','_','_']])
p1S = 'x'
p2S = 'o'
play()
