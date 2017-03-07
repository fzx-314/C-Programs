/*
  Exercise 4-1
  Write the function strrindex(s,t) ,
  which returns the position of the rightmost occurrence of t in s , or -1 if there is none. 
*/
#include<stdio.h>
void strrindex(char s[],char t)
{
    int i=0,k=-1;
    while(s[i]!='\0')
        if(s[i++]==t)
            k=i;
    printf("%d",k);
}
int main(void) {
	char s[100],t;
	strcpy(s,"Test String");
	scanf("%c",&t);
	strrindex(s,t);
	return 0;
}
