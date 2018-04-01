//Momin Hussain
//ucf cop3223c spring 18
//Hw7 Problem 2


#include <stdio.h>


int field[50][50] = {0};


int Left(int orientation);

int Right(int orientation);


int Motion(int orientation, int move, int row, int col, int PenState);

void PrintField(void);

int main(void) //Starting main function
{
  
  int input = 0, move, orientation = 1, PenState = 0, row = 50, col = 0;
  
  printf("Welcome to turtle sketch\n");
  printf("Commands: \n");
  printf("1: Pen-Up \n");
  printf("2: Pen-Down \n");
  printf("3: Turn Right \n");
  printf("4: Turn Left \n");
  printf("5,10: Move forward 10 spaces \n");
  printf("6: Print to 50 by 50 array \n");
  printf("9: End program entry(sentinel value)\n");
  
  // Printing the Commands^^
  
  while (input != 9)
  {
    switch (input)
    {
      case 1:
      {
        PenState = 0;
        break;
      }
      case 2:
      {
        PenState = 1;
        break;
      }
      case 3:
      {
        orientation = Right(orientation);
        break;
      }
      case 4:
      {
        orientation = Left(orientation);
        break;
      }
      case 5:
      {
        scanf(",%d", &move);
        
        if(orientation == 2 || 4)
          col = Motion(orientation, move, row, col, PenState);
          
        else if(orientation == 1 || 3)
          row = Motion(orientation, move, row, col, PenState);
        break;
      }
      case 6:
      {
        PrintField();
        break;
      }
      case 9:
      printf("\nEnding the program\n");
      
    }
    scanf("%d", &input);
  }
  return 0;
}


int Right(int orientation)
{
  orientation++;
  if (orientation == 5)
    orientation = 1;
  return orientation;
}

int Left(int orientation)
{
  orientation--;
  if (orientation == 0)
    orientation = 4;
  return orientation;
}

int Motion(int orientation, int move, int row, int col, int PenState)
{
  
  switch (orientation){
    case 1:{
      if (PenState == 1)
      {
        for (int a = 0; a < move; a++){
          field[row - a][col] = 1;
          printf("\nrow: %d, col: %d, n: %d", row - a, col, a);
        }
      }
      row = row - move;
      return row;
      break;
    }
    
    case 2:
    {
      if (PenState == 1){
        for (int a = 0; a < move; a++){
          field[row][col + a] = 1;
        }
      }
      col = move + col;
      break;
    }
    
    case 3:
    {
      if (PenState == 1)
      {
        for (int a = 0; move > a; a++){
          field[a + row][col] = 1;
        }
      }
      row = move + row;
      break;
    }
    
    case 4:
    {
      if (PenState == 1){
        for (int a = 0; a < move; a++){
          field[row][col - a] = 1;
        }
      }
      col = col - move;
      break;
    }
  }
  printf("%d,%d", 1, 2);
  printf("\nMotion complete\n");
}

void PrintField(void){
  for (int m = 0; m < 19; m++){
    for (int a = 0; a < 19; a++)
    {
      if(field[a][m] == 0)
        printf("   ");
        
      if(field[a][m] == 1)
        printf(" * ");
    }
    printf("\n");
  }
}



//End of Hw7 Problem 2
