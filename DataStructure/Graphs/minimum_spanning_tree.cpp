#include <bits/stdc++.h>
#include "../heap.h"


using namespace std;
/*
it's uses DSU DS
1. Prim's Algo
2. Kruskal's Algo
*/

// Prim's Algo
// It just checks out the edges weight and connect with lesser weight and marks that edge as check
// it do this till all vertex are found. 
void prim(void);

int main(){
	
	prim();
}

// -------------------------------------------
void prim(){
	int v,e; cin>>v>>e;

	vector<pair<int, int>> adj[v];
	int parent[v];
	int weights[v];
	bool mst[v];
	// this queue is use to store weight as it decrease the complexity of search;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;

	for(int i=0; i<e; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	for(int i=0; i<v; i++)
		parent[i] = -1, weights[i] = INT_MAX, mst[i]=false;

	weights[0] = 0;
	parent[0] = 0;
	q.push({0, 0});

	for(int count=0; count<v-1; count++){
		int vertex;
		int mini = INT_MAX;

		vertex = q.top().second; //second as second representing vertex and first weight
		q.pop(); 


		mst[vertex] = true;
		for(auto i:adj[vertex]){
			int node = i.first;
			int weight = i.second;
			if(!mst[node] && weight<weights[node]){
				q.push({weight, node});
				weights[node] = weight;
				parent[node] = vertex;
			}
		}
	}

	for(int i=0; i<v; i++)
		cout<<parent[i]<<" ";
}

// SAMPLE INPUT
/*
6 7
0 1 2
0 3 6
1 4 5
1 2 3
1 3 8
2 4 7
2 5 6
*/

