//Shimeng Cui
//Takes input from the user of number of cents greater than 0 and less than 100. Returns the coins needed for least amount of coins neeeded to create change.
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int initChange; //the orginal change inputed by the user
    int change; //amount of change after each operation
    int quarter = 0; //number of each coin needed
    int dime = 0;
    int nickel = 0;
    int penny = 0;
    int types = 0;
    bool needPrintQuarter = false; //flag to see if the type of coin needs printing.
    bool needPrintDime = false;
    bool needPrintNickel = false;
    bool needPrintPenny = false;
    printf("Please give an amount in cents less than 100: ");
    scanf("%d",&change);
    initChange = change; //sets the initial change equal to the change
    if(change<0||change>99){ //makes sure the input is valid
        printf("Goodbye.");
    }
    else{
        while(change>0&&change<=99){ //while the change remaining is not 0
            if(change-25>=0){ //checks if the change-25 is not 0
                types+=1; //increses the number of types of coins
                needPrintQuarter = true; //flags it as needs to print quarters
                while(change-25>=0){ //while change-25 is not 0
                    quarter+=1; //increases the number of quarters
                    change-=25; //subtracts 25 from the change remaining
                }
            }
            if(change-10>=0){ //repeats for dimes, nickels, pennies
                types+=1;
                needPrintDime = true;
                while(change-10>=0){
                    dime+=1;
                    change-=10;
                }
            }
            if(change-5>=0){
                types+=1;
                needPrintNickel = true;
                while(change-5>=0){
                    nickel+=1;
                    change-=5;
                }
            }
            if(change-1>=0){
                types+=1;
                needPrintPenny = true;
                while(change-1>=0){
                    penny+=1;
                    change-=1;
                }
            }
            printf("%d cents: ",initChange);
            if(types==2){ //if there are only 2 types
                if(needPrintQuarter==true&&quarter==1){ //if the quarter needs to be printed and there is only 1 quarter
                    printf("1 quarter");
                }
                if(needPrintQuarter==true&&quarter>1){ //when there are more than 1 quarter
                    printf("%d quarters",quarter);
                }
                if(quarter>0&&dime==1){ //when there are quarters and dimes
                    printf(" and 1 dime");
                }
                if(quarter>0&&dime>1){
                    printf(" and %d dimes",dime);
                }
                if(quarter==0&&dime==1){ //when are no quarters and dimes
                    printf("1 dime");
                }
                if(quarter==0&&dime>1){
                    printf("%d dimes",dime);
                }
                if(quarter>0||dime>0){ //if there are quarters or dimes and nickels
                   if(nickel==1){
                        printf(" and 1 nickel");
                   }
                }
                if(quarter>0||dime>0){
                    if(nickel>1){
                        printf(" and %d nickels",nickel);
                    }
                }
                if(quarter==0&&dime==0){ //when there are NO quarters and dimes but there are nicksls
                    if(nickel==1){
                        printf("1 nickel");
                    }
                }
                if(quarter==0&&dime==0){
                    if(nickel>1){
                        printf("%d nickels",nickel);
                   }
                }
                if(quarter>0||dime>0||nickel>0){ //when there are quarters, nickels or dimes and pennies
                    if(penny==1){
                        printf(" and 1 cent");
                    }
                }
                if(quarter>0||dime>0||nickel>0){
                    if(penny>1){
                        printf(" and %d cents",penny);
                    }
                }
                if(quarter==0&&dime==0&&nickel==0){ //when there are NO quarters, dimes and nickels. But there are pennies
                    if(penny==1){
                        printf("1 cent");
                    }
                }
                if(quarter==0&&dime==0&&nickel==0){
                    if(penny>1){
                        printf("%d cents",penny);
                    }
                }
            }
            else{ //when there is only 1 type or more than 2 types
                if(needPrintQuarter==true&&quarter==1){ //if quarters need to be printed
                    printf("1 quarter");
                    needPrintQuarter = false; //sets flag to false to say that quarters have been printed
                }
                if(needPrintQuarter==true&&quarter>1){
                    printf("%d quarters",quarter);
                    needPrintQuarter = false;
                }
                if(quarter>0&&dime==1){ //checks if there are quarters and dimes
                    printf(", 1 dime");
                }
                if(quarter>0&&dime>1){
                    printf(", %d dimes",dime);
                }
                if(quarter==0&&dime==1){ //checks there are NO quarters and some dimes
                    printf("1 dime");
                }
                if(quarter==0&&dime>1){
                    printf("%d dimes",dime);
                }
                if(quarter>0||dime>0){ //when there are quarters and dimes
                   if(needPrintPenny==true&&nickel==1){ //checks if there are pennies still to be printed
                        printf(", 1 nickel");
                   }
                   if(needPrintPenny==false&&nickel==1){ //when there are no pennies to be printed, thus nickels are the last type
                        printf(", and 1 nickel");
                   }
                }
                if(quarter>0||dime>0){
                    if(needPrintPenny==true&&nickel>1){ //more than 1 nickel
                        printf(", %d nickel",nickel);
                    }
                    if(needPrintPenny==false&&nickel>1){
                        printf(", and %d nickels",nickel);
                    }        }
                if(quarter==0&&dime==0){ //when nickel is the first type to be printed
                    if(nickel==1){
                        printf("1 nickel");
                    }
                }
                if(quarter==0&&dime==0){
                    if(nickel>1){
                        printf("%d nickels",nickel);
                   }
                }
                if(quarter>0||dime>0||nickel>0){ //same as above with pennies
                    if(penny==1){
                        printf(", and 1 cent");
                    }
                }
                if(quarter>0||dime>0||nickel>0){
                    if(penny>1){
                        printf(", and %d cents",penny);
                    }
                }
                if(quarter==0&&dime==0&&nickel==0){ //when pennies are the only type to be printed
                    if(penny==1){
                        printf("1 cent");
                    }
                }
                if(quarter==0&&dime==0&&nickel==0){
                    if(penny>1){
                        printf("%d cent",penny);
                    }
                }
            }
            printf(".\n");
            quarter = 0;
            dime = 0;
            nickel = 0;
            penny = 0;
            types = 0;
            needPrintQuarter = false;
            needPrintDime = false;
            needPrintNickel = false;
            needPrintPenny = false;
            printf("Please give an amount in cents less than 100: "); //keeps repeating as long as the input is valid
            scanf("%d",&change);
            initChange = change;
        }
        printf("Goodbye.");
    }
    return 0;
}
