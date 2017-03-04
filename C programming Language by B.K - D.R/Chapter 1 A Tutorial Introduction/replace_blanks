/*
  Exercise 1-9
  Write a program to copy its input to its output, replacing string of one or more blank by a single blank
*/
#include <stdio.h>
#include <ctype.h>
int main(void) {
    int c,flag=0;
    while((c=getchar())!=EOF)
    {
        if(c!=' ')
        {
            putchar(c);
            flag=1;
        }
        else if(flag==1&&c==' ')
        {
            printf(" ");
            flag=0;
        }
    }
	return 0;
}
