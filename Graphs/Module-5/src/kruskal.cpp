#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
#include"../include/input.h"

using namespace std;
struct triplet{
	int u,v,w;
};
void addedge(vector <pair<int,int>> vert[],int v,int u,int w)
{
	vert[u].push_back(make_pair(v,w));
	vert[v].push_back(make_pair(u,w));
}
int comptrip(triplet v1,triplet v2){
	return(v1.w<v2.w);
}
void MST_kruskal(vector <pair<int,int>> vert[],int v){
	vector <pair<int,int>> tree[v];
	vector <triplet> edges;
	int tess=0;
	for(int i=0;i<v;i++){
		for(auto j=vert[i].begin(); j!=vert[i].end(); j++){
			tess=0;
			for(auto h=edges.begin();h!=edges.end();h++){
				if( (h->u==i && h->v==j->first)||(h->v==i && h->u==j->first))
				{tess+=1;}}
				if(tess==0)
				{
					edges.push_back({i,j->first,j->second});
				}				
			
		}
	}
	sort(edges.begin(),edges.end(),comptrip);
	int tn=0;
	vector <pair<int,int>> conn;
	int nconn=1;
	int uc=0,vc=0;
	for(auto h=edges.begin();h!=edges.end();h++){
		uc=0;vc=0;
		for(auto f=conn.begin();f!=conn.end();f++){
			if(h->u==f->first){
				uc=f->second;
			}
			if(h->v==f->first){
				vc=f->second;
			}
		}
		if(uc==vc && uc==0){
			conn.push_back(make_pair(h->u,nconn));
			conn.push_back(make_pair(h->v,nconn));
			addedge(tree,h->u,h->v,h->w);
			nconn++;
			tn++;
		}
		else if(uc!=vc)
		{
			if(uc==0){
				conn.push_back(make_pair(h->u,vc));
				addedge(tree,h->u,h->v,h->w);
				tn++;
			}
			else if(vc==0){
				conn.push_back(make_pair(h->v,uc));
				addedge(tree,h->u,h->v,h->w);
				tn++;
			}
			else{
				addedge(tree,h->u,h->v,h->w);
				tn++;
				for(auto f=conn.begin();f!=conn.end();f++){
					if(uc==f->second){
						f->second=vc;
					}
				}
			}
		}
		if(tn==v-1)
			break;
		
	}
	cout<<"\n\nEdges of MST of the form: \nu: (v, wt)\nare:\n";
	for(int i=0; i<v; i++){
		cout<<i<<": ";
		for(int j=0; j<tree[i].size(); j++){
			printf("(%d, %d)", tree[i][j].first, tree[i][j].second);
		}
		cout<<endl;
	}
}
int main(){
	//vertext, weight
	// int n;
	// cout<<"Enter the number of vertices:"<<endl;
	// cin>>n;
	// int u,v,w;
	// vector <pair<int,int>> vert[n];
	// int e;
	// for(int i=0;i<n;i++){
	// 	cout<<"vertex"<<i<<endl;
	// 	cout<<"enter number of edges";
	// 	cin>>e;
	// 	for(int h=0;h<e;h++){
	// 	cin>>v>>w;
	// 	addedge(vert,i,v,w);}
	// }

	vector<pair<int, int>> vert[100];
	int n;
	bool flag;

	get_vec(vert, n, flag);

	cout<<"\n\nOutput:\n\n";

	MST_kruskal(vert,n);
	return 0;	
}
