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
