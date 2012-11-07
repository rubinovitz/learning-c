#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int i;
 
// start loop at 0, iterate twice until i = 2

    int hour; int minute; int duration; int duration_m; int duration_h;
    hour= 0; minute = 0; duration= 0; duration_m = 0; duration_h = 0;

    // Get starting hour user input
    printf("Starting Hour: ");
    scanf("%i", &hour);

    // Get starting minute via user input
    printf("Starting minute: ");
    scanf("%i", &minute);

    // check if intue or hour is less than 10, if so, add zero before int when printing

    if (minute < 10){
        if (hour < 10) {
            printf("Starting time is 0%i:0%i, what is the duration? ",hour, minute);
        }            
        if (hour > 10){
        printf("Starting time is %i:0%i, what is the duration?  ",hour,minute);        

       }
  }

    else if (hour < 10){
        printf("Starting Time is 0%i:%i, what is the duration? ",hour,minute);
    }

    else{
        printf("Starting Time is %i:%i, what is the duration? ",hour,minute);
    }

    scanf("%i", &duration);
    int new_min;
    new_min = minute;
    for (i = 0; i < duration; i++){
        new_min = new_min + 1;
        if (new_min == 60){
            new_min = 0;
            hour = hour + 1;}
        if (hour == 25){
           hour = 1;
        }
    }

    minute = new_min;
  
    if (minute < 10){
        if (hour < 10) {
            printf("Ending  time is 0%i:0%i\n",hour, minute);
        }
        if (hour > 10){
        printf("Ending Time is %i:0%i\n",hour,minute);  

       }
  }

    else if (hour < 10){
        printf("Ending Time is 0%i:%i\n",hour,minute);
    }

    else{
        printf("Ending Time is %i:%i\n",hour,minute);
    }


// if (hour > 9 && minute < 10){ 
    //        printf("Ending Time is %i:0%i\n",hour,minute);}

     
      //  printf("Ending Time is 0%i:%i\n",hour,minute);
    
}
