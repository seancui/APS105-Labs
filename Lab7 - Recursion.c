//Shimeng Cui
//This program take in the user's guess for the game mastermind and the number of whites and blacks reported by the mastermind game. It then outputs all the possible combinations of answers possible with that number of whites, blacks, dots and answer.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int findW(int pos,int len, int black, int white, char *pat, char *oriPat,char *copyPat, char *copyOriPat){ //finds the number of whites in the current generated pattern compared to the user input
    int i,j;
    int white1=0; //amount of whites
    for(i = 0;i<len;i++){
        if(pat[i]==oriPat[i]){ //if the characters equal and are both in the same position (index)
            copyPat[i]='x'; //this is needed to prevent checking too many times later on causing unnecessary whites
            copyOriPat[i]='y';
        }
    }
    for(i=0;i<pos;i++){
        for(j=0;j<len;j++){
            if((copyOriPat[j]==copyPat[i])&&(i!=j)){ //makes sure the characters equal and and the positions don't equal
                white1+=1; //adds to count of whites
                copyPat[i]='x'; //needed for same reason as above
                copyOriPat[j]='y';
            }
        }
    }
    return white1; //returns the number of whites
}
int findB(int pos,int len, int black, char *pat, char *oriPat,char *copyPat, char *copyOriPat){
    int i;
    int black1=0; //amount of whites
    for(i = 0;i<len;i++){
        if(pat[i]==oriPat[i]){ //if the characters equal and are both in the same position (index)
            black1+=1;
        }
    }
    return black1; //returns number of blacks
}

void perm(int pos, int len, int black, int blackCount,int white, int whiteCount, char *oriPat, char *pat, char *copyPat, char *copyOriPat){ //parameters: index position, length of user input, user input blacks, number of blacks in current combo, user input whites, whites in current combo, user input pattern, current combo, copy of original, copy of current combo
    int i,j;
    char bank[] = {'a','b','c','d','e','f'}; //bank of charactesr that could be used, a to f
    if(pos==len){ //base case, when the index equals the length of the user input string, thus all apaces are filled with a letter
        pat[len]='\0'; //adds null character to end so that it can be printed using %s
        if(blackCount==black&&whiteCount==white){ //makes sure that the whites and blacks in the combo is the same as the ones the user inputs
            printf("%s\n",pat);
            return;
        }
    }
    else{
        for(i=0;i<=5;i++){ //gets the letter from the bank, thus making sure every combination is made
            pat[pos]=bank[i];
            strcpy(copyPat,pat); //makes a copy of pat so that it can be changed without consequence
            strcpy(copyOriPat,oriPat);
            whiteCount = findW(pos+1,len,black,white,pat,oriPat,copyPat,copyOriPat); //finds number of whites
            blackCount = findB(pos+1,len,black,pat,oriPat,copyPat,copyOriPat); //finds number of blacks
            if(blackCount<=black&&(blackCount+whiteCount+(len-pos+1)>=black+white)){ //makes sure the number of blacks is not more than the number specified, makes sure that blacks plus whites plus number of apaces remaining can satsify  the number of user specified blacks and whites
                perm(pos+1,len,black,blackCount,white,whiteCount,oriPat,pat,copyPat,copyOriPat); //calls itself
            }
        }
    }
}

int main(void)
{
    int patLen,black,white; //user input pattern length, use input blacks and whites
    printf("Enter the pattern length: ");
    scanf("%d",&patLen); //gets length from user
    getchar(); //consumes new line
    char *pat = (char *)malloc((patLen+1)*sizeof(char)); //makes arrays for pattern, oriPat, copyPat, copyOriPat. patLen+1 for null character
    char *oriPat = (char *)malloc((patLen+1)*sizeof(char));
    printf("Input the guess pattern: ");
    int i;
    gets(oriPat); //gets the user input patter
    printf("Enter the number of black pegs in the feedback: ");
    scanf("%d",&black); //gets user input blacks
    printf("Enter the number of white pegs in the feedback: ");
    scanf("%d",&white); //gets user input whites
    char *copyPat = (char *)malloc((patLen+1)*sizeof(char));
    char *copyOriPat = (char *)malloc((patLen+1)*sizeof(char));
    printf("The possible key patterns are:\n");
    perm(0,patLen,black,0,white,0,oriPat,pat,copyPat,copyOriPat);
    free(copyPat); //free memory
    free(copyOriPat);
    free(pat);
    free(oriPat);
    return 0;
}
