/* Insertion at end */
#include<stdio.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*head;
void insertL(int num){
	struct node *temp;
	struct node *last;
	temp=head;
	if(temp==NULL){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=temp;
		temp->prev=temp;
		head=temp;
	}
	else{
		last=(struct node *)malloc(sizeof(struct node));
		last->data=num;
		last->prev=temp->prev;
		temp->prev->next=last;
		last->next=temp;
		temp->prev=last;
	}
}
void search(int num){
		int f=0,c=0;
		struct node *temp;
		temp=head;
		while(temp->next!=head){
			c++;
			if(temp->data==num){
				printf("Element present at %d\n",c);
				f=1;
				break;
			}
			else
				temp=temp->next;
		}
		if(temp->data==num){
			printf("Element present at %d\n",c+1);
			f=1;
		}
		if(f==0)
			printf("Element not present\n");
}
void print(){
	struct node *temp;
	temp=head;
	printf("%d\t",temp->data);
	while(temp->next!=head){
	temp=temp->next;
	printf("%d\t",temp->data);
	}
	printf("\n");
}
void delete(int num){
	struct node *temp;
	struct node *temp1;
	temp=head;
	if(temp->data==num){
		if(temp->next==head)
			head=NULL;
	}
	else if(temp->data==num){
		if(temp->next->next==head){
		head=temp->next;
		head->next=head;
		head->prev=head;
	}
	}
	if(temp->data==num){
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		head=temp->next;
	}
	else{
		while(temp->next->data!=num)
			temp=temp->next;
		temp1=temp;
		temp=temp->next;
		temp1->next=temp->next;
		temp->next->prev=temp->prev;
		temp=NULL;
		temp->next=NULL;
		temp->prev=NULL;

	}
}
int main(){
		int num,choice;
		head=NULL;
		while(1){
		printf("1)Insert\n2)Delete\n3)Search\n4)Display\n5)Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter Element to insert:");
				   scanf("%d",&num);
				   insertL(num);
				   break;
			case 2:if(head==NULL)
						printf("Under flow");
				   else{
					   printf("Enter number to be deleted:");
					   scanf("%d",&num);
					   delete(num);
				   }
				   break;
			case 3:printf("Enter element to be searched:");
					scanf("%d",&num);
					search(num);
				   break;
			case 4:if(head==NULL)
						printf("List is empty\n");
					else{
						print();
					}
				   break;
			case 5:return 0;
			default:printf("Invalid choice\n");
				    break;
		}
		}
}
