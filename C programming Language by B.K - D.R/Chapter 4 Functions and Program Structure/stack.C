/*
  Exercise 4-4
  Add commands to print the top element of the stack without popping,to duplicate it and to swap
  the top two elements. Add a comand to clear stack
*/
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
void istop() //To Display top element of stack
{
    printf("Element at top is %d\n",a[top-1]);
}
void isclear()  //To empty stack.
{
    while(isempty()!=1)
        pop();
}
int main(void) {
	int x,ch,temp;
	l1:printf("Which operation do you want to perform\n");//Basic function of stack
	printf("1)Push\n2)Pop\n3)Display Top\n4)Duplicate top Element\n5)swap top 2 elements\n6)Clear stack\n7)Exit:");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:printf("Enter Element you want to push\n");
	           scanf("%d",&x);
	           push(x);
	           break;
	    case 2:pop();
	           break;
	    case 3:istop();
	           break;
	    case 4:x=a[top-1];
	           push(x);
	           break;
	    case 5:temp=a[top-2];
	           a[top-2]=a[top-1];
	           a[top-1]=temp;
	           break;
	    case 6:isclear();
	           break;
	    case 7:exit(0);
	   default:printf("Inalid case\n");
	           break;
	}
	printf("Want to perform some task? press 0 for yes and 1 to exit:");
	scanf("%d",&ch);
	if(ch==0)
	    goto l1;
	return 0;
}
