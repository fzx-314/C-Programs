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