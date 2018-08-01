#include <stdlib.h>
#include<stdio.h>

struct node
{
	struct node* next;
	int data;
}*start;

void insertAtStart(int x)
{
	struct node *p= (struct node*) malloc(sizeof(struct node));
	if(p==NULL)
	{
		//memory gets full
		exit(0);
	}

	p->data=x;
	if(start == NULL)
	{
		p->next=NULL;
		start=p;
	}
	else
	{
		p->next=start;
		start=p;
	}
}

void insertAtEnd(int x)
{
	struct node *p= (struct node*) malloc(sizeof(struct node));
	struct node *t;
	if(p==NULL)
	{
		//memory gets full
		exit(0);
	}
	
	p->data=x;
	if(start == NULL)
	{
		p->next=NULL;
		start=p;
	}
	else
	{
		t=start;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=p;
	}
	
}

void showData()
{
    if (start == NULL)
    {
        printf("\nLinked List is Empty	\n");
        return;
    }

    struct node *p;
    p = start;
    printf("\nElements of Linked list are: \n");
    while (p != NULL)
    {
        printf(" %d  -> ",p->data);
        p = p->next;
    }
    printf("NULL");
}

int main()
{
	int ch, data;
	while(ch!=4)
	{
		printf("\nMenu:\n");
		printf("1. Show Linked List\n");
		printf("2. Insert element at start of Linked List\n");
		printf("3. Insert element at end of Linked List\n");
		printf("4. Exit\n");
		printf("Enter Your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: showData();
					break;
			case 2: printf("\nEnter data to insert: ");
					scanf("%d",&data);
					insertAtStart( data);
					break;
			case 3: printf("\nEnter data to insert: ");
					scanf("%d",&data);
					insertAtEnd(data);
					break;
			case 4:break;
			default: printf("\n!!!!Wrong choice!!!!");
		}
	}
	return 0;
}
