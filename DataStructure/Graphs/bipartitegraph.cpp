#include "bits/stdc++.h"
using namespace std;


void DFS(int vertex, int c, vector<int> color, vector<vector<int>> &adj, vector<bool> &visited){
	visited[vertex] = true;
	if(c==1)
		color[vertex] = 2;
	else
		color[vertex] = 1;

	for(auto i: adj[vertex]){
		if(!visited[i]){
			if(!color[i]==c)
				DFS(i, c, color, adj, visited);
			else
				cout<<"not bipartite sadly";
				return;
		}
	}
}

int main(){
	int v, e; cin>>v>>e;

	vector<vector<int>> adj(v);
	vector<bool> visited(v, false);
	vector<int> color(v, 0);
	for(int i=0; i<e; i++){
		int key, val; cin>>key>>val;
		adj[key].push_back(val);
		adj[val].push_back(key);
	}

	for(int i=0; i<v; i++){
		DFS(i, 0, color, adj, visited);
	}


}