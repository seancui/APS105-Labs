//Shimeng Cui
//This program simulates the game Mastermind. One user inputs the length of the pattern, the max amount of tries allowed and the answer code. Then another user attempte to guess the code within the alloted number of tries by inputing a guess code. The program will output the user's guessed pattern along with "b" if the guessed character is in the right place, "w" if it's in the code but in the wrong place and "." if it's not in the code
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void)
{
    int patLen, guessMax; //length of pattern, max amount of guesses allowed
    int guessNum = 1; //keeps track of the guess number
    bool correct = false; //indicates when the playser guesses the patternr right
    printf("Enter the pattern length: ");
    scanf("%d",&patLen);
    char *key = (char *)malloc(patLen*sizeof(char)); //array of char for the key
    char *copyKey = (char *)malloc(patLen*sizeof(char)); //copy of key
    char *copyAns = (char *)malloc(patLen*sizeof(char)); //copy of user answers
    printf("Enter the number of guesses: "); //gets max amount of guesse
    scanf("%d",&guessMax);
    printf("Input the key pattern with no spaces: ");
    scanf("\n"); //consumes the \n from previous scanf so that it does not fill the first spot in the key array
    int i;
    for(i = 0;i<patLen;i++){
        scanf("%c",&key[i]); //gets the answer key
    }
    getchar(); //consumes enter after scanning key
    char **userAns;
    userAns = (char **)malloc(guessMax*sizeof(char *)); //user's answers
    for(i = 0; i<guessMax;i++){
        userAns[i] = (char *)malloc(patLen*sizeof(char));
    }
    char **corAns;
    corAns = (char **)malloc(guessMax*sizeof(char *)); //array for the "b","w" and "."
    for(i = 0; i<guessMax;i++){
        corAns[i] = (char *)malloc(patLen*sizeof(char));
    }
	while((correct==false)&&(guessNum<=guessMax)){ //while the user does not guess the right code and is below the max amount of guesses
        int black = 0; //keeps track of amount b, w and .
        int dot = 0;
        int white = 0;
	    int ansIndex = 0; //keeps track of where the index is for inputing into the corAns array
	    int i,j;
        for(i=0;i<patLen;i++){
            copyKey[i]=key[i]; //copies original key over to a temporary array
        }
	    printf("Input a guess pattern with no spaces: ");
	    for(j=0;j<patLen;j++){
            scanf("%c",&userAns[guessNum-1][j]); //scans the user answer in to the array. guessNum-1 would give the right index
	    }
	    for(i=0;i<patLen;i++){
            copyAns[i]=userAns[guessNum-1][i]; //copies answer to temporary array
	    }
	    getchar(); //consumes \n after inputing answers
        for(i = 0;i<patLen;i++){
            if(key[i]==userAns[guessNum-1][i]){ //if the characters equal and are both in the same position (index)
                corAns[guessNum-1][ansIndex] = 'b'; //adds "b" to to the corAns array
                black+=1; //adds to black count
                ansIndex+=1; //shifts the index right 1
                copyKey[i]='x'; //this is needed to prevent checking too many times later on causing unnecessary Ws
                copyAns[i]='y';
            }
        }
        for(i=0;i<patLen;i++){
            for(j=0;j<patLen;j++){
                if((copyAns[j]==copyKey[i])&&(i!=j)){ //makes sure the characters equal and and the positions don't equal
                    white+=1; //adds to count of whites
                    copyKey[i]='x'; //needed for same reason as above
                    copyAns[j]='y';
                }
            }
        }
        for(i=0;i<white;i++){ //adds the right amount of Ws to the corAns array
            corAns[guessNum-1][ansIndex]='w';
            ansIndex+=1; //shifts index
        }
        dot = patLen-black-white; //gets number of dots needed
        for(i=0;i<dot;i++){ //adds right amount of dots to the corAns array
            corAns[guessNum-1][ansIndex]='.';
            ansIndex+=1; //shifts index
        }
        for(i=0;i<patLen;i++){
            if(corAns[guessNum-1][i]=='b'){ //if all the characters match up between answer key and user answer
                correct=true; //the game should end because the user has guessed the pattern
            }
            else{
                correct=false;
            }
        }
        for(i=0;i<guessNum;i++){ //prints all lines of corAns and userAns
            int j;
            printf("%d: ",i+1); //prints the guess number
            for(j=0;j<patLen;j++){
                printf("%c",corAns[i][j]); //prints the Bs, Ws, and dots corrisponding to the guess number
            }
            printf(" ");
            for(j=0;j<patLen;j++){ //prints the user guess at the correct guess number
                printf("%c",userAns[i][j]);
            }
            printf("\n"); //next line
        }
        guessNum+=1; //increases guess number
	}
	if(correct==true){ //if the playser guessed it right
        printf("You guessed the pattern!");
    }
    else{ //if the player did not guess right in the number of tries allotted
        printf("You did not guess the pattern!");
    }
    return 0;
}
