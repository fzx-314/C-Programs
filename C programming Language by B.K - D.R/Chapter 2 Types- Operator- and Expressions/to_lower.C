/*
  Exercise 2-10
  Rewrite the function lower, which converts upper case letters to lower case,
  with a conditional expression instead of if-else 
*/
#include<stdio.h>
#include<ctype.h>
int main(void) {
	int c;
	while((c=getchar())!=EOF)
	    c=(isupper(c))?putchar(tolower(c)):putchar(c);
	return 0;
}

//Without Using Standard Library Function 

#include<stdio.h>
int main(void) {
	int c;
	while((c=getchar())!=EOF)
	    c=(c>='A'&&c<='Z')?putchar(c+32):putchar(c);  //c+32 difference between ASCII value of A and a
	return 0;
}
