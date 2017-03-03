/*
Exercise 1-19.
Write a function reverse(s) that reverse the character string s.
Use to write a program that reverse its input a line at a time
*/
#include<stdio.h>
void main()
{
	char a[10];
	int i=0;
	clrscr();
	while((a[i++]=getchar())!='\n');
	while(i)
		printf("%c",a[--i]);
	getch();
}
