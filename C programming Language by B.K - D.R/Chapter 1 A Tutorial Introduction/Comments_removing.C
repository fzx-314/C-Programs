/*
  Write a program to remove all comments from a C program.
  Don't forget to handle quoted strings and character constants properly.
  C comments do not nest.
/*
#include <stdio.h>
int main(void) {
    int a[1000],i=0,k,nc=0;
    while((a[i++]=getchar())!=EOF);
    i--;
    k=i;
    i=0;
    while(i!=k)
    {
        if(a[i]=='/'&&a[i+1]=='/'&&a[i-1]!='"')
            while(a[i]!='\n')
                i++;
        else if(a[i]=='/'&&a[i+1]=='*'&&a[i-1]!='"')
        {
            nc=1;
            while(nc!=0)
            {
                i=i+2;   // To avoid an particular case i.e /*/ since "/*" is valid start and "/* is valid end"
                if(a[i]=='*'&&a[i+1]=='/')
                    nc=0;
                else
                    i++;
            }
            i=i+2; //For Proper termination
        }
        else
            printf("%c",a[i++]);
    }
	return 0;
}
