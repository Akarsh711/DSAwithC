#include<bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> &v){
    for(auto i: v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
int gridTraveller(int n1, int n2){
    vector<int> temp(n2, 0);
    vector<vector<int>> v(n1, temp);
    
    v[1][1] = 1;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(!(j+1 == n2))
                v[i][j+1]+= v[i][j];
            if(!(i+1==n1))
                v[i+1][j]+= v[i][j];
        }
    }
    printGrid(v);
    return v[n1-1][n2-1];
    
}
int main(){
    cout<<gridTraveller(4,3);
}