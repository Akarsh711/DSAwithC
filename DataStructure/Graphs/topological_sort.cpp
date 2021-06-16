#include"bits/stdc++.h"

using namespace std;
//Implemented using BFS
vector<int> topological_sort(int V, vector<vector<int>> &adj){
	vector<int> in(V, 0);// in degree
	vector<int> ans;
	queue<int> q;

	for(int i=0; i<V; i++){
		for(auto x:adj[i]){
			in[x]++;
		}
	}

	for(int i=0; i<V; i++){
		if(in[i] ==0) q.push(i);
	}

	while(!q.empty()){
		int td = q.front();
		q.pop();
		ans.push_back(td);
		for(aut x: adj[td]){
			in[x]--;
			if(in[x] == 0) q.push(x);
		}		
	}
	return ans;
}

void topologicalSortDFS(vector<vector<int>> &adj, vector<bool> &visited,  int src){
	visited[src] = true;
	for(auto it: adj[src]){
		if(!visited[it])
			topologicalSortDFS(adj, visited, s, it);
	}
	cout<<src;
}

int main(){

	int n, m; cin>>n, m;
	vector<vector<int>> adj;
	vector<bool> visited;

	for(int i=0; i<m; i++){
		int k, v; cin>>k, v;
		adj[k].push_back(v);
	}



} 