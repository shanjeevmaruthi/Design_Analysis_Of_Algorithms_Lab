#include<bits/stdc++.h>
#include"../include/input.h"
using namespace std;
  

bool test_bipartite(vector<int> adj[], int v, int st=0) 
{ 
    int visit[v]={0};
    int color[v]={0};
    for(int i=0;i<v;i++)
    color[i]=-1;
    color[st]=1;
    queue <int> q;
    q.push(st);
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        for(int i=0;i<adj[w].size();i++)
        {
            if(color[adj[w][i]]==-1 && adj[w][i])
            {
                color[adj[w][i]]=1-color[w];
                q.push(adj[w][i]);
            }
            else if(color[adj[w][i]]==color[w] && adj[w][i])
            {
                return false;
            }
        }
    }
    return true;
} 

int main() 
{   
vector<int> adj[100];
  int n;
  bool flag=0;
 
  get_graph(adj,n,flag);//flag for undirected or directed
  
  

  cout<<"OUTPUT: "<<endl;


  if(test_bipartite(adj,n))
  cout<<"Graph is Bipartite"<<endl;
  else
  cout<<"Graph is not Bipartite"<<endl;
  
  
    return 0; 
}