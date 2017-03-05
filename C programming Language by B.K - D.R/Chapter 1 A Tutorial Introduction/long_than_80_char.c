/*
  Exercise 1-17
  Write a program to print all input lines that are longer than 80 characters
*/
#include <stdio.h>

int main(void) {
    int a[1000],i=0,ch=0,c,k;
    while((c=getchar())!=EOF)
    {
        if(c!='\n')
        {
            a[i++]=c;
            ch++;
        }
        else if(c=='\n'&&ch>80)
        {
            i--;
            k=i;
            i=0;
            while(i!=k)
                printf("%c",a[i++]);
            printf("\n");
            i=0;
            ch=0;
        }
        else if(c=='\n'&&ch<=80)
        {
            i=0;
            ch=0;
        }
    }
	return 0;
}
