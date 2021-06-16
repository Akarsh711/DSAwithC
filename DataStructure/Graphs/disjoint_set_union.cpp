#include "bits/stdc++.h"
// #include<iostream>
using namespace std;

int parent[1000000];
int rank_set[1000000];
	

void makeSet(){
	for(int i=1; i<=sizeof(parent)/sizeof(int); i++){
	
		parent[i] = i;
		rank_set[i] = 0;
	}
}

int findParent(int node){
	if(node == parent[node]){
		return node;
	}
	// path compressing
	return parent[node] = findParent(parent[node]);
}


void unionSet(int u, int v){
	u = findParent(u);
	v = findParent(v);

	if(rank_set[u] < rank_set[v]){
		parent[u] = v;
	}
	else if(rank_set[v]<rank_set[u]){
		parent[v] = u;
	} 
	else{
		parent[v] = u;
		rank_set[u]++;
		// when you put smaller tree with larger one height never increases
		// and when you join tree with same rank height increase so that's why 
		// increament here not on above condition
	}
}


int main(){
	int n, v;
	cin>>n >>v;
	makeSet();
	while(n--){
		int u, v;
		cin>>u>> v;
		unionSet(u,v);
	}

	for(int i=0; i<=v; i++){
		cout<<parent[i];
	}
	// 2 and 3 belong tho the smae componen or not
	if(findParent(4)!=findParent(3)){
		cout<<"Different component";
	}
	else{
		cout<<"Same component";
	}
}


// 1 2 3, 6 5 4 set representation

// SAMPLE INPUT:

/*
7 7
1 2
2 3
3 -1
6 5
5 4
4 -1
0 1
*/

