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
void insertAfterX(int y, int x)
{
	struct node *p, *t;
	p= (struct node*) malloc(sizeof(struct node));
	p->data=y;
	t=start;

	while(t->data!=x && t->next!=NULL)
		t=t->next;

	if(t->data==x)
	{
		p->next=t->next;
		t->next=p;
	}
	else
	{
		printf("\n%d not found!!",x);
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
	int ch, data, x;
	while(ch!=5)
	{
		printf("\nMenu:\n");
		printf("1. Show Linked List\n");
		printf("2. Insert element at start of Linked List\n");
		printf("3. Insert element at end of Linked List\n");
		printf("4. Insert After x: \n");
		printf("5. Exit\n");
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
			case 4: printf("\nEnter element after you want to insert a node: ");
					scanf("%d", &x);
					printf("\nEnter data to insert: ");
					scanf("%d",&data);
					insertAfterX(data, x);
					break;
			case 5:break;
			default: printf("\n!!!!Wrong choice!!!!");
		}
	}
	return 0;
}
