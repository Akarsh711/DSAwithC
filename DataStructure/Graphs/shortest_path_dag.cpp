#include <bits/stdc++.h>
using namespace std;

/*
	Topological Sort
		simply do dfs on components in graph and add them to stack when backtracking
		and from top to bottom of stack obtained is your topological ordering 
		
		we gonna traverse this stack and check for if neighbours weight + current weight is 
		greater than in distance array(which is initialize with infinity) if that be the case we
		subsitute the value 

		It will give you path for all nodes.
*/


void topologicalSortDFS(vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &s, int src){
	visited[src] = true;
	for(auto it: adj[src]){
		if(!visited[it.first])
			topologicalSortDFS(adj, visited, s, it.first);
	}

	s.push(src);
	// cout<<src;
}

// with topological ordering
void shortestPath(vector<vector<pair<int, int>>> &adj ,stack<int> s, int V){
	
	int dis[V];
	
	for(int i=0; i<s.size(); i++){
		dis[i] = 1e9;
	}
	dis[0] = 0;

	while(!s.empty()){
		int curr = s.top();
		s.pop();
	
		for(auto it : adj[curr]){
			int val = it.first;
			int weight = it.second;

			if(dis[val] > dis[curr]+weight){
				dis[val] = dis[curr]+weight;
			}
		}
	}

	// printing time
	for(int i=0; i<V; i++){
		(dis[i]== 1e9)?cout<<"inf ":cout<<dis[i]<< " ";
	}
}

// without topological ordering
void shortestPathBFS(vector<vector<pair<int, int>>> &adj, vector<bool> &visited, int src, int V){
	queue<int> q;
	q.push(src);

	int dis[V];
	for(int i=0; i<V; i++)
		dis[i] = 1e9;
	dis[0] = 0;

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(auto i:adj[curr]){
				visited[i.first] = true;
				q.push(i.first);
				if(dis[i.first]> dis[curr]+i.second){
					dis[i.first] = dis[curr]+i.second;
				}
		}
	}

	for(int i=0; i<V; i++)
		cout<<dis[i]<<" ";
}
int main(){
	int V,E; cin>>V>>E;
	vector<vector<pair<int, int>>> adj(V); //pair(val, weight)
	// vector<vector<int>> adj(V);
	// stack<int> topology;
	vector<bool> visited(V, false);

	for(int i=0; i<E; i++){
		int u,v, w; cin>>u>>v>>w;
		adj[u].push_back({v, w});
	}

	stack<int> s;
	for(int i=0; i<V; i++){
		if(!visited[i])
			topologicalSortDFS(adj, visited, s, i);
	}
	cout<<endl;
	shortestPath(adj, s, V)
	shortestPathBFS(adj, visited, 0, V);

}