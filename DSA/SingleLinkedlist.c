#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node* head=NULL;

void InsertionAtBeginning()
{
	int value;
	struct Node*newnode;

	newnode=(struct Node*)malloc(sizeof(struct Node));

	printf("Enter the value to InsertAtBeginning: ");
	scanf("%d",&value);

	newnode->data=value;
	newnode->next=head;
	head=newnode;
}

void InsertionAtEnd()
{
	int value;
	struct Node*newnode;

	newnode=(struct Node*)malloc(sizeof(struct Node));

	printf("Enter the value to InsertAtEnd: ");
	scanf("%d",&value);

	newnode->data=value;
	newnode->next=NULL;

	if(head==NULL)
	{
		head=newnode;
		printf("It is inserted as first node");
		return;
	}

	struct Node*temp=head;

	while(temp->next !=NULL)
	{
		temp=temp->next;
	}

	temp->next=newnode;
}

void InsertionAtPosition()
{
	int pos,value;
	struct Node*newnode;

	printf("Enter the value to InsertAtPosition: ");
	scanf("%d",&value);

	printf("Enter the position to insert: ");
	scanf("%d",&pos);

	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=value;

	if(pos==1)
	{
		newnode->next=head;
		head=newnode;
		return;
	}

	struct Node*temp=head;

	for(int i=1;i<pos-1;i++)
	{
		if(temp==NULL)
		{
			printf("position is out of range");
			free(newnode);
			return;
		}

		temp=temp->next;
	}

	if(temp==NULL)
	{
		printf("position is out of range");
		free(newnode);
		return;
	}

	newnode->next=temp->next;
	temp->next=newnode;
}

void DeletionAtBeginning()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}

	struct Node*temp=head;
	int value=temp->data;

	head=head->next;
	free(temp);

	printf("Deleted node at beginning is : %d\n",value);
}

void DeletionAtEnd()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}

	if(head->next==NULL)
	{
		int value=head->data;

		free(head);
		head=NULL;

		printf("The deleted at end is : %d\n",value);
		return;
	}

	struct Node*temp=head;

	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}

	struct Node*deletenode;

	deletenode=temp->next;
	int value=deletenode->data;

	temp->next=NULL;
	free(deletenode);

	printf("The deleted node at end is : %d\n",value);
}

void DeletionAtPosition()
{
	int pos;

	printf("Enter the position to delete: ");
	scanf("%d",&pos);

	if(head==NULL)
	{
		printf("List is empty");
		return;
	}

	struct Node*temp=head;

	if(pos==1)
	{
		int value=temp->data;

		head=head->next;
		free(temp);

		printf("Deleted node is : %d\n",value);
		return;
	}

	for(int i=1;i<pos-1;i++)
	{
		if(temp==NULL || temp->next==NULL)
		{
			printf("position is out of range");
			return;
		}

		temp=temp->next;
	}

	if(temp==NULL || temp->next==NULL)
	{
		printf("position is out of range");
		return;
	}

	struct Node*deletenode;

	deletenode=temp->next;
	int value=deletenode->data;

	temp->next=temp->next->next;
	free(deletenode);

	printf("After deletion at position node is : %d\n",value);
}

void Display()
{
	struct Node *temp=head;

	if(head==NULL)
	{
		printf("List is empty");
		return;
	}

	printf("Linked list is : \n");

	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}

	printf("NULL\n");
}

int main()
{
	InsertionAtBeginning();
	InsertionAtBeginning();
	InsertionAtBeginning();

	Display();

	InsertionAtEnd();
	Display();

	InsertionAtPosition();
	Display();

	DeletionAtBeginning();
	Display();

	DeletionAtEnd();
	Display();

	DeletionAtPosition();
	Display();

	return 0;
}