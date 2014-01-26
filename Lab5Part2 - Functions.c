//Shimeng Cui
//This program simulates the game Craps. It keeps track of the user's wins and losses and at the end of each game asks the user if they want to continue playing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rollDice(void){
    int num1 = (rand()%6)+1; //creates 2 random numbers between 1 and 6 inclusive
    int num2 = (rand()%6)+1;
    return num1+num2; //adds up numbers and returns it
}

bool playGame(void){
    int count = 0; //checks which roll it's on
    int point; //keeps track of the "point" value
    do{
        int num = rollDice(); //calls rollDice() to get the summed numbers
        printf("You rolled: %d\n",num);
        count++; //adds to count
        if(count == 1){ //if it's the first roll
            if(num == 7||num == 11){ //if you get 7 or 11 you win
                printf("You win!\n");
                return true; //tells winLoss() that it's a win

            }
            else if(num == 2||num == 3||num == 12){ //if it's 2,3 or 1 you lose
                printf("You lose!\n");
                return false; //tells winLoss() you lost
            }
            else{
                point = num; //this situation means you will continue to play more rounds so it sets point as the number rolled on the first turn
                printf("Your point is: %d",point); //prints point
            }
        }
        else{ //if it's not the first roll
            if(num == point){
                printf("You win!\n"); //win
                return true;
            }
            if(num == 7){
                printf("You lose!\n"); //loss
                return false;
            }
        }
    }while(true); //while the function does not return. e.g. when you have not won or loss
}

void winLoss(void){
    char ans = 'y'; //character entered by the user to continue playing or not
    char ul; //filler charcter needed for the enter key press
    bool game; //game is either true or false for win or loss
    int win = 0; //keeps track of W/L
    int loss = 0;
    while(ans == 'y'||ans == 'Y'){ //makes sure that the user wants to continue
        game = playGame(); //calls playGame() to play game
        if(game == true){
            win++; //adds to win count you win
        }
        else{
            loss++; //vice versa
        }
        printf("Play again? ");
        scanf("%c%c",&ans,&ul); //gets user input of y/n to continue or not
    }
    printf("\nWins: %d\nLosses: %d",win,loss);

}
