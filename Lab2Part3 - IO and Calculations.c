//Shimeng Cui
//The user inputs information about a loan (e.g. interest rate, finance term, down payment, etc) and the program will calculate the monthly payment rounded to 2 decimal places
#include <stdio.h>
#include <math.h>

int main(void)
{
    int price, dPayment, term; //purchase price, down payment and term length
    double rate, mPayment; //monthly rate and monthly payment
    printf("Enter the purchase price P: ");
    scanf("%d",&price); //gets purchase price from user
    printf("Enter the amount of down payment D: ");
    scanf("%d",&dPayment); //gets amount of down payment from user
    printf("Enter the finance term (in months): ");
    scanf("%d",&term); //get fincance term in months from user
    printf("Enter the monthly interest rate (in percent): ");
    scanf("%lf",&rate); //gets monthly rate (as a percentage) from user
    rate/=100; //changes percentage to decimal
    mPayment = ((price-dPayment)*rate*pow((1+rate),term))/(pow((1+rate),term)-1); //calculates the monthly payment using the given formula. pow(x,y) raises x to the yth power
    printf("The monthly payment is: %0.2lf",mPayment); //prints monthly payment rounded to 2 decimal places
    return 0;
}
