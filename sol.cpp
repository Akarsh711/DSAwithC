#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


vector<int> howSum(int n, vector<int> v){
    if(n == 0)return [];
    if(n<0)return NULL; 

    vector<int> sums;
    for(auto i:v){

        if(howSum(n-i, v)){
            sums.push_back(i);
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);


return 0;
}