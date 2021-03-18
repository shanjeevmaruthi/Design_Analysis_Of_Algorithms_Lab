#include<bits/stdc++.h>
#include"../include/input.h"
using namespace std;
int visit[10]={0};
void DFS(vector <int> adj[],int v,int st)
{  
    // int visit[v]={0};
     stack <int> s;
   visit[st]=1;
   s.push(st);
    while(!s.empty())
    {
        int t=s.top();
        s.pop();
            for(int j=0;j<adj[t].size();j++)
              {  
               if(visit[adj[t][j]]!=1)
                  {
                  s.push(adj[t][j]);
                  visit[adj[t][j]]=1;
              
                  }
               }
         cout<<"-"<<t;         
    } 
       
}


void DFS(vector<int>adj[],int v)
{
 // int visit[v]={0};
	int connected_comp=0;

	cout << "DFS: \n";
	for(int i=0;i<v;++i)
	{
		if(visit[i] == 0)
		{
			DFS(adj,v,i);
			++connected_comp;
			printf("\n");
		}
	}
	cout <<"No of Connected Components: "<<connected_comp<<"\n";

}

void DFS(vector <int> adj[],int v,int st,int end)
{  
     //int visit[v]={0},
     int flag=0;
     stack <int> s;
     visit[st]=1;
     s.push(st);
    while(!s.empty())
    {
        int t=s.top();
        s.pop();
            for(int j=0;j<adj[t].size();j++)
            {     if(visit[adj[t][j]]!=1)
                        {
                        s.push(adj[t][j]);
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

int *modifiedDFS(vector <int> adj[],int v,int st=0)       //returns pointer to array bish
{  
     //int visit[v]={0};
     stack <int> s;
     int *dfsarr=new int[v];
     int i=0;
   visit[st]=1;
   s.push(st);
    while(!s.empty())
    {
        int t=s.top();
        s.pop();
            for(int j=0;j<adj[t].size();j++)
              {  
               if(visit[adj[t][j]]!=1)
                  {
                  s.push(adj[t][j]);
                  visit[adj[t][j]]=1;
              
                  }
               }
         dfsarr[i++]=t;         
    } 
    return dfsarr;   
}
int main()
{
  vector<int> adj[100];
  int n;
  bool flag=0;
 // int visit[n]={0};
  get_graph(adj,n,flag);//flag for undirected or directed
  
  

  cout<<"OUTPUT: "<<endl;

 // int *ptr=modifiedDFS(adj,v);
  // for(int i=0;i<v;i++)
  // cout<<ptr[i]<<" ";
  // cout<<endl;
  //DFS(adj,n);
 // DFS(adj,n,0);
  DFS(adj,n,0,3);
return 0;
}