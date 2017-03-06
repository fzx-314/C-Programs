/*
  Exercise 2-5
  Write the function any(s1,s2) , which returns the first location in the string s1 where any character from the string s2 occurs,
  or -1 if s1 contains no characters from s2 .
  (The standard library function strpbrk does the same job but returns a pointer to the location.)
*/
#include <stdio.h>
int main(void) {
	int c,s1[20],s2[20],i=0,k1,k2,j,f=0;
	while((s1[i++]=getchar())!='\n');
	i--;
	k1=i;
	i=0;
	while((s2[i++]=getchar())!=EOF);
	i--;
	k2=i;
	i=0;
	for(i=0;i<=k1;i++)
	    for(j=0;j<=k2;j++)
	   {
	       if(s1[i]==s2[j])
	       {
	        printf("%d",i+1);
	        f=1;
	       }
	   }
	  if(f==0)
	    printf("-1");
	return 0;
}
