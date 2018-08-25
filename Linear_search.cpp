#include<iostream>
using namespace std;
int main()
{
	int n,a[100],s,flag=0,i;
	cout<<"Enter size of array: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>a[i];
	}

	cout<<"\n\nEnter element to be search for: ";
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(a[i]==s)
			{
				flag++;
				break;
			}
	}
	if(flag==0)
	{
		cout<<s<<" not found!!\n";
	}
	else
	{
		cout<<s<<" found at index '"<<i<<"'\n";
	}
}