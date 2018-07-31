#include<iostream>
#include <stdlib.h>
using namespace std;
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
        cout<<"\nLinked List is Empty	"<<endl;
        return;
    }

    struct node *p;
    p = start;
    cout<<"\nElements of Linked list are: "<<endl;
    while (p != NULL)
    {
        cout<<" "<<p->data<<" -> ";
        p = p->next;
    }
    cout<<"NULL";
}

int main()
{
	int ch, data;
	while(ch!=4)
	{
		cout<<"\nMenu:\n";
		cout<<"1. Show Linked List\n";
		cout<<"2. Insert element at start of Linked List\n";
		cout<<"3. Insert element at end of Linked List\n";
		cout<<"4. Exit\n";
		cout<<"Enter Your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1: showData();
					break;
			case 2: cout<<"\nEnter data to insert: ";
					cin>>data;
					insertAtStart( data);
					break;
			case 3: cout<<"\nEnter data to insert: ";
					cin>>data;
					insertAtEnd(data);
					break;
			case 4:break;
			default: cout<<"\n!!!!Wrong choice!!!!";
		}
	}
	return 0;
}