//Shimeng Cui
//This program takes a X and Y coordinate input from the user, rounds it to 2 decimal places and tells the user which quadrant the point is in or whether it is on the X or Y axis or at the origin.
#include <stdio.h>
#include <math.h>

int main(void)
{
    const double PRECISION = 0.01; //rounds to the hundredth digit
    double inputX, inputY; //original input from user
    double roundX, roundY; //user input rounded to 2 decimal places
    printf("Enter the x-coordinate in floating point: ");
    scanf("%lf", &inputX); //scans x coordinate
    roundX = rint(inputX/PRECISION)*PRECISION; //divides by 0.01 to shift decimal place right 2 places and rounds to nearest integer. Then it multiplies by 0.01 to shift decimal place left 2 to the original position to get the rounded number
    printf("Enter the y-coordinate in floating point: ");
    scanf("%lf", &inputY); //scans y coordinate
    roundY = rint(inputY/PRECISION)*PRECISION; //same as above but with y coordinate
    if(roundX == 0||roundY == 0){ //when either x or y is 0
        if(roundX == 0 && roundY == 0){ //when both x and y are 0
            printf("(0.00, 0.00) is at the origin.");
        }
        else{ //when only 1 of x or y is 0
            if(roundX == 0){ //if x coordinate is 0
                printf("(%0.2lf, %0.2lf) is on the y axis.", roundX, roundY);
            }
            else{ //when y coordinate is 0
                printf("(%0.2lf, %0.2lf) is on the x axis.", roundX, roundY);
            }
        }
    }
    if(roundX != 0 && roundY !=0){ //when both x and y are NOT 0
        if(roundX>0&&roundY>0){ //when both x and y are greater than 0
            printf("(%0.2lf, %0.2lf) is in quadrant I.", roundX, roundY);
        }
        if(roundX<0&&roundY>0){ //when x is less than 0 and y is greater than 0
            printf("(%0.2lf, %0.2lf) is in quadrant II.", roundX, roundY);
        }
        if(roundX<0&&roundY<0){ //when both x and y are less than 0
            printf("(%0.2lf, %0.2lf) is in quadrant III.", roundX, roundY);
        }
        if(roundX>0&&roundY<0){ //when x is greater than 0 and y is less than 0
            printf("(%0.2lf, %0.2lf) is in quadrant IV.", roundX, roundY);
        }
    }
    return 0;
}
