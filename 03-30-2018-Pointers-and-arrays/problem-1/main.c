//Momin Hussain
//HW 7 Problem 1
//UCF cop3223c spring 18
#include<stdio.h>
#include<string.h>

void printTicket(int seatNumber, char seatName[])
{  
  printf("\n==========Boarding pass========\n");
  printf("                                 \n");
  printf("Passenger: %d \t");
  printf("Seat Number: %d \t|\n", seatNumber);
  printf("Seat Type: %s|\n", seatName);
  printf("                           \n");
  printf("______________________________________ \n");
}


int assignSeat(int seats[], int *seatType){

  int startIndex, finalIndex, i;   
  char answer[3];
  //array declaration
  if (*seatType == 1)
  {
    startIndex = 0;
    finalIndex = 4;
  }
  else {
    startIndex = 5;
    finalIndex = 9;
  }
  for (i = startIndex; i <= finalIndex; i++){
    //Looping through the array index
    if (seats[i] == 0)
    {   //If all seats are taken
      
      return i;
    }
  }
  if (*seatType == 1){
    printf("Would you like to switch to Economy class?\n");
  }
  else {
    printf("Would you like to switch to First class?\n"); 
  }
  printf("Please respond: \"yes\" or \"no\"\n");   
  
  scanf("%s", answer);
  if (strcmp(answer,"no") == 0)
  {
    printf("The next plane will leave in 3 hours\n");    
    return -1;    
  }
  else {
    if (*seatType == 1){   
      *seatType = 2;
      startIndex = 5;
      finalIndex = 9;
    }
   
    else 
    {
      
      *seatType = 1;
      startIndex = 0;
      finalIndex = 4;
    }
  }
    for (i = startIndex; i <= finalIndex; i++){    
    if (seats[i] == 0){
      return i;
    }
  }
}

int main (void){                    
  int seatNumber, seatType, i;       
  char seatName[20];                 
  int seats[10] = {0};               
  
  for (i = 0; 10 > i; i++)
  {                               
    printf("Please type 1 for \"First class\"\n");    
    
    printf("Please type 2 for \"Economy\"\n");
    scanf("%d", &seatType);                            
    
    seatNumber = assignSeat(seats, &seatType);      
    if (seatNumber == -1){
      continue;
    }
    seats[seatNumber]++;           
    
    if (seatType == 1) {                     
      strcpy(seatName, "First Class ");
    }
    
    else if (seatType == 2){
      strcpy(seatName,"Economy\t");
    }
    
    printTicket(seatNumber + 1, seatName); 
  }
  return 0;
}


//End of Hw7 Problem 1
