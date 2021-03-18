#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void edge_add(vector<int> adj[],int u,int v, bool flag=0)
{  
    if(flag==0){
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    else
    {
       adj[u].push_back(v);
    }
    
}

void get_graph(vector<int> adj[], int &v, bool flag){

	cout<<"Enter number of vertices of graph\n";
	cin>>v;
	

	flag = 0;
	int e;
	cout<<"Enter number of edges:\n";
	cin>>e;

	for(int i=0; i<e; i++){
		
		int u, v;
	
		printf("%d:Enter u, v: ", i);
		cin>>u>>v;
		edge_add(adj, u, v, flag);
	}

}