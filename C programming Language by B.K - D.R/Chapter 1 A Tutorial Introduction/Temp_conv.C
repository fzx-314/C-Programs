/*
Exercise 1-3
Modify Tempature COnversion Program to Print a heading above table
*/
#include<stdio.h>
void main()
{ 
    float fahr, celcius; 
    int lower, upper, step; 
    lower = 0; 
    upper = 300; 
    step = 20; 
    fahr = lower; 
    printf("FAHRENHEIT\tCELCIUS\n"); 
    while (fahr <= upper) 
    { 
        celcius = (5.0/9.0) * (fahr - 32.0); 
        printf(" %3.0f\t %6.1f\n", fahr, celcius); 
        fahr = fahr + step;
    }
}
