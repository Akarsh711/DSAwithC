#include "bits/stdc++.h"
using namespace std;

// we need to add an recStack
// bool isCycle(int vertex, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &rec_stack){
bool isCycle(int vertex, vector<int> adj[], vector<bool> &visited, vector<bool> &rec_stack){

	visited[vertex] =true;
	rec_stack[vertex] = true;

	// if rec_stack[vertex] == false && visited[vertex] == true; NO CYCLE
	// if rec_stack[vertex] == true && visited[vertex] == true; CYCLE

	for(auto i: adj[vertex]){
		if(rec_stack[i] and visited[vertex])
			return true;
			
        if(!visited[i]){
		    if(isCycle(i, adj, visited, rec_stack))
			    return true;
        }
	}
	rec_stack[vertex] = false;
	return false;
}



int main(){

	int n, m; cin>>n>>m;

	// vector<vector<int>> adj(n);
	vector<int> adj[n];
	vector<bool> visited(n, false);
	vector<bool> rec_stack(m ,false);

	for(int i=0; i<m; i++){
		int k,v; cin>>k>>v;
		adj[k].push_back(v);
	}


	if(isCycle(0, adj, visited, rec_stack)){
		cout<<"Cycle is Present";
	}
	else {
		cout<<"Cycle is not present";
	}
	

	// If you wanna check for multiple graph which might be unconnected use this
	// Where V is number of vertices

	// bool isCyclic(int V, vector<int> adj[]) 
	// {
	//    	vector<bool>visited(V, false);
	//    	vector<bool>rec_stack(V, false);
	//    	for(int i=0; i<V; i++){
 //     	        if(!visited[i]){
	//    	        if(isCycle(i, adj, visited, rec_stack))
	//    	            return true;
	//    	    }
	//    	}
	//    	return false;
	// }
}