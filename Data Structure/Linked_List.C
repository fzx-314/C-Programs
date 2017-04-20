#include<stdio.h>
struct node{
	int data;
	struct node *next;
}*head;
void add(int num){
		struct node *temp;
		struct node *last;
		last=(struct node*)malloc(sizeof(struct node));
		temp=head;
		if(temp==NULL){
			last->data=num;
			head=last;
			last->next=NULL;

		}
		else{
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=last;
			last->data=num;
			last->next=NULL;
		}
}
void print()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void delete(int num)
{
	struct node *temp;
	struct node *previous;
	temp=head;
	if(temp->data==num){
	printf("%d Deleted\n",num);
	if(temp->next==NULL)
		head=NULL;
	else
		head=head->next;
	}
	else{
		while(temp!=NULL){
			if(temp->data!=num){
			previous=temp;
			temp=temp->next;
			}
			else
				break;
		}
		if(temp->data==num&&temp->next==NULL){
			previous->next=NULL;
			temp=NULL;
			printf("%d deleted\n",num);
		}
	    else if(temp->data==num&&temp->next!=NULL){
			previous->next=temp->next;
			temp=NULL;
			printf("%d deleted\n",num);
	    }
	    else if(temp==NULL)
	        printf("Element not found");
	}
}
int main(){
	int choice,num;
	head=(struct node*)malloc(sizeof(struct node));
	head=NULL;
	while(1){
	printf("1)Insert\n2)Delete\n3)Print\n4)Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:printf("\nEnter Data:");
			   scanf("%d",&num);
			   add(num);
			   break;
		case 2:if(head==NULL)
			   printf("Underflow\n");
			   else{
					printf("Enter Element you want to delete:");
					scanf("%d",&num);
					delete(num);
			   }
			   break;
		case 3:if(head==NULL)
				printf("List is empty");
			    else{
					printf("Content of list are\n");
					print();
				}
			    break;
		case 4:return 0;
		default: printf("Invalid Choice");
		}
	}
}
