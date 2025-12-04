
#include <iostream>
using namespace std;
int main() {
    int n, value;
    cout<<"Enter the array size:";
    cin>>n;
    cout<<"enter array value:";
    int arr[n+1];
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
    cout<<"Enter the element value :";
    cin>>value;
    arr[n]=value;
    for(int i=0;i<n+1;i++)
    {cout<<arr[i]<<" ";}
    return 0;
}
