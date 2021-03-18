#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include"input.h"

using namespace std;

struct triplets{
		int u, v, w;
};

bool cmppair(const triplets &i1, triplets &i2) 
{ 
    return (i1.w < i2.w); 
}

void Max_Weight_MST_Prim(vector<pair<int, int>> G[], int vert){

	vector<pair<int, int>> MST[vert];

	int vertertex = 0, count = 1;
	bool neighbour[vert] = {0};
	neighbour[0] = 1;
	cout<<"\n\n";
	for(int i=0; i<vert-1; i++){
		
		vector<triplets> pairs;

		// Push all neighbours of the vertices in focus
		int k = 0;
		while(k<vert){
			if(neighbour[k]){
				for(int q=0; q<G[k].size(); q++){
					triplets push;
					push.u = k;
					push.v = G[k][q].first;
					push.w = G[k][q].second;
					
					pairs.push_back(push);
				}
			}
			k++;
		}
		
		//Sort them to find edge with max weight
		sort(pairs.begin(), pairs.end(), cmppair);

		int u = pairs[pairs.size()-1].u, v = pairs[pairs.size()-1].v, w = pairs[pairs.size()-1].w;

		//Push minimum edge (u, v) and (v, u) into MST.
		printf("Pushing: %d, %d, %d\n", u, v, w);
		MST[u].push_back(make_pair(v, w));
		MST[v].push_back(make_pair(u, w));
		int adr;
		
		// Find and delete edge (u, v)
		for(int j=0; j<G[u].size(); j++){

			if(v == G[u][j].first){
				adr = j;
				break;
			}
		}

		G[u].erase(G[u].begin()+adr);

		// Find and delete edge (v, u)		
		for(int j=0; j<G[v].size(); j++){

			if(u == G[v][j].first){
				adr = j;
				break;
			}
		}
		G[v].erase(G[v].begin()+adr);

		// G[u].erase(G[u].begin()+adr);
		
		cout<<"\n\nEdges of G are:\n";

		for(int i=0; i<vert; i++){
			cout<<i<<": ";
			for(int j=0; j<G[i].size(); j++){
				printf("(%d, %d)", G[i][j].first, G[i][j].second);
			}
			cout<<endl;
		}

		neighbour[v] = 1;
		count ++;

	
	}

	cout<<"\n\nEdges of MST are:\n";
	for(int i=0; i<vert; i++){
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

	Max_Weight_MST_Prim(adj, v);

	

}