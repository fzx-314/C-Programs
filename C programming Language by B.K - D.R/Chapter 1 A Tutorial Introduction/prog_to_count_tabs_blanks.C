/*
  Exercise 1-8
  Write a program to count blanks,tabs,new line
*/
#include <stdio.h>

int main(void) {
	int c,nl=0,b=0,t=0;
	while((c=getchar())!=EOF)
	{
	    switch(c)
	    {
	        case '\t':t++;
	                  break;
	        case ' ':b++;
	                 break;
	        case '\n':nl++;
	                  break;
	    }
	}
	printf("Blank=%d,Tabs=%d,New Line=%d",b,t,nl);
	return 0;
}
