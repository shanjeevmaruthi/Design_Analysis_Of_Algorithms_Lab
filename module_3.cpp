#include<bits/stdc++.h>
using namespace std;

void edge_add(vector<int> adj[],int u,int v)
{  adj[u].push_back(v);
   adj[v].push_back(u);      //undirected and unweighted graph    
}

int BFS_MODIFIED(vector <int> adj[],int v,int st,int end,int parent[])
{  
     int visit[v]={0},flag=0;
     queue <int> s;
     visit[st]=1;
    //  cout<<" "<<st;
     for(int j=0;j<adj[st].size();j++)
           {s.push(adj[st][j]);
            visit[adj[st][j]]=1;
            parent[adj[st][j]]=st;
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
               parent[adj[t][j]]=t;
              // cout<<" "<<adj[t][j]<<"->";
               }
         }
        //  cout<<","<<t;
         if(t==end)flag=1;         
    }    
       
if(flag)
{cout<<"  path exists for "<<st<<" to "<<end<<" ";
 return 1;}
else 
{if(st!=end) cout<<" no path for "<<st<<" to "<<end<<" "; 
return 0;}
}

void pathprinter(int parent[],int st,int end)
{     int node=end;
       cout<<node;
     while(parent[node]!=-1)
         {cout<<"<-"<<parent[node];
          node=parent[node];
         }

}
void BFS_SPath(vector<int> adj[],int v,int st,int flag=0)
{ for(int i=1;i<v;i++)
  {  int parent[v];
    for(int j=0;j<v;j++)
    {
      parent[j]=-1;
    }
    if(BFS_MODIFIED(adj,v,st,i,parent))
          pathprinter(parent,st,i);
  }
}

int main()
{
  int v;
  cout<<"enter number of vertices ";
  cin>>v;
  int visit[v]={0};
  
  vector<int> adj[v];
  edge_add(adj,1,2);
  edge_add(adj,2,3);
  edge_add(adj,3,4);
  edge_add(adj,5,4);
  edge_add(adj,5,6);
  edge_add(adj,1,6);
//   edge_add(adj,2,3);

BFS_SPath(adj,v,1);
return 0;
}