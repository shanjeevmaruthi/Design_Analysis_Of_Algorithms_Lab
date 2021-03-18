#include<iostream>
using namespace std;

int main()
{
     int arr[10];
    // {1,6,0,23,909,21,-78231,-909,-5,345,7111};
   // int n=sizeof(arr)/sizeof(int);
     int i,j,n,min,max,comp,index;
     cout<<"enter the no of elements ";
     cin>>n;
     for(i=0;i<n;i++)
     cin>>arr[i];
     max=arr[0];
     comp=0;
     for(i=1;i<n;i++)
     {   comp++;
            if(arr[i]>=max)
              { max=arr[i];
              index=i;}
                            
     }
     cout<<"max "<<max<<" ";
     swap(arr[n-1],arr[index]);
 
 cout<<endl;
 min=arr[0];
for(i=1;i<n-1;i++)
{  comp++;
    if(arr[i]<=min)
        min=arr[i];
}
 cout<<"Min "<<min;   
 
cout<<" no of comparisons "<<comp;
}