#include<iostream>

using namespace std;

int main()
{
 int i,j,n,k;
 cin>>n;
 //pattern 1
 for(i=0;i<n;i++)
  {
       for(j=1;j<=n-i;j++)
       {
           cout<<j;
       }
       cout<<"\n";
  }
  cout<<"\n";
  //pattern 2
for(i=0;i<n;i++)
  { 
      for(j=1;j<=n;j++)
       {  if(j>i)
          cout<<j;
        else if(j<10) cout<<" ";
        else cout<<"  ";   
       }
       cout<<"\n";       
  }
  cout<<"\n";
//pattern 3
for(i=0;i<=n;i++)
{
    for(j=1;j<=i;j++)
      cout<<j;
  cout<<"\n";    
}
cout<<"\n";
//pattern 4
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
      {
          if(j>n-i)cout<<j;
        else if(j<10) cout<<" ";
        else cout<<"  ";
      }
      cout<<"\n";
}
cout<<"\n";
//pattern 5
if(n%2==0)k=n/2; 
else k=(n/2)+1;
for(i=1;i<=k;i++)
{
   for(j=1;j<=n;j++)
     { if(j<i)cout<<" ";
       else if(j>n-i+1)cout<<" ";
       else cout<<j;

     }

cout<<"\n";
}
for(i=k;i>0;i--)
{
   for(j=1;j<=n;j++)
     { if(j<i)cout<<" ";
       else if(j>n-i+1)cout<<" ";
       else cout<<j;

     }
     cout<<"\n";
     }
  return 0;
}