#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node*next;
	struct Node*prev;
};

struct Node*head=NULL;
void InsertionAtBeginning() 
{
	int value;
	struct Node*newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value to Insert at beginning: ");
	scanf("%d",&value);
	newnode->data=value;
	newnode->prev=NULL;
	if(head==NULL) 
	{
		printf("It is inserted as a first node");
		newnode->next=NULL;
		head=newnode;
		return;
	}
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}
void InsertionAtEnd() 
{
	int value;
	struct Node*newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value to Insert at beginning: ");
	scanf("%d",&value);
	newnode->data=value;
	newnode->next=NULL;
	if(head==NULL) 
	{
		printf("It is inserted as first node");
		newnode->prev=NULL;
		head=newnode;
		return;
	}
	struct Node*temp=head;
	while(temp->next!=NULL) 
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
void InsertionAtPosition() 
{
	int value,pos;
	struct Node*newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the value to Insert at beginning: ");
	scanf("%d",&value);
	printf("Enter the position to insert: ");
	scanf("%d",&pos);

	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=value;

	if(pos==1) 
	{
		newnode->prev=NULL;
		newnode->next=head;
		if(head!=NULL) 
		{
			head->prev=newnode;
		}
		head=newnode;
		return;
	}
	struct Node*temp=head;
	for(int i=1; i<pos-1; i++)
	{
		temp=temp->next;
	}
	if(temp==NULL) 
	{
		printf("position is out of range");
		return;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	if(temp->next!=NULL) 
	{
		temp->next->prev=neewnode;
	}
	temp->next=newnode;
}
void display()
{
	struct Node*temp=head;
	if(head==NULL)
	{
		printf("List is empty..\n");
		return;
	}
	printf("Linked list is..\n");
	while(temp!=NULL)
	{
		printf("%d<->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
