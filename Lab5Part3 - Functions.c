//Shimeng Cui
//This program gets the date, month and year for the user and and outputs what day of the week that date was on
#include <stdio.h>

void inputDate(int *day, int *month, int *year){ //gets day, month and year from user and changes those in the main using pointers
    int d,m,y;
    printf("Please enter a date: ");
    scanf("%d/%d/%d",&d,&m,&y);
    *day = d; //assigns the variables in the main to the user's inputs
    *month = m;
    *year = y;
}

void calculateDay(int day, int month, int year){
    int modYear = year; //the year if it needed changing. E.g. when it is January or Febuary, the year goes down by 1
    int A,B,C,D,W,X,Y,Z,R;
    if((month-2)>=1){ //when it's not January or Febuary
        A = month-2; //subtracts 2 from month, thus making March month 1
    }
    else{ //it is January or Febuary
        modYear -= 1;
        if((month-2)==0){ //when Feb, month will be 12
            A = 12;
        }
        if((month-2)==-1){ //when Jan., month will be 11
            A = 11;
        }
    }
    B = day; //following formula
    C = modYear%100;
    D = modYear/100;
    W = (13*A-1)/5;
    X = C/4;
    Y = D/4;
    Z = W+X+Y+B+C-(2*D);
    R = Z%7;
    if(R<0){
        R+=7;
    }
    printf("The day %d/%d/%d is a ",day,month,year);
    if(R==0){
        printf("Sunday."); //according to the remainder, the day of week is decided with Sunday being remainder 0
    }
    if(R==1){
        printf("Monday.");
    }
    if(R==2){
        printf("Tuesday.");
    }
    if(R==3){
        printf("Wednesday.");
    }
    if(R==4){
        printf("Thursday.");
    }
    if(R==5){
        printf("Friday.");
    }
    if(R==6){
        printf("Saturday.");
    }
}
