#include<bits/stdc++.h>
using namespace std;


/*
	It will give you path for all nodes.
*/

// Don't go with func name it's working is different but yes backend is bfs
void bfs(vector<vector<int>> &adj, int V, int start_point){

	int path[V];
	for(int i=0; i<V; i++) path[i] = INT_MAX;

	queue<int> q;
	q.push(start_point);
	path[start_point] = 0;

	while(!q.empty()){

		int curr = q.front();
		q.pop();		
		for(auto it:adj[curr]){
			int distance = path[curr]+1;
			if(distance < path[it]){
				path[it] = distance;
				q.push(it);
			}
		}	
	}	
	for(int i=0; i<V; i++){
		cout<<path[i]<<" ";
	}
}

int main(){
	/*
	source -> destination
	if source-distance<current_distance
	*/
	// int source_distance = 0;

	int n, m; cin>>n>>m; //number of vertex and no. of edges

	vector<vector<int>> adj(n);
	// Here keep in mind as we are taking arr of arr and mapping adjancey using index
	// Take value of vertex with in number of vertices.
	vector<bool> visited(n, false);

	for(int i=0; i<m; i++){
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(adj,n, 0);
	
}