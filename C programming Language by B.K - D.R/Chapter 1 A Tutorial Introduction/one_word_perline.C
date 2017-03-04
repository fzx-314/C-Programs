/*
 Exercise 1-12
 Write a Program that prints its input one word per line
*/
#include <stdio.h>
int main(void) {
    int c,flag=0;
    while((c=getchar())!=EOF)
    {
        if(c!=' '&&c!='\t'&&c!='\n')
        {
            putchar(c);
            flag=1;
        }
        else if((c==' '||c=='\t'||c=='\n')&&flag==1)
        {
            printf("\n");
            flag=0;
        }
    }
	return 0;
}
