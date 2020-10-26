#include<bits/stdc++.h> 
using namespace std; 

#define BEGINNER 0 
#define INTERMEDIATE 1 
#define ADVANCED 2 
#define MAXSIDE 25 
#define MAXMINES 99 
#define MOVESIZE 526 // (25 * 25 - 99) 

int SIDE ; // side length of the board 
int MINES ; // number of mines on the board 
int level; 

bool isValid(int, int);
bool isMine(int, int, char);
void makeMove(int*, int*);
void printBoard(char myBoard[][MAXSIDE]);
int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]);
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int *movesLeft);
void placeMines(int mines[][2], char realBoard[][MAXSIDE]);
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]);
void replaceMine (int row, int col, char board[][MAXSIDE]);
void playMinesweeper ();
void chooseDifficultyLevel ();
void changeRed();
void normal();
//Driver function
int main() {
  system("clear");
  system("tput setaf 1; tput bold");
  printf("\n\n\t\tMINE SWEEPER\n\n");
  system("tput sgr0");
  chooseDifficultyLevel(); 
  // printBoard()
  playMinesweeper();  
}


// Function to check whether given cell (row, col) is a valid cell or not 
bool isValid(int row, int col) {
  return (row >= 0) && (row < SIDE) && 
  (col >= 0) && (col < SIDE); 
} 


// Function to check whether given cell (row, col) has a mine or not. 
bool isMine (int row, int col, char board[][MAXSIDE]) {
  if (board[row][col] == '*') 
    return true; 
  else
    return false; 
} 


// Function to get the user's move 
void makeMove(int *x, int *y) { 
  printf("Enter your move,(row,col) -> "); 
  while(scanf("%d , %d", x, y) != 2){
        printf("Enter correct value : ");
        getchar();
  }
} 


void changeRed(){
  system("tput setaf 6; tput bold");
}


void normal(){
  system("tput sgr0");
}

// Function to print the current gameplay board 
void printBoard(char myBoard[][MAXSIDE]){
  system("clear");
  printf("\n\n\t\t");
  if(level == 1)
    printf("\t ");
  if(level == 2)
    printf("\t\t\t ");
  system("tput setaf 1; tput bold");
  printf("MINE SWEEPER\n\n");
  normal();
  int i, j; 
  printf ("\n\n\n  ");
  for (i=0; i<SIDE; i++)
    printf (" %2d ", i); 
  printf ("\n\n"); 
  for (i=0; i<SIDE; i++) {
    printf ("%2d ", i); 
    for (j=0; j<SIDE; j++){
      if(myBoard[i][j] == '*')
        changeRed();
      printf (" %c  ", myBoard[i][j]); 
      if(myBoard[i][j] == '*')
        normal();
    }
    printf ("\n"); 
  } 
  printf("\n\n");
}


// A Function to count the number of mines in the adjacent cells 
int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]) { 
  int i; 
  int count = 0; 
  if (isValid (row-1, col) == true) { //North
    if (isMine (row-1, col, realBoard) == true) 
      count++; 
  } 
  if (isValid (row+1, col) == true) { //South
    if (isMine (row+1, col, realBoard) == true) 
      count++; 
  } 
  if (isValid (row, col+1) == true) {  //East
    if (isMine (row, col+1, realBoard) == true) 
      count++; 
  } 
  if (isValid (row, col-1) == true) {  //West
    if (isMine (row, col-1, realBoard) == true) 
      count++; 
  } 
  if (isValid (row-1, col+1) == true) {  //North-East
    if (isMine (row-1, col+1, realBoard) == true) 
      count++; 
  } 
  if (isValid (row-1, col-1) == true){  //North-West- 
    if (isMine (row-1, col-1, realBoard) == true) 
      count++; 
  } 
  if (isValid (row+1, col+1) == true) { //South-East
    if (isMine (row+1, col+1, realBoard) == true) 
      count++; 
  } 
  if (isValid (row+1, col-1) == true) { //South-West
    if (isMine (row+1, col-1, realBoard) == true) 
      count++; 
  } 
  return count; 
}


// A Recursive Fucntion to play the Minesweeper Game 
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int *movesLeft){
  if (myBoard[row][col] != '-') 
    return false; 
  int i, j;  
  if (realBoard[row][col] == '*') {
    myBoard[row][col]='*'; 
    for (i=0; i<MINES; i++) 
      myBoard[mines[i][0]][mines[i][1]]='*'; 
    printBoard (myBoard); 
    printf ("\nYou lost!\n"); 
    return true; 
  } 
  else{ 
    // Calculate the number of adjacent mines and put it on the board 
    int count = countAdjacentMines(row, col, mines, realBoard); 
    (*movesLeft)--; 
    myBoard[row][col] = count + '0'; 
    if (!count){ 
      if (isValid (row-1, col) == true) { 
        if (isMine (row-1, col, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row-1, col, movesLeft); 
      }
      if (isValid (row+1, col) == true) { 
        if (isMine (row+1, col, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row+1, col, movesLeft); 
      }
      if (isValid (row, col+1) == true) { 
        if (isMine (row, col+1, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row, col+1, movesLeft); 
      }
      if (isValid (row, col-1) == true) { 
        if (isMine (row, col-1, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row, col-1, movesLeft); 
      }
      if (isValid (row-1, col+1) == true) { 
        if (isMine (row-1, col+1, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row-1, col+1, movesLeft); 
      }
      if (isValid (row-1, col-1) == true) { 
        if (isMine (row-1, col-1, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row-1, col-1, movesLeft); 
      } 
      if (isValid (row+1, col+1) == true) { 
        if (isMine (row+1, col+1, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row+1, col+1, movesLeft); 
      } 
      if (isValid (row+1, col-1) == true) { 
        if (isMine (row+1, col-1, realBoard) == false) 
          playMinesweeperUtil(myBoard, realBoard, mines, row+1, col-1, movesLeft); 
      } 
    } 
    return false; 
  } 
} 


// A Function to place the mines randomly on the board 
void placeMines(int mines[][2], char realBoard[][MAXSIDE]) {
  bool mark[MAXSIDE*MAXSIDE]; 
  memset (mark, false, sizeof (mark)); 
  for (int i=0; i<MINES; ){ 
    int random = rand() % (SIDE*SIDE); 
    int x = random / SIDE; 
    int y = random % SIDE; 
    if (mark[random] == false) { 
      mines[i][0]= x; 
      mines[i][1] = y; 
      realBoard[mines[i][0]][mines[i][1]] = '*'; 
      mark[random] = true; 
      i++; 
    } 
  }
} 


// A Function to initialise the game 
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]) { 
  srand(time (NULL)); 
  for (int i=0; i<SIDE; i++){ 
    for (int j=0; j<SIDE; j++){ 
      myBoard[i][j] = realBoard[i][j] = '-'; 
    } 
  }
}


// A function to replace the mine from (row, col) and put it to a vacant space 
void replaceMine (int row, int col, char board[][MAXSIDE]) {
  for (int i=0; i<SIDE; i++) {
    for (int j=0; j<SIDE; j++){
        // Find the first location in the board which is not having a mine and put a mine there. 
      if (board[i][j] != '*'){ 
        board[i][j] = '*'; 
        board[row][col] = '-'; 
        return; 
      } 
    } 
  } 
} 


// A Function to play Minesweeper game 
void playMinesweeper (){
  bool gameOver = false; // Initially the game is not over 
  char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE]; 
  int movesLeft = SIDE * SIDE - MINES, x, y; 
  int mines[MAXMINES][2]; // stores (x,y) coordinates of all mines. 
  initialise (realBoard, myBoard); 
  placeMines (mines, realBoard); // Place the Mines randomly 
  int currentMoveIndex = 0; 
  while (gameOver == false) {
    printf ("Current Status of Board : \n"); 
    printBoard (myBoard); 
    makeMove (&x, &y); 
    if (currentMoveIndex == 0) { 
      if (isMine (x, y, realBoard) == true) 
        replaceMine (x, y, realBoard); 
    } 
    currentMoveIndex ++; 
    gameOver = playMinesweeperUtil (myBoard, realBoard, mines, x, y, &movesLeft); 
    if ((gameOver == false) && (movesLeft == 0)){
      printf ("\nYou won !\n"); 
      gameOver = true; 
    } 
  } 
} 


// A Function to choose the difficulty level of the game 
void chooseDifficultyLevel (){
  printf ("Enter the Difficulty Level\n"); 
  printf ("Press 0 for BEGINNER     ( 9 *  9 Cells and 10 Mines)\n"); 
  printf ("Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n"); 
  printf ("Press 2 for ADVANCED     (24 * 24 Cells and 99 Mines)\n"); 
  scanf ("%d", &level); 
  if (level == BEGINNER){
    SIDE = 9; 
    MINES = 10; 
  } 
  if (level == INTERMEDIATE){ 
    SIDE = 16; 
    MINES = 40; 
  } 
  if (level == ADVANCED){
    SIDE = 24; 
    MINES = 99; 
  } 
} 
