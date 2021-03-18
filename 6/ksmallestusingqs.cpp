#include<iostream>
using namespace std;
int partition(int a[], int st,int end)
{  
   long int index=end,i,j,temp;
   i=st-1;
   for(j=st;j<=end-1;j++)  
   {
       if(a[j]<=a[index])
          {
              i++;
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;  }
   } 
     temp=a[++i];
     a[i]=a[index];
     a[index]=temp;
     return i; 
}
int function(int a[],int st,int end,int k)
{ 

     int p=partition(a,st,end);
     if(p-st+1==k)
        return p;
     else if(k<p-st+1)
        {int q=function(a,st,p-1,k);
         return q; }
     else
     {
         int q= function(a,p+1,end,k-1-p+st);
         return q;
     }
           }
// void quicksort(int a[],int st,long int end)
// {
//   if(st<end)
//    { long int p=partition(a,st,end);
//       {      quicksort(a,st,p-1);
//              quicksort(a,p+1,end);}
//    }
// }
int main()
{   int N;
    int a[]={12,7,9,2,0,-1,57};
    N=sizeof(a)/sizeof(int);  
    int k=7;
     int p=function(a,0,N-1,k);
    for(int i=0;i<=p;i++)cout<<a[i]<<" ";
}