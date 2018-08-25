#include<iostream>
using namespace std;
int binSearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  
            return mid;

        if (arr[mid] > x) 
            return binSearch(arr, l, mid-1, x);
 
        return binSearch(arr, mid+1, r, x);
   }
   return -1;
}

int main()
{
	int n,a[100],s,index=0,i;
	cout<<"Enter size of array: ";
	cin>>n;
	cout<<"Now enter sorted array elements";
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>a[i];
	}

	cout<<"\n\nEnter element to be search for: ";
	cin>>s;
	index=binSearch(a,0,n-1,s);
	if(index==-1)
	{
		cout<<s<<" not found!!";
	}
	else
	{
		cout<<s<<" found at index "<<index;
	}
}