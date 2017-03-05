/*
  Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses,
  brackets and braces. Don't forget about quotes, both single and double, escape sequences,
  and comments. (This program is hard if you do it in full generality.) 
*/
#include <stdio.h>

int main(void) {
    int c,sb=0,cb=0,rb=0,dq=0,f=0,f1=0,sq=0;
    while((c=getchar())!=EOF)
    {
        switch(c)
        {
            case '[':sb++;
                    break;
            case ']':if(sb!=0)
                        sb--;
                    break;
            case '{':cb++;
                    break;
            case '}':if(cb!=0)
                        cb--;
                    break;
            case '(':rb++;
                    break;
            case ')':if(rb!=0)
                        rb--;
                    break;
        }
        if(c==34&&f==0) // ASCII value of Double Quote
        {
            f=1;
            dq++;
        }
        else if(c==34&&f==1)
        {
            f=0;
            dq--;
        }
        if(c==39&&f1==1)// ASCII value of Single Quote
        {
            f1=0;
            sq++;
        }
        else if(c==39&&f==0)
        {
            f1=1;
            sq--;
        }
    }
    if(rb==0&&cb==0&&sb==0&&dq==0&&sq==0)
        printf("No Syntax Errors");
    else
        printf("Error");
	return 0;
}
