#include<vector>
using namespace std;

void get_graph(vector<int> adj[], int &v, bool flag);
void edge_add(vector<int> adj[], int u, int v, int wt, bool flag=0);
bool DFS(vector <int> adj[],int v,int st);