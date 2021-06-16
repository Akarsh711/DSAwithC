#include "bits/stdc++.h"
using namespace std;

void BFS(vector<vector<int>> &adj, vector<bool> visited, int vertex){
	queue<int> neighbour_q;
	visited[vertex] = true;
	neighbour_q.push(vertex);

	while(!neighbour_q.empty()){
		int val = neighbour_q.front();
		neighbour_q.pop();	
		cout<<val;

		for(auto i: adj[val]){
			if(!visited[i]){
				visited[i] = true;
				neighbour_q.push(i);
			}
		}
	}

}

int main(){
	int n, m; cin>> n>>m; //number of vertex and no. of edges

	vector<vector<int>> adj(n);
	// Here keep in mind as we are taking arr of arr and mapping adjancey using index
	// Take value of vertex with in number of vertices.
	vector<bool> visited(n, false);

	for(int i=0; i<m; i++){
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	BFS(adj, visited, 0);

}