/*
Exercise 2.4
Write an alternate versiom of squeeze(s1,s2) that delete each character in s1 that matches 
any character in s2.
*/
#include<stdio.h>
void main()
{
	char c;
	char s1[10],s2[10];
	int i=0,j,k,r,flag=0;
	clrscr();
	while((s1[i++]=getchar())!='\n');
	i--;
	j=i;
	i=0;
	while((s2[i++]=getchar())!='\n');
	i--;
	k=i;
	i=0;
	while(i!=j)
	{
	     flag=0;
	     for(r=0;r!=k;r++)
	     {
		if(s1[i]==s2[r])
		{
			flag=1;
			break;
		}
	     }
	     if(flag==0)
	     printf("%c",s1[i]);
	     i++;
	}
       getch();
}
