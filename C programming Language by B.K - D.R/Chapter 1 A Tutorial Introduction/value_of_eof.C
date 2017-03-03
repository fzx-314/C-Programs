/*
Exercise 1-7
Write a Program to Print the value of EOF
*/
#include <stdio.h>

int main(void) {
	int c;
	int s;
	c=getchar();
	while(c!=EOF)
	{
	    c=getchar();
	    s=EOF;
	}
	printf("\n%d",s);
	return 0;
}
