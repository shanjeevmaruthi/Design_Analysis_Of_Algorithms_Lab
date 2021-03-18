#include<bits/stdc++.h>
#include"../include/input.h"
using namespace std;
int visit[100]={0};
void DFS_util(vector <int> adj[],int v,int st)
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
         //cout<<"-"<<t;         
    } 
    
       
}
bool DFS(vector<int>adj[],int v)
{
 // int visit[v]={0};
	int connected_comp=0;

	//cout << "DFS: \n";
	for(int i=0;i<v;++i)
	{
		if(visit[i] == 0)
		{
			DFS_util(adj,v,i);
			++connected_comp;
			//printf("\n");
		}
	}
    if(connected_comp>1)
    return 0;
	//cout <<"No of Connected Components: "<<connected_comp<<"\n";
return 1;
}