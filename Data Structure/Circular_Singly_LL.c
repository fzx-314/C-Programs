#include<stdio.h>
struct node{
	int data;
	struct node *next;
}*head;
int insert(int x){
	struct node *temp;
	struct node *temp1;
	temp=head;
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node));
		head->data=x;
		head->next=head;
	}
	else{
		while(temp->next!=head)
			temp=temp->next;
		temp1=(struct node*)malloc(sizeof(struct node));
		temp1->data=x;
		temp->next=temp1;
		temp1->next=head;
	}
	return 0;
}
struct node *search(int x){
	struct node *temp;
	temp=head;
	do{
		if(temp->data==x)
			return temp;
		temp=temp->next;
	}while(temp!=head);
	return NULL;
}
int delete(int x){
	struct node *temp;
	struct node *temp1;
	temp=search(x);
	if(temp==NULL)
		printf("Element not present\n");
	else if(temp==head&&temp->next==head)
		head=NULL;
	else if(temp==head&&temp->next!=head){
		while(temp->next!=head)
			temp=temp->next;
		temp->next=head->next;
		head=head->next;
	}
	else{
		temp1=temp;
		while(temp1->next!=temp)
			temp1=temp1->next;
		temp1->next=temp->next;
	}
	return 0;
}
int display(){
	struct node *temp;
	temp=head;
	if(head!=NULL){
	    do{
		    printf("%d\t",temp->data);
		    temp=temp->next;
	    }while(temp!=head);
	}
	else
	    printf("List is empty");
	printf("\n");
	return 0;
}
int main(){
	int choice,x;
	struct node *temp;
	do{
		printf("1)Insert\n2)Delete\n3)Search\n4)Print\n5)Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
		case 1:printf("\nEnter Element:");
				scanf("%d",&x);
				insert(x);
				break;
		case 2:if(head==NULL){
		        printf("List is empty\n");
		            break;
		        }
		        printf("\nEnter element to delete:");
				scanf("%d",&x);
				delete(x);
				break;
		case 3:printf("\nEnter element to search:");
				scanf("%d",&x);
				temp=search(x);
				if(temp!=NULL)
					printf("%p\n",(void *)temp);
				else
					printf("Element not present\n");
				break;
		case 4:display();
				break;
		default:choice=5;
				break;
		}
	}while(choice!=5);
	return 0;
}
