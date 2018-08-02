#include <stdlib.h>
#include<stdio.h>
//using namespace std;
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

void deleteAtStart(int x)
{
	struct node *p;

	if(start != NULL)
	{
		p=start;
		start= start->next;
		free(p);
	}
	else
	{
		printf("Underflow!!!!\n");
	}
}

void deleteAfterX( int x)
{
	struct node *p, *t;
	t=start;

	if(start==NULL)
	{
		printf("Underflow!!!\n");
	}
	else
	{
		while(t->data!=x && t->next!=NULL)
		t=t->next;

		if(t->data==x)
		{
			p=t->next;
			t->next=p->next;
			free(p);
		}
		else
		{
			printf("\n%d not found!!",x);
		}
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
	while(ch!=6)
	{
		printf("\nMenu:\n");
		printf("1. Show Linked List\n");
		printf("2. Insert element at start of Linked List\n");
		printf("3. Insert element at end of Linked List\n");
		printf("4. Delete element at start of Linked List\n");
		printf("5. Delete element after element 'x'\n");
		printf("6. Exit\n");
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
			case 4: deleteAtStart(data);
					break;
			case 5: printf("\nEnter value of 'x': ");
					scanf("%d",&data);
					deleteAfterX(data);
					break;
			case 6:break;
			default: printf("\n!!!!Wrong choice!!!!");
		}
	}
	return 0;
}