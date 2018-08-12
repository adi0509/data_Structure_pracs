#include<iostream>
using namespace std;

int factRecursion(int x)
{
	if(x==1)
		return 1;
	else
		return x*factRecursion(x-1);
}

int factIteration(int x)
{
	int f=1;
	for(int i=x;i>0;i--)
	{
		f*=i;
	}
	return f;
}

void factorsRecursion(int n,int x)
{
	if(x==1)
		cout<<" 1 ";
	else
	{
		if(n%x==0)
			cout<<x<<" ";
		factorsRecursion(n,x-1);
	}
}

void factorsIteration(int x)
{
	cout<<"\nFactors are: ";
	for(int i=1;i<=x;i++)
	{
		if(x%i==0)
		{
			cout<<i<<" ";
		}
	}
}
int main()
{
	int n,ch;
	cout<<"Enter a number: ";
	cin>>n;
	while(1)
	{
		cout<<"\nMenu: ";
		cout<<"\n1. Enter a different number.";
		cout<<"\n2. Factorial using recursion.";
		cout<<"\n3. Factorial using iteration.";
		cout<<"\n4. Factors of given no. using recursion";
		cout<<"\n5. Factors of given no. using iteration";
		cout<<"\n6. Exit";
		cout<<"\nEnter Your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter no.: ";
					cin>>n;
					break;
			case 2: cout<<"Factorial using recursion: "<<factRecursion(n);
					break;
			case 3: cout<<"Factorial using iteration: "<<factIteration(n);
					break;
			case 4: cout<<"Factors are: ";
					factorsRecursion(n,n);
					break;
			case 5: factorsIteration(n);
					break;
			case 6: break;
			
			default: cout<<"Wrong choice!!!!!";
					 break;
		}
		if(ch==6)	
			break;	
	}
}