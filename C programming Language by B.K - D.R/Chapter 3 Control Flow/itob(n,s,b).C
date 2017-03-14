/*
   Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
   In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
*/
#include<stdio.h>
#include<ctype.h>
char s[10];
void itob(int n,char s[],int b)
{
    int i=0;
    if(b<2||b>36)
        printf("Error");
    else
    {
        while(n)
        {
            s[i++]=n%b;
            n=n/b;
        }
    }
    i--;
    while(i>=0)
    {
        if(s[i]>=10)
            printf("%c",(65+(s[i--]-10)));
        else if(s[i]<=9&&s[i]>=0)
            printf("%c",(s[i--]));
    }
}
int main(void) {
	int n,b;
	scanf("%d,%d",&n,&b);
	itob(n,s,b);
	return 0;
}


Another Version
#include <stdio.h>
#include <math.h>
void convert (long n, char s[], int b);
void main()
{
	long n;
	int b;
	char s[20];
	printf("Enter the number upto 5 digits:\n");
	scanf("%ld", &n);
	printf("Enter the base within 16 :\n");
	scanf("%d", &b);
	convert (n, s, b);
}

void convert (long n, char s[], int b)
{
	long i=0,x=0,y,p;
	L1:
	i=(n/pow(b, x));
	if(i> 0)
	{
		++x;
		goto L1;
	}
	--x;
	y=x;
	while(x>=0)
	{
		p= pow(b,x);
		i= (n/p);
		if(i> 9)
		{
			s[y-x]= 64+  (i-9);
		}
		else
		s[y-x]= 48+i;
		--x;
		n= n % p;
	}
	s[y+1]= '\n';
	x=0;
	printf("\n\n");
	while(s[x]!='\n')
	{
		printf("%c", s[x]);
		++x;
	}
}
