/*
  Exercise 1-10
  Write a Program to copy its input to its output, replacing each tab by \t,
  each backspace by \b and each backslash by \\.This makes tabs and backaspace visible
  in an unambigious way.
*/
#include <stdio.h>
#include <ctype.h>
int main(void) {
    int c,flag=0,t='\t';
    while((c=getchar())!=EOF)
    {
        switch(c)
        {
            case '\t':printf("\\");
                      printf("t");
                      break;
            case ' ':printf("\\");
                     printf("b");
                     break;
            case '\\':printf("\\");
                     break;
            default:putchar(c);
        }
    }
	return 0;
}
