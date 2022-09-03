#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int canSum(int v, vector<int> vec){
    vector<int> p(v+1, 0);
    p[0] = 1;
    for(int i = 0; i<v+1; i++){
        if(p[i]==1){
            for(auto j: vec){
                if(i+j<v+1)
                    p[i+j]=1;
            }
        }
    }
    return p[v];

}
int main(){
    cout<<canSum(7, {2,3});
    cout<<canSum(7, {5,3, 4, 7})<<endl;
    cout<<canSum(7, {2,4})<<endl;
    cout<<canSum(8, {2,3,5})<<endl;
    cout<<canSum(300, {7,14})<<endl;
return 0;
}