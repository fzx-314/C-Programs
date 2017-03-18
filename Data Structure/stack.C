#include <stdio.h>
int a[10],top=0;
void push(int x) //Push Element in Stack
{
    if(!isfull())  //Condition for Overflow
        printf("Stack is Full\n");
    else
        a[top++]=x;  //Pushing an element
}
int isfull()// Function to check overflow
{
    if(top<10)
        return 1;
    return 0;
}
void pop()
{
    if(isempty()) // Function to check underflow
        printf("Stack is Empty\n");
    else
    {
        printf("Element Removed is %d\n",a[top-1]);// Poping an element
        a[--top]=0;
    }
}
int isempty()  //Function to check if stack is empty or not
{
    if(top<=0)
        return 1;
    return 0;
}
int main(void) {
	int x,ch,temp;
	l1:printf("Which operation do you want to perform\n");//Basic function of stack
	printf("1)Push\n2)Pop\n3)Exit:");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:printf("Enter Element you want to push\n");
	           scanf("%d",&x);
	           push(x);
	           break;
	    case 2:pop();
	           break;
	    case 3:exit(0);
	   default:printf("Inalid case\n");
	           break;
	}
	printf("Want to perform some task? press 0 for yes and 1 to exit:");
	scanf("%d",&ch);
	if(ch==0)
	    goto l1;
	return 0;
}
