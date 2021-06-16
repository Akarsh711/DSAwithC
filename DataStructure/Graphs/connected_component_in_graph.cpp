#include "bits/stdc++.h"
using namespace std;



void dfs(int vertex, vector<vector<int>> &adj, vector<bool> &visited){
	visited[vertex] = true;
	stack<int> s;
	s.push(vertex);

	while(!s.empty()){
		int node = s.top();
		s.pop();
		cout<<node;
		for(auto x:adj[node]){
			if(!visited[x]){
				s.push(x);
				visited[x] = true;
			}
		}
	}
}

int main(){
	int v, e; cin>>v>>e;
	vector<vector<int>> adj(v);
	vector<bool> visited(v, false);
	cout<<e;
	for(int i=0; i<e; i++){
		int k, val; cin>>k>>val;
		adj[k].push_back(val);
		// adj[val].push_back(k);
	}

	for(int j=0; j<v; j++){
		cout<<"aya";
		if(!visited[j]){
			dfs(j, adj, visited);
		}
	}
	
}