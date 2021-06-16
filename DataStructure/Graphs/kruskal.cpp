#include<bits/stdc++.h>
// #include<iostream>
using namespace std;


struct node{
	int vertex;
	int weight;
	int destination_vertex;

	node(int v1, int v2, int w){
		vertex =v1;
		destination_vertex = v2; 
		weight = w;
	}	
};



bool comparator( node n1,  node n2){
	return n1.weight < n2.weight;
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionSet(int v1, int v2, vector<int> &parent, vector<int> &rank){
	int par_v1 = findPar(v1, parent);
	int par_v2 = findPar(v2, parent);	

	if(rank[par_v1] < rank[par_v2]){
		parent[par_v1]=par_v2;
	}
	else if(rank[par_v2] < rank[par_v1]){
		parent[par_v2]=par_v1;
	}
	else{
		parent[par_v2] = parent[par_v1];
		rank[par_v1]++;
	}
}


int main(){
	int v, e;	
	cin>>v>>e;

	vector<node> node_arr;
	vector<int> parent(v);
	vector<int> rank(v , 0);
	vector<pair<int, int>> mst;


	for(int i=0; i<e; i++){
		int v1,v2,w;
		cin>>v1>>v2>>w;
		node_arr.push_back(node(v1, v2, w));
	}

	for(int i=0; i<v; i++){
		parent[i] = i;
	}

	sort(node_arr.begin(), node_arr.end(), comparator);

	for(auto i: node_arr){
		if(findPar(i.vertex, parent) != findPar(i.destination_vertex, parent)){
			unionSet(i.vertex, i.destination_vertex, parent, rank);
			mst.push_back({i.vertex, i.destination_vertex});
		}
	}
	
	for(auto i: mst){
		cout<<i.first;
		cout<<i.second<<endl;
	}
}


/*
6 9
5 4 9
5 1 4
4 1 1
4 2 3
1 2 2
4 3 5
3 2 3
2 6 7
3 6 8
*/

