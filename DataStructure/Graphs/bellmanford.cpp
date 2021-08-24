// shortest path in graph with negative weights
// Also can be used for detetcting negative cycle
// Not better complexity than Dixetra but can be used with negative weights

/*COMPLEXITY*/
// 	write here

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int e1;
	int e2;
	int w;

	Node(int first, int second, int weight){
		e1 = first;
		e2 = second;
		w = weight;
	}
};

int main(){
	int n, m; //no. of edges and weights respectively
	cin>>n>>m;

	vector<Node> adj(m);
	vector<int> dis(n);

	for(int i =0; i<m; i++){
		int u, v, weight;
		cin>>u>>v>>weight;
		adj.push_back(Node(u, v, weight));
	}


	// making all elements of distance array except 0 infinity
	for(int i=0; i<n; i++){
		dis[i] = INT_MAX;
	}
	dis[0] = 0;
	cout<<"ithe";

	for(int i=0; i<n-1; i++){
		cout<<"aya";
		for(int j=0; j<n; j++){

			int u = adj[j].e1;
			int v = adj[j].e2;
			int weight = adj[j].w;

			if(dis[u] + weight< dis[v])
				dis[v] = dis[u] + weight;
		}
	}

	for(int i=0; i<n; i++){
		cout<< "aya";
		cout<<dis[i];
	}
}

/*
OUTPUT
6 7
0 1 5
1 5 -3
5 3 1
3 2 6
1 2 -2
2 4 3
3 4 -2	
*/