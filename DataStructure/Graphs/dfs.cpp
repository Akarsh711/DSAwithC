#include "bits/stdc++.h"
using namespace std;

void DFS(vector<vector<int>> &adj, vector<bool> &visited, int vertex){
	visited[vertex] = true;
	cout<<vertex;
	for(auto i: adj[vertex]){
		cout<<i<<":"<<vertex<<" ";
		if(!visited[i]){
			DFS(adj, visited, i);
		}
	}
}

void iterDFS(vector<vector<int>> &adj, vector<bool> &visited, int vertex){
	stack<int> neighbour_stack;
	visited[vertex] = true;
	neighbour_stack.push(vertex);

	while(!neighbour_stack.empty()){
		int val = neighbour_stack.top();
		neighbour_stack.pop();
		cout<<val;
		for(auto i: adj[val]){
			if(!visited[i]){
				visited[i] = true;
				neighbour_stack.push(i);
			}
		}
	}

}

int main(){
	int n, m; cin>>n>>m;//vertex, and edges
	// Adjancey List
	vector<vector<int>> adj(n);
	vector<bool> visited(n);

	for(int i=0; i<m; i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// for(int i=0; i<=n; i++){
	// 	cout<<adj[i][0];
	// 	// <<":"<<adj[0];
	// 	for(int j=0;j++)
	// 		cout<<adj[i][j]<<endl;
	// }
	DFS(adj, visited, 0);
}