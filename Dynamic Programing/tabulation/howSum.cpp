#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

vector<int> howSum(int n, vector<int> vec){
    vector<vector<int>> p(n+1);
    p[0][0] = {};
    for(int i=0;i<n+1; i++){
        if(p[i]!=NULL){
            for(auto j:vec){
                if(i+j<n+1)
                    p[i+j].push_back(j);
            }
        }
    }
    return p[n];
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    vector<int> res = howSum(7, {3,5,2});
    for(auto i: res){
        cout<<i<<" ";
    }
return 0;
}