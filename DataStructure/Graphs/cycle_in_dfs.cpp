#include "bits/stdc++.h"
using namespace std;

// bool isCycle(int vertex, vector<vector<int>> &adj, vector<bool> &visited, int parent){
// 	visited[vertex] = true;
// 	for(auto i: adj[vertex]){
// 		if(i!=parent){ //we need to take care of parent as without this condition it will affect return
// 			if(!visited[i]){
// 				if(isCycle(i, adj, visited, vertex)){
// 					return true;
// 				}
// 			}
// 			else{
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

bool isCycle(int vertex, vector<vector<int>> &adj, vector<bool> &visited, int parent){
	visited[vertex] = true;
	for(auto i: adj[vertex]){
		if(i!=parent){
			if(visited[i])
				return true;
			if(isCycle(i, adj, visited, vertex)){
				cout<<"isme aya";
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n, m; cin>>n>>m;//n:vertices, m:edges
	bool cycle = false; 
	vector<vector<int>> adj(n);
	vector<bool> visited(n, false);

	for(int i =0; i<m; i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		// adj[v].push_back(u);
	}


	cycle = isCycle(0, adj, visited, -1);

	if(cycle)
		cout<<"cycle is present";
	else
		cout<<"cycle is not present";
}

// SAMPLE INPUT
