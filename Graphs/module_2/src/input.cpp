 
#include<iostream>
#include<vector>

using namespace std;



void edge_add(vector<int> adj[],int u,int v)
{  adj[u].push_back(v);
   adj[v].push_back(u);      //undirected and unweighted graph    
}