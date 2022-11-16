

/*
Expand:
Tournaments
Difficulty
reset
hints
category
*/

#include <stdio.h>

int quickPlay(){
  return 0;
}

struct setting{
  int difficulty;
  int reset;
  int hint;
};
void settings(struct setting* set){
  int val;
  printf("\n\n--------------\n   SETTINGS\n--------------\n");
  printf("\n1: Change Difficulty");
  printf("\n2: Hints");
  printf("\n3: Reset All Settings");
  printf("\n4: Leave Settings");
  printf("\n----------------------\n\n");

  while(1){
    printf("Choose an option (1-3)\n> ");
    scanf("%d", &val);
    
  }
  
  
}



//Describes how to play WORDLE
void howPlay(){
  printf("\n\nHOW TO PLAY:\n\n");
  printf("Guess must be a 5-letter word.\n");
  printf("'+' and '-' symbols determine a words validity.\n\n");
  
  printf("W+ O R D L E\n");
  printf("'W+' in the word and right spot.\n\n");

  printf("W O- R D L E\n");
  printf("'W-' in the word but wrong spot.\n\n");

  printf("W O R D L E\n");
  printf("No symbol means its not in the word.\n\n\n");  
}


//Main function that runs system
int main() {
  int Exit = 0;
  struct setting set;
  set.difficulty = 0;
  set.reset = 0;
  set.hint = 0;
  
  while(!Exit){
    //Main menu of game
    printf("==============\n\tWORDLE\n==============\n");
    printf("\n1: Quick Play");
    printf("\n2: Settings");
    printf("\n3: How to Play");
    printf("\n4: Exit");
    printf("\n=====================\n\n");
    
    //Check if an option is valid and directs to chosen option
    while(1){
      int opt;
      
      printf("Choose an option (1-4)\n> ");
      scanf("%d", &opt);
      
      if(opt == 1){
        quickPlay();
        break;
      }
      else if(opt == 2){
        settings(&set);
        break;
      }
      else if(opt == 3){
        howPlay();
        break;
      }
      else if(opt == 4){
        printf("Bye :)");
        Exit++;
        break;
      }
      else{
        printf("Invalid option, enter a number from 1 - 4");
      }
    }

    
  }
  
}



