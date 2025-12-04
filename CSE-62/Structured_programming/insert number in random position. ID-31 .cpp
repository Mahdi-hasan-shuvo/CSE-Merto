#include<iostream>
using namespace std;
int main ()
{
   int n,value,pos;
   cout<<"Enter Array size: ";
   cin >> n;
   int arr[n+1];
   cout<<"enter array: ";
   for (int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   cout<<"enter position : ";
   cin>>pos;
   while(pos<1||pos>n+1)
   {
       cout<<" invalid position";
       cout<<"again enter position";
       cin>>pos;
   }
   cout<<"enter the element value: ";
   cin>> value;
   int index=pos-1;
   for(int i=n-1;i>=index;i--)
   {
      arr[i+1]=arr[i];
   }
   arr[index]=value;
   for(int i=0;i<n+1;i++)
   {
       cout<<arr[i]<<" ";
   }
return 0;
}
