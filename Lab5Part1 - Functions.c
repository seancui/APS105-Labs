//Shimeng Cui
//This program takes in an input of a number with 6 digits or more. It then adds 4 to each digit and shifts each digit left 1 space while the first digit is placed in the last digit position. The program then outputs the encrypted number.
#include <stdio.h>

void input(int *num){
    *num = 0; //sets the number equal to 0 to ensure that the program goes into the loop
    while(*num<=99999){ //makes sure that the number has 6 digits or more.
        printf("Please enter an integer greater than 99999: ");
        scanf("%d",num); //scans in input and gives it to pointer num
        if(*num<=99999){
            printf("Incorrect input.\n");
        }
        else{
            printf("The number entered is %d\n",*num);
        }
    }
}

int add4(int num){
    int cur = num; //the current number after each step
    int addNum = 0; //the number as each digit is being added to
    int multipier = 1; //the digit muliplies by this to get it to the right column
    while(cur>0){ //while the current number still has digits to add to
        if(((cur%10)+4)<10){
            addNum += (((cur%10)+4)*multipier); //if adding 4 to the number is less than 10, it muliplies and creates the digit in the right column
        }
        else{
            addNum += (((cur%10)-6)*multipier); //if adding 4 causes the number to be greater than 10, you subtract ten after adding 4. Same as subtracting 6.
        }
        cur /= 10; //takes out the ones column of the current number
        multipier *= 10; //increases multiplier
    }
    return addNum; //returns encrypted number

}

int shift(int num){
    int cur = num; //number after each step
    int shiftNum = 0; //keeps track of shifted number
    int multipier = 10; //gets digit in to the right column by multiplying by it. Starts at 10 to start with moving it left 1
    while(cur>0){ //while there are still digits in the number
        if(cur<10){
            shiftNum += cur; //if there is only 1 digit left, it puts it in the ones column
            cur /= 10;
        }
        else{
            shiftNum += (cur%10)*multipier; //otherwise it shifts it left
            cur /= 10; //cuts off ones digit
            multipier *= 10; //increase multiplier
        }
    }
    return shiftNum; //returns ecrypted number

}

void printOutput(int encryptNum, int originalNum){
    printf("Original number: %d\nEncrypted number: %d",originalNum,encryptNum); //prints out original number an totally encrypted number
}
