#include<stdio.h>

#include<iostream>
#define size 10

//This is stack class, all functions are defined inside this class
class Stack
{
	int top;
	public:
		int s[size];
		Stack()
		{
			top=-1;
		}
		int push(int element);
		int pop();
};

	int Stack::push(int element)
	{
		if(top>10)
		{
			printf("Stack is overflow");
			return 0;
		}
		else
		{
			s[++top]=element;
			return 1;
		}
	}
	int Stack::pop()
	{
	    if (top < 0)
	    {
	        printf("Stack is Underflow");
	        return 0;
	    }
	    else
	    {
	        int y = s[top--];
	        return y;
	    }
	}

int main()
{
	Stack obj;
	obj.push(10);
	obj.push(20);
	obj.push(35);

	printf("%d popped from Stack\n", obj.pop());
	printf("%d popped from Stack\n", obj.pop());
	printf("%d popped from Stack\n", obj.pop());
	return 0;
}
