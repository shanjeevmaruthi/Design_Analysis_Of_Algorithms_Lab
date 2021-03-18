#include<iostream>
using namespace std;

int main()
{   int arr[10];
//{6,-4,6,23,0,-45,-78,10,200};
   // int n=sizeof(arr)/sizeof(int);
    // if(n%2!=0)
    // {
    //     arr[n]=arr[n-1];
    //     n++;
    // } 

    int i,gmin,n,gmax;
    int j=0;
    int comp=0;
        cout<<"enter the no of elements .";
     cin>>n;
     int min[n/2],max[n/2];

     for(i=0;i<n;i++)
     cin>>arr[i];
   if(n%2==0)
    {  for(int i=0;i<=n-2;i=i+2)
        {    comp++;
            if(arr[i]<arr[i+1])
             { max[j]=arr[i+1];
               min[j]=arr[i];
               j++;
             }
            else 
            {
                max[j]=arr[i];
                min[j]=arr[i+1];
                j++;
            } 
        }
        gmax=max[0];
      for(i=1;i<n/2;i++)
     {   comp++;
            if(max[i]>gmax)
               gmax=max[i];              
                            
     }
     cout<<"max "<<gmax<<" ";
     gmin=min[0];
     for(i=1;i<n/2;i++)
     {   comp++;
           if(min[i]<gmin)
                 gmin=min[i];

     }
   cout<<"min "<<gmin;
   cout<<" no of comp "<<comp;}

     if(n%2!=0)
    {  for(int i=0;i<=n-3;i=i+2)
        {    comp++;
            if(arr[i]<arr[i+1])
             { max[j]=arr[i+1];
               min[j]=arr[i];
               j++;
             }
            else 
            {
                max[j]=arr[i];
                min[j]=arr[i+1];
                j++;
            } 
        }
        max[j]=min[j]=arr[n-1];
        j++;
        gmax=max[0];
      for(i=1;i<j;i++)
     {   comp++;
            if(max[i]>gmax)
               gmax=max[i];              
                            
     }
     cout<<"max "<<gmax<<" ";
     gmin=min[0];
     for(i=1;i<j;i++)
     {   comp++;
           if(min[i]<gmin)
                 gmin=min[i];

     }
   cout<<"min "<<gmin;
   cout<<" no of comp "<<comp;}
    return 0;
}