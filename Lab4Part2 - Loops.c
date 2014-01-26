//Shimeng Cui
//The user inputs a list of numbers ending with a negative number. The program takes those numbers and outputs the number of terms, max, min, mean and standard deviation
#include <stdio.h>
#include <math.h>

int main(void)
{
    int count = 0; //number of terms
    float num1 = 0; //first element of the standard deviation formula
    float num2 = 0; //second element of the standard deviation formula
    float max = 0; //largerst number
    float min = 0; //smallest number
    float std = 0; //standard deviation
    float input; //user input
    char c = 'a'; //place for the space behind each entered term
    printf("Please enter a list of numbers ending with a negative number.\n");
    scanf("%f",&input);
    if(input<0){ //when the first entered number is less than 0
        printf("N = 0, no statistics can be calculated!");
    }
    else{
        max = input; //sets max and min equal for the first round
        min = input;
        while(input>=0){ //while input is greater than or equal to 0
            num1 += input*input; //adds input squared to num1 to get summation
            num2 += input; //adds input to num2 for summation
            count+=1; //adds to term count
            if(input<min){ //checks if the current input is smaller than the current min
                min = input; //if so, the current number is the new min
            }
            if(input>max){ //vice versa of above for max
                max = input;
            }
            scanf("%f",&input); //reads next number
            scanf("%c", &c); //takes up the space after the number
        }
        if(count == 1){ //when there is only 1 term, this must be done or else the program would divide by 0 because of count-1 and count is 1
            printf("N = 1, min = %.2f, max = %.2f, mean = %.2f, std = Undefined",min,max,(num2/count));
        }
        else{ //when there is more than 1 term
            std = sqrt((num1-((num2*num2)/count))/(count-1)); //calculate standard deviation
            printf("N = %d, min = %.2f, max = %.2f, mean = %.2f, std = %.2f",count,min,max,(num2/count),std);
        }
    }
    return 0;
}
