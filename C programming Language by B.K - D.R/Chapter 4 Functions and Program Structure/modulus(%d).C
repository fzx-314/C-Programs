/*
  Exercise 4-3
  Given the basic framework,it's straightforward to extend the calculator.
  Add the modulus(%d) operator and provisions for negative number.
*/
#include <stdio.h>
#include <math.h>
int main(void) {
	float a,b;
	int ch;
	printf("Enter two Numbers");
	scanf("%f,%f",&a,&b);
	printf("Press\n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n5)Modulus\n");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:printf("%f",a+b);
	           break;
	    case 2:printf("%f",a-b);
	           break;
	    case 3:printf("%f",a*b);
	           break;
	    case 4:printf("%f",a/b);
	           break;
	    case 5:printf("%f",fmod(a,b));
	           break;
	    default:printf("Inavlid choice");
	            exit(0);
	}
	return 0;
}
