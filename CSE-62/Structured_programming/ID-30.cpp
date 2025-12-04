#include<iostream>
using namespace std;
int main()
{int n,value,position;
cout<<"Enter Array Size:";
cin>>n;
int arr[n+1];
cout<<"Enter Array:";
for(int i=0;i<n;i++)
{cin>>arr[i];}
cout<<"Enter the element value:";
cin>>value;
int index=0;
for(int i=n-1;i>=index;i--)
{ arr[i+1]=arr[i];
}
arr[index]=value;
for (int i=0;i<n+1;i++)
{cout<<arr[i]<<" ";}
return 0;
}
