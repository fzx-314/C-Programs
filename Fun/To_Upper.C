// Convert Each occurence of lower case character to upper case
#include<stdio.h>
#include<ctype.h>
void main()
{
	char c;
	clrscr();
	while((c=getchar())!='\n')
	{
		if(c>='a'&&c<='z')
			putchar(toupper(c));// can use tolower also
		else
			putchar(c);
	}
	getch();
}
