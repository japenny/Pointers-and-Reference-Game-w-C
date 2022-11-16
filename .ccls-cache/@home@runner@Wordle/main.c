

/*
Expand:
Add tournaments
Allow user to choose a category
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Struct: 
contains difficulty
hints enabled or not
# of attempts
an array of words
*/
struct setting{
  int diff;
  int hint;
  int trys;
  char word[2000][5];
};

//Displays a hint
void hints(char* word, int* idx, int diff){//Hints could be better, hints based on difficulty and randomized idx
  //Checks if user is allowed hints and displays a hint based on idx
  if(diff < 3){
    if(*idx < 4){
      printf("Hint: %c", word[*idx]);
      *idx += 1;
    }
    else{
      printf("No more hints avaliable");
    }
  }
  else{
    printf("Nice Try");
  }
  printf("\n");
  
}

//Checks the users guess
void userGuess(char* guess, char* word, int* attempts){

  //Copy word to temp
  char temp[5];
  for(int i = 0; i < 5; i++){//strcpy causes buffer overflow
    temp[i] = word[i];
  }

  //Displays any corrects letters the user guessed
  printf("---------------\n");
  int win = 5;
  for(int i = 0; i < 5; i++){//guess
    printf(" %c", guess[i]);
        
    for(int j = 0; j < 5; j++){//word
      if(guess[i] == temp[j] && temp[j] != '/'){
        if(j == i){
          win--;
          printf("+ ");
        }
        else{
          printf("- ");
        }
        temp[j] = '/';
      }
    }   
  }
  
  //Displays if user won or not
  if(win == 0){
    *attempts = -1;
    printf("\n\n> CONGRATS <");
    printf("\n٩( ^ᴗ^ )۶");
  }
  else if(*attempts <= 0){
    printf("\n\n> FAIL <");
    printf("\n(╯°□°)╯︵ ┻━┻");
  }
  
  printf("\n---------------\n");
}

//Operates the game (WORDLE)
void quickPlay(struct setting* set){
  //Displays allowed attempts and if hints are enabled
  printf("\n\n==============\n\t PLAY\n==============");
  printf("\nAttempts: %d", set->trys);
  if(set->hint == 1) printf("\nHints Enabled\nType 'hints' for a hint");
  else  printf("\nHints Disabled");
  printf("\n=====================");

  //Declares extra variables for function
  int attempts = set->trys; 
  int wordIdx = rand() % 2000;      //change to a true random generator
  int hintIdx = 0;

  //Gets a word from set.word for user to guess
  char word[5];                 //Strcpy?
  for(int i = 0; i < 5; i++){
    word[i] = set->word[wordIdx][i];
  }

  //Gets users guess and directs to appropriate function, when needed
  while(attempts > 0){
    char guess[999];
    
    printf("\nEnter Guess\n> ");
    scanf("%s", guess);

    if(strcmp(guess, "hints") == 0){
      hints(word, &hintIdx, set->diff);
    }
    else if(strlen(guess) == 5){
      attempts--;
      userGuess(guess, word, &attempts);
    }
    else{
      printf("Must be 5 characters long\n");
    }
  }
}


//Displays what each difficulty represents and users current diff
void diffTypes(struct setting* set){
  printf("\n\nYour current difficulty is set to ");
  if      (set->diff == 1) printf("Easy\n");
  else if (set->diff == 2) printf("Normal\n");
  else                     printf("Hard\n");
  
  printf("\nEasy");
  printf("\nHints are enabled");
  printf("\nTotal of 8 attempts\n");
  
  printf("\nNormal");
  printf("\nHints are enabled");
  printf("\nTotal of 5 attempts\n");
  
  printf("\nHard");
  printf("\nHints are disabled");
  printf("\nTotal of 4 attempts\n");
  
}

//Difficulty menu
void diff(struct setting* set){

  //Allows users to change diff from easy to hard, and see difficulty differences
  while(1){
    int val;
    printf("\n\n--------------\n   DIFFICULTY\n--------------");
    printf("\n1: Easy");
    printf("\n2: Normal");
    printf("\n3: Hard");
    printf("\n4: View difficulty types");
    printf("\n5: Exit difficulty settings");
    printf("\n----------------------\n\n");

    printf("Choose an option (1-5)\n> ");
    scanf(" %d", &val);
    
    if (val == 1){
      set->diff = 1;
      set->hint = 1;
      set->trys = 8;
      break;
    }
    else if (val == 2){ 
      set->diff = 2;
      set->hint = 1;
      set->trys = 5;
      break;
    }
    else if (val == 3){ 
      set->diff = 3;
      set->hint = 0;
      set->trys = 4;
      break; 
    }
    else if(val == 4){
      diffTypes(&*set);
    }
    else if (val == 5) break;
    
  }
  
}

//Prompts user to enable/disable hints
void hint(struct setting* set){
  while(1){
    char str[999];
    
    if(set->hint == 1){
      printf("\nWould you like to disable hints?");
    }
    else{
      printf("\nWould you like to enable hints?");
    }
    printf("\nType 'yes' or 'no' (y/n)\n> ");
    scanf(" %s", str);

    if(str[0] == 'y'){
      if (set->hint == 1) set->hint = 0;
      else set->hint = 1;
      break;
    }
    else if(str[0] == 'n'){
      break;
    }
  }
}

//Prompts user with option to reset settings 
void reset(struct setting* set){
  while(1){
    char str[999];

    printf("\nWould you like to reset all settings?");
    printf("\nType 'yes' or 'no' (y/n)\n> ");
    scanf(" %s", str);

    if(str[0] == 'y'){
      set->diff = 2;
      set->hint = 1;
      set->trys = 5;
      break;
    }
    else if(str[0] == 'n'){
      break;
    }
  }
  
}

//Settings menu
void settings(struct setting* set){
  int exit = 0;
  
  //Displays diff menu and directs to users chosen option
  while(!exit){
    printf("\n\n--------------\n   SETTINGS\n--------------");
    printf("\n1: Change Difficulty");
    printf("\n2: Hints");
    printf("\n3: Reset All Settings");
    printf("\n4: Leave Settings");
    printf("\n----------------------\n");
  
    while(1){
      int val;
      
      printf("Choose an option (1-4)\n> ");
      scanf("%d", &val);
  
      if (val == 1){
        diff(&*set);
        break;
      }
      else if(val == 2){
        hint(&*set);
        break;
      }
      else if(val == 3){
        reset(&*set);
        break;
      }
      else if(val == 4){
        exit = 1;
        break;
      }
    }
  }

}


//Describes how to play WORDLE
void howToPlay(){
  printf("\n\nHOW TO PLAY:\n\n");
  printf("Guess must be a 5-letter word.\n");
  printf("'+' and '-' symbols determine a words validity.\n\n");
  
  printf("W+ O R D L E\n");
  printf("'W+', correct spot and right letter.\n\n");

  printf("W O- R D L E\n");
  printf("'W-',letter in word but wrong spot.\n\n");

  printf("W O R D L E\n");
  printf("No symbol means its not in the word.\n\n\n");  
}

//Main function thats the basis for the system
int main() {
  int Exit = 0;
  struct setting set;
  set.diff = 2;
  set.hint = 1;
  set.trys = 5;

  //Retrieves 2000 words from words.txt (12,000 words avaliable)
  FILE *file;
  file = fopen("words.txt", "r");
  for(int i = 0; i < 2000; i++){
    fgets(set.word[i], 7, file);
  }
  fclose(file);
  
  
  while(!Exit){
    //Main menu of game
    printf("\n\n==============\n\tWORDLE\n==============");
    printf("\n1: Quick Play");
    printf("\n2: Settings");
    printf("\n3: How to Play");
    printf("\n4: Exit");
    printf("\n=====================\n");
    
    //Check if an option is valid and directs to chosen option
    while(1){
      int opt;
      
      printf("Choose an option (1-4)\n> ");
      scanf("%d", &opt);
      
      if(opt == 1){
        quickPlay(&set);
        break;
      }
      else if(opt == 2){
        settings(&set);
        break;
      }
      else if(opt == 3){
        howToPlay();
        break;
      }
      else if(opt == 4){
        printf("\n( ´ ▽ ` )ﾉ\n");
        Exit++;
        break;
      }
      else{
        printf("Invalid option, enter a number from 1 - 4");
      }
    }
 
  }
}