#include<bits/stdc++.h>
using namespace std;

// inputs 
// first line contains number of vertex and edges
// next line will take connection b/w vertex1, vertex2, weight according to number of
// edges provided in previous line
// last line contain src where to start
int main(){
	int src;
	int V,E; cin>>V>>E;
	vector<vector<pair<int, int>>> adj(V);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
	for(int i=0; i<E; i++){
		int u, v, w; cin>>u>>v>>w;
		adj[u].push_back({v, w});
		// adj[v].push_back({u, w});
	}
    
	int dist[V];
	vector<int> prev(V,-1);
	for(int i=0; i<V; i++){
		dist[i] = INT_MAX;
	}
    // starting point src;
    cin>>src;
    dist[src] = 0;
    
    q.push({src, 0});
	while(!q.empty()){
		int curr = q.top().first;
		q.pop();
		for(auto i: adj[curr]){
			if(dist[i.first] > dist[curr]+i.second){
				prev[i.first] = curr;
				dist[i.first] = dist[curr] +i.second;
				q.push(i);
			}
		}
	}

	cout<<endl;
	for(int i=0; i<V; i++){
		cout<<dist[i]<<" ";
	}	
	cout<<endl;
	cout<<"sequence of nodes to destination"<<endl;
	for(int i=0; i<V; i++){
		cout<<prev[i]<<" ";
	}	
}

/*
5 6
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3
0
*/

// OUTPUT
/*
0 3 1 4 7 
sequence of nodes to destination
-1 2 0 1 3
*/

