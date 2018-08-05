#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* rp;
	struct node* lp;
	int data;
}*start;

void insertAtBegin(int d)
{
	struct node *t= (struct node*) malloc(sizeof(struct node));	
	t->data=d;
	t->lp=NULL;
	if(start==NULL)
	{
		t->rp=NULL;
		start=t;
	}
	else
	{
		t->rp=start;
		start->lp=t;
		start=t;
	}
}

void insertAfterX(int d, int x)
{
	struct node *t= (struct node*) malloc(sizeof(struct node));	
	struct node *p;
	t->data=d;

	//now we'll find x
	p=start;
	while(p!=NULL && p->data!=x)
	{
		//printf("\nthis loop runs\n");
		p=p->rp;
	}
	if(p->data==x && p->rp!=NULL && p->lp!=NULL)
	{
		t->rp= p->rp;
		t->lp= p;

		p->rp=t;
		p->rp->rp->lp=t;
	}
	else if(p->data==x && p->rp==NULL)
	{
		p->rp=t;
		t->lp=p;
		t->rp=NULL;
	}
	else if(p->data==x && p->lp==NULL)
	{
		p->lp=t;
		t->rp=p;
		t->lp=NULL;
		start=t;
	}
}

void showall()
{
	struct node*t;
	t=start;
	while(t!=NULL)
	{
		printf(" %d ->",t->data);
		t=t->rp;
	}
	printf("NULL");
}

int main()
{
	int ch=0;
	int data,x;
	while(ch!=4)
	{
		printf("\n\nMenu:\n");
		printf("1. Insert at begin\n");
		printf("1. Insert after x\n");
		printf("3. Show all\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: printf("Enter value to be inserted: ");
					scanf("%d",&data);
					insertAtBegin(data);
					break;
			case 2: printf("Enter value of 'x' after which data will be inserted: ");
					scanf("%d",&x);
					printf("Enter value to be inserted: ");
					scanf("%d",&data);
					insertAfterX(data,x);
					break;
			case 3: showall();
					break;
			case 4: break;

			default: printf("\n\n\t\t!!!!Wrong choice!!!!\n");
		}
	}
}