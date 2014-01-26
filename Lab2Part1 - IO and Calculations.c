//Shimeng Cui
//This program takes an input of the daily rental rate and number of rental days from the user and outputs the number of free days and total charge of the rental
#include <stdio.h>

int main(void)
{
    const double HST = 1.13; //defines 1.13 (tex rate) as a constant
    double rate; //daily rental rate
    int days; //total rental days
    int freeDays; //number of free days (1 free day per 4 day period)
    printf("Enter the daily rate: ");
    scanf("%lf",&rate); //gets rental rate from user
    printf("Enter the rental period (in days): ");
    scanf("%d",&days); //gets total rental days from user
    freeDays = (days/4); //gets number of free days by dividing by 4. Because both days and freeDays are integers, it will give the lowest whole number quotient
    printf("Your total free day(s) in this rental is: %d\n",freeDays);
    printf("Your total charge including taxes is: %0.2lf",((days-freeDays)*rate)*HST); //finds total number of days with charge and finds the total charge before tax. Multiply by the constant HST (value 1.13) to find price after tax
    return 0;                                       //the %0.2lf rounds the final charge to 2 decimal places
}
