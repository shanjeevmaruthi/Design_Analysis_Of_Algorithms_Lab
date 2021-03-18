#include<iostream>

using namespace std;
int main()
{
    int n;
    cout<<"enter the number";
    cin>>n;
    int arr[100];
    int c=0;
    while(n)
    {
        arr[c]=n%10;
        n=n/10;
        c++;
    }
    for(int i=0;i<c;i++)
    {
         for(int j=0;j<c;j++)
               {cout<<arr[i]<<arr[j];
               cout<<endl;}
    }

}