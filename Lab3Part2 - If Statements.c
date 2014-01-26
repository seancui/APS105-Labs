//Shimeng Cui
//Takes a threshold and temperature input from the user. If the temperature given is within a number of degrees (determined by the threshold) from the boiling point of a known substance, it outputs the substance
#include <stdio.h>

int main(void)
{
    const int WATER = 100; //boiling points of the known substances
    const int MERCURY = 357;
    const int COPPER = 1187;
    const int SILVER = 2193;
    const int GOLD = 2660;
    int threshold; //threshold
    int boil; //input boiling point
    printf("Enter the threshold in celsius: ");
    scanf("%d", &threshold); //scans the threshold from user
    printf("Enter the observed boiling point in celsius: ");
    scanf("%d", &boil); //scans the user given temperature
    if(WATER-threshold<=boil&&boil<=WATER+threshold){ //the given temperature is within the threshold. Found by adding or subtracting threshold from known boiling points
        printf("The substance you tested is: Water"); // if it is water, it outputs "water"
    }
    else if(MERCURY-threshold<=boil&&boil<=MERCURY+threshold){ //same as above but with mercury's boiling point
        printf("The substance you tested is: Mercury");
    }
    else if(COPPER-threshold<=boil&&boil<=COPPER+threshold){ //same as above but with copper's boiling point
        printf("The substance you tested is: Copper");
    }
    else if(SILVER-threshold<=boil&&boil<=SILVER+threshold){ //same as above but with silver's boiling point
        printf("The substance you tested is: Silver");
    }
    else if(GOLD-threshold<=boil&&boil<=GOLD+threshold){ //same as above but with gold's boiling point
        printf("The substance you tested is: Gold");
    }
    else{
        printf("Substance unknown."); //if the given temperature is not within the threshold, it outputs that the substance cannot be determined
    }
    return 0;
}
