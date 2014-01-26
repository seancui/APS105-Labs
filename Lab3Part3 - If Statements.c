//Shimeng Cui
//The program will take an input from the user as mass (in kilograms or pounds) and height (in inches, feet or meters), calculates the Body Mass Index (BMI), rounds it to the nearest tenth, and outputs whether the person is severely underweight, underweight, normal, overweight or obese
#include <stdio.h>
#include <math.h>

int main(void)
{
    const double PRECISION = 0.1; //allows for precision of 1 decimal place
    double mass; //mass of user
    char massType; //mass type (lb or kg) stored as a character
    double height; //height of user
    char heightType; //height type (in, ft or mt) stored as a character
    double bmi; //calculated BMI
    char ul; //needed to store second character of weight identifier
    printf("Enter the body weight: ");
    scanf("%lf%c%c",&mass,&massType,&ul); //scans the user's weight and stores it as mass. Scans first character of the weight type and stores it to massType. Stores second character as ul.
    printf("Enter the height: ");
    scanf("%lf%c",&height,&heightType); //scans the user's height. Scans first character of height identifier and stores it to heightType
    if(massType == 'l'){ //if the massType and thus first character of the weight type identifier is "l", it is in pounds
        mass*=0.4536; //converts pounds to kilograms (kg needed for BMI calculation)
    }
    if(heightType == 'f'){ //if the heightType and thus first character of the height type identifier is "f", it is in feet
        height/=3.28; //converts feet to meters (meters needed for BMI calculation)
    }
    if(heightType == 'i'){ //if the heightType and thus first character of the height type identifier is "i", it is in inches
        height/=39.37; //converts inches to meters (meters needed for BMI calculation)
    }
    bmi = rint((mass/(height*height))/PRECISION)*PRECISION; //calculates BMI using the formula and then rounds it to 1 decimal place. Divides by 0.1 to shift decimal place right 1 place and rounds to nearest integer. Then it multiplies by 0.1 to shift decimal place left 1 to the original position to get the rounded number
    printf("The Body Mass Index (BMI) is: %0.1lf\n",bmi); //prints the BMI
    if(bmi<16.5){ //outputs the correct weight status based on the rounded BMI value
        printf("Category: Severely underweight");
    }
    if(bmi>=16.5&&bmi<=18.4){
        printf("Category: Underweight");
    }
    if(bmi>=18.5&&bmi<=24.9){
        printf("Category: Normal");
    }
    if(bmi>=25.0&&bmi<=29.9){
        printf("Category: Overweight");
    }
    if(bmi>=30.0){
        printf("Category: Obese");
    }
    return 0;
}
