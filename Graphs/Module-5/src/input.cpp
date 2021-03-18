#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt, bool flag=0){    //0 for undirected and 1 for directed.

	if(flag == 0){
		
		adj[u].push_back(make_pair(v, wt));
		adj[v].push_back(make_pair(u, wt));
	}
	else{
		adj[u].push_back(make_pair(v, wt));
	}
}

void get_vec(vector<pair<int, int>> adj[], int &v, bool flag){

	cout<<"Enter number of vertices of graph\n";
	cin>>v;
	
	
	// cout<<"Enter 1 for directed and 0 for undirected\n";
	// cin>>flag;
	flag = 0;
	int e;
	cout<<"Enter number of edges:\n";
	cin>>e;

	for(int i=0; i<e; i++){
		
		int u, v, wt;
		// cout<<"Enter u, v, wt: ";
		printf("%d:Enter u, v, wt: ", i);
		cin>>u>>v>>wt;
		addEdge(adj, u, v, wt, flag);
	}

	// cout<<"\n\nEdges are:\n";
	// for(int i=0; i<v; i++){
	// 	cout<<i<<": ";
	// 	for(int j=0; j<adj[i].size(); j++){
	// 		printf("(%d, %d)", adj[i][j].first, adj[i][j].second);
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"End\n";
}

