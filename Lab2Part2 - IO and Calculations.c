//Shimeng Cui
//This program takes an user input of a 4 digit number and returns the decrypted version of that number.
#include <stdio.h>

int main(void)
{
    int encrypted; //encrypted code
    int digit1, digit2, digit3, digit4; //individual digits of the code
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d",&encrypted); //gets encrypted version of the code
    digit1 = (encrypted-(encrypted%1000))/1000; //encrypted%1000 returns the remainder of encrypted/1000. Subtract this from encrypted to get a multiple of 1000. Then divide by 1000 to get the thousands digit.
    encrypted = encrypted%1000; //gets the remainder which in essence removes the thousands digit
    digit2 = (encrypted-(encrypted%100))/100; //same as above but for hundreds digit
    encrypted = encrypted%100;
    digit3 = (encrypted-(encrypted%10))/10; //same as above but for tens digit
    encrypted = encrypted%10;
    digit4 = encrypted; //remainder is the ones digit
    printf("The real combination is: %d%d%d%d", digit4, 9-digit2, 9-digit3, digit1); //switches thousands and ones digit and subtracts digit2 and digit3 from 9 to get their real values
    return 0;
}
