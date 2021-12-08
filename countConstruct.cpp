#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using namespace chrono;
map<string, int> m;
int countConstruct(string s, vector<string> v){
    if(s == "")return 1;

    int res = 0;
    for(auto i: v){
        if(s.find(i) == 0){
            res += countConstruct(s.substr(i.size(), s.size()), v);
        }
    }
    return res;
}

int countConstructMemoized(string s, vector<string> v){
    if(s == "")return 1;
    if(m[s]!=NULL){return m[s];}

    int res = 0;
    for(auto i: v){
        if(s.find(i) == 0){
            res += countConstructMemoized(s.substr(i.size(), s.size()), v);
            // m[s] = res;
        }
    }
    // return res;
    m[s] = res;
    return res;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    map<string, int> m;
    vector<string> v = {"purple", "p", "ur", "le", "purpl"};
    string s = "purple";
    
    v = {"e", "ee", "eee", "eeee","eeee","eeeee"};
    s = "eeeeeeeeeeeeeeeeeeeeeeef";
    
    
    
    // cout<<countConstruct(s, v);
    auto start1 = high_resolution_clock::now();
    cout<<countConstruct(s, v);
    auto stop1 = high_resolution_clock::now();
    
    // auto start1 = high_resolution_clock::now();
    // cout<<countConstructMemoized(s, v);
    // auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout<<"\n"<<duration.count();
    
    // cout<<countConstructMemoized("abcdef", {"ab", "abc", "cd", "def", "abcd"}, m);

return 0;
}