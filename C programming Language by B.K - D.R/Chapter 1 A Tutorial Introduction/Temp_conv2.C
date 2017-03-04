/*
  Exercise 1-4
  Write a program to print the corresponding Celsius to Farenheit table
*/
#include<stdio.h>
void main()
{ 
    float fahr, celcius;
    int lower, upper, step;
    lower = 0;
    upper = 200;
    step = 10;
    celcius = lower;
    printf("CELCIUS\tFAHRENHEIT\n");
    while (celcius <= upper)
    { 
        fahr = (9.0/5.0) * celcius + 32.0;
        printf(" %6.1f\t %3.0f\n", celcius, fahr);
        celcius = celcius + step;
    }
}
