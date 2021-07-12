#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &time, vector<int> &low, vector<int> &visited ,int root, int parent, int &timer){
    visited[root] = 1;
    time[root] = timer+1;
    low[root] = timer+1;
    timer++;
    for(auto i: adj[root]){
        if(i == parent) continue;

        if(!visited[i]){
            dfs(adj, time, low, visited, i, root, timer);
            if(low[i] < low[root] && visited[i] == 1){
                low[root] = low[i];
                }
            else if(low[i] >= low[root] && visited[i] == 1  && parent!=-1){
            }
        }
        if(low[i] < low[root] && visited[i] == 1){
                low[root] = low[i];
            }
    }   
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> adj(n);
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    vector<int> time(n, -1);
    vector<int> low(n, -1); 
    vector<int> vis(n, 0); 
    int timer = 0; 
    // for(int i = 0;i<n;i++) {
    //     if(!vis[i]) {
    //         dfs(i, -1, vis, tin, low, timer, adj); 
    //     }
    // }
    dfs(adj, time, low, vis, 0, -1, timer);
    
    // for(int i=0; i<n; i++){
    //  cout<<time[i]<<" ";
    // }
    // cout<<endl;

    // for(int i=0; i<n; i++){
    //  cout<<low[i]<<"     ";
    // }

    return 0;
}


// SAMPLE INPUTS
/*
5 5
0 1
1 2
2 0
0 3
3 4
*/
/*
12 14
0 1
1 2
2 3
3 0
3 4
4 5
5 6
5 8
6 7
8 7
7 9
9 10
10 11
11 9
*/