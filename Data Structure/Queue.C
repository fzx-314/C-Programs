#include <stdio.h>
#define size 10
int a[size],front=-1,rear=-1;   //Intialization of Queue and front,rear variables
int isfull()                    // Returns 1 when queue is full else return 0
{
    if(rear==size-1)
        return 1;
    return 0;
}
int isempty()                   //Return 1 is queue is empty else return 0
{
    if(front==rear)
        return 1;
    return 0;
}
void Enqueue()              // Function to add element in Queue
{
    int x;
    if(isfull())            // To check if queue is full or not
    {
        printf("Queue Full");
    }
    else
    {
        if(front==-1)       // Change variable as element is being inserted
            front=0;
        printf("Enter element:");
        scanf("%d",&x);
        ++rear;             // Since index starts from -1
        a[rear]=x;
        printf("\nElement inserted is %d\n",a[rear]);
    }
}
void Dequeue()          // To remove element from Queue
    {
        if(isempty())
        {
            printf("Queue is empty\n");
            front=rear=-1;
        }
        else
        {
            printf("Element Removed is %d\n",a[front]);
            front++;
        }
    }
void Display()      //Just another display function
{
    int i;
    if(rear==-1)
    {
        printf("Queue is Empty");
    }
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",a[i]);
        printf("\n");
    }
}
int main(void) {
	int ch;
	f1:printf("\n1)Enqueue\n2)Dequeue\n3)Display\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:Enqueue();
	           break;
	    case 2:Dequeue();
	           break;
	    case 3:Display();
	           break;
	    default:printf("Invalid choice\n");
	            break;
	}
	printf("press 1 to continue or any key to exit:");
	scanf("%d",&ch);
	if(ch==1)
	    goto f1;
	else
	    goto f2;
	f2:return 0;
}
