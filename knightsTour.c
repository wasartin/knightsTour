#include<stdio.h>

const int NUM_OF_SPACES = 25;
const int TRUE = 0;
const int FALSE = 1;
const int BOARD[5][5] = {{1, 2, 3, 4, 5},
			 {6, 7, 8, 9, 10},
			 {11, 12, 13, 14, 15},
			 {16, 17, 18, 19, 20},
			 {21, 22, 23, 24, 25}};

//array holding possible combinations of the knights tours
static int savedPath[25];

//the index of the saved[] array
static int index = 0;

int isLegalMove(int row, int col);
int isSavedPathFull();
int isUnvisisted(int row, int col);
void checkPossibleSpot(int row, int col);
void recBacktrack(int currRow, int currCol);
void runTour();

int main(int argc, char *argv[]){
  runTour();
  return 0;
}

int isLegalMove(int row, int col){
  if(row > -1 && row < 5 && col > -1 && col < 5) return TRUE; 
  return FALSE;
}

int isSavedPathFull(){
  int lastPosition = 24;
  if(savedPath[lastPosition] != 0) return TRUE;
  return FALSE;
}

int isUnvisited(int row, int col){
  int i = 0;
  while(savedPath[i] != 0 && i < NUM_OF_SPACES){
    if(savedPath[i++] == BOARD[row][col]) return FALSE;
  }
  return TRUE;
}

void checkPossibleSpot(int row, int col){
  if(isLegalMove(row, col) == TRUE && isUnvisited(row, col) == TRUE){
    index++;
    recBacktrack(row, col);
    savedPath[index--] = 0;
  }
}

void recBacktrack(int currRow, int currCol){
  static int count = 0;

  savedPath[index] = BOARD[currRow][currCol];

  if(isSavedPathFull() == TRUE){
    printf("Current count is: %d\n", ++count);
    int i;
    for(i = 0; i < NUM_OF_SPACES; i++){
      printf("%d ", savedPath[i]);
    }
    printf("\n");
    return;
  }

  int row = currRow;
  int col = currCol;

  //check available moves
  //upper check
  checkPossibleSpot(row - 2, col - 1); //left
  checkPossibleSpot(row - 2, col + 1); //right

  //lower check
  checkPossibleSpot(row + 2, col - 1); //left
  checkPossibleSpot(row + 2, col + 1); //right

  //right check
  checkPossibleSpot(row - 1, col + 2); //up
  checkPossibleSpot(row + 1, col + 2); //down
   
  //left check
  checkPossibleSpot(row - 1, col - 2); //up
  checkPossibleSpot(row + 1, col - 2); //down
}

void runTour(){
  int i,j;
  int spaces = 5;
  for(i = 0; i < spaces; i++){
    for(j = 0; j < spaces; j++){
      recBacktrack(i, j);
    }
  }
}
