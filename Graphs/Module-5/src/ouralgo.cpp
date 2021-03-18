#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include"../include/input.h"

using namespace std;

// 4 0 4 0 1 10 0 3 12 0 2 11 2 3 5


struct triplets{
	int u, v, w;
};

bool is_connected(vector<pair<int, int>> adj[100], int v){

	int visit[v]={0}, count = 1;
	queue <int> s;
	visit[0]=1;
		
	for(int j=0;j<adj[0].size();j++){
		
		s.push(adj[0][j].first);
		visit[adj[0][j].first]=1;
		count++;
		//cout<<" "<<adj[0][j]<<"->";
	}
	while(!s.empty())
	{
		int t=s.front();
		s.pop();
			for(int j=0;j<adj[t].size();j++){
				if(visit[adj[t][j].first]!=1){
					s.push(adj[t][j].first);
					visit[adj[t][j].first]=1;
			    	count++;
			  // cout<<" "<<adj[t][j]<<"->";
			   }
		 }
		//  cout<<"-"<<t;         
	} 

	if(v == count)
		return 1;
	else
		return 0;

}

bool cmppair(const triplets &i1, triplets &i2){ 
    return (i1.w > i2.w); 
}

void youralgo (vector<pair<int, int>> adj[], int v){
	
	vector<pair<int, int>> MST[v];
	vector<triplets> edges;
	int e=0;

	triplets temp;
	for(int i=0; i<v; i++){
		for(int j=0; j<adj[i].size(); j++){
			
			MST[i].push_back(adj[i][j]);
			temp.u = i;
			temp.v = adj[i][j].first;
			temp.w = adj[i][j].second;
			edges.push_back(temp);
			e++;
		}
	}

	e /= 2;

	sort(edges.begin(), edges.end(), cmppair);

	// for(int i=0; i<edges.size(); i++){
	// 	printf("(%d, %d, %d)\n", edges[i].u, edges[i].v, edges[i].w);
	// }

	int i=0;

	while(e>=v){

		int u = edges[i].u, v = edges[i].v, w = edges[i].w;

		// Find and delete edge (u, v)
		int adr;
		for(int j=0; j<MST[u].size(); j++){

			if(v == MST[u][j].first){
				adr = j;
				break;
			}
		}

		MST[u].erase(MST[u].begin()+adr);

		// //Find and delete edge (v, u)		
		for(int j=0; j<MST[v].size(); j++){

			if(u == MST[v][j].first){
				adr = j;
				break;
			}
		}
		MST[v].erase(MST[v].begin()+adr);

		if(is_connected){
			i += 2;
			e--;
		}
		else{
			MST[u].push_back(make_pair(v, w));
			MST[v].push_back(make_pair(u, w));
		}

	}

	cout<<"\n\nEdges of MST of the form: \nu: (v, wt)\nare:\n";
	for(int i=0; i<v; i++){
		cout<<i<<": ";
		for(int j=0; j<MST[i].size(); j++){
			printf("(%d, %d)", MST[i][j].first, MST[i][j].second);
		}
		cout<<endl;
	}

}



int main (){

	vector<pair<int, int>> adj[100];
	int v;
	bool flag;

	get_vec(adj, v, flag);

	cout<<"\n\n\nOUTPUT:";
	youralgo(adj, v);

	return 0;
}