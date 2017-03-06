/*
  Exercise 3-2
  Write a function escape(s,t) that converts characters like newline and tab into
  visible escape sequences like \n and \t as it copies the string t to s .
  Use a switch . Write a function for the other direction as well,
  converting escape sequences into the real characters. 
*/
#include<stdio.h>
#include<ctype.h>
int main(void) {
	int c;
	while((c=getchar())!=EOF)
	{
	    switch(c)
	    {
	        case '\n':printf("\\");
	                  printf("n\n");
	                  break;
	        case '\t':printf("\\");
	                  printf("t");
	                  break;
	        case ' ':printf("\\");
	                 printf("b");
	                 break;
	        default:putchar(c);
	    }
	}
	return 0;
}
