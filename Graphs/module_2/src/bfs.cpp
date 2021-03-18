#include<bits/stdc++.h>
#include"../include/input.h"
using namespace std;


void BFS(vector <int> adj[],int v,int st=0)
{  
     int visit[v]={0};
     queue <int> s;
     visit[st]=1;
     cout<<" "<<st;
     for(int j=0;j<adj[st].size();j++)
           {s.push(adj[st][j]);
            visit[adj[st][j]]=1;
           //cout<<" "<<adj[0][j]<<"->";
           }
    while(!s.empty())
    {
        int t=s.front();
        s.pop();
                for(int j=0;j<adj[t].size();j++)
           {  if(visit[adj[t][j]]!=1)
               {s.push(adj[t][j]);
               visit[adj[t][j]]=1;
              // cout<<" "<<adj[t][j]<<"->";
               }
         }
         cout<<"-"<<t;         
    } 
       
}
void BFS(vector <int> adj[],int v,int st,int end)
{  
     int visit[v]={0},flag=0;
     queue <int> s;
     visit[st]=1;
     cout<<" "<<st;
     for(int j=0;j<adj[st].size();j++)
           {s.push(adj[st][j]);
            visit[adj[st][j]]=1;
           //cout<<" "<<adj[0][j]<<"->";
           }
    while(!s.empty())
    {
        int t=s.front();
        s.pop();
                for(int j=0;j<adj[t].size();j++)
           {  if(visit[adj[t][j]]!=1)
               {s.push(adj[t][j]);
               visit[adj[t][j]]=1;
              // cout<<" "<<adj[t][j]<<"->";
               }
         }
         cout<<","<<t;
         if(t==end)flag=1;         
    }    
       
if(flag)cout<<"  path exists";
else 
cout<<" no path";
}
int main()
{
  int v;
  cout<<"enter number of vertices ";
  cin>>v;
  int visit[v]={0};
  vector<int> adj[v];
  edge_add(adj,0,3);
  edge_add(adj,3,2);
  edge_add(adj,3,1);
  edge_add(adj,5,4);
  edge_add(adj,4,6);
//   edge_add(adj,1,3);
//   edge_add(adj,2,3);

BFS(adj,v,4,2);
return 0;
}