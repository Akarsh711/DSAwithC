#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using namespace std::chrono;


int canConstructMemoized(string s, vector<string> v, map<string, int> mp){
    if(s.size() ==0) return 1;
    
    if(mp[s]!=NULL) return mp[s];
    for(auto i: v){
        if(s.find(i)==0){
            mp[s] = canConstructMemoized(s.substr(i.size(), s.size()), v, mp);
            return mp[s];
        }
    }
    mp[s]=0;
    return 0;
}

int canConstruct(string s, vector<string> v){
    if(s.size() ==0) return 1;
    
    for(auto i: v){
        if(s.find(i)==0){
            if(canConstruct(s.substr(i.size(),s.size()), v)){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    // vector<string> v = {"te", "e", "st"};
    // string s = "test";
    vector<string> v = {"ee", "eee" "eeee"};
    string s = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    // cout<<s.substr(1, s.size());   
    map<string, int> mp;
    
    // string s2 = s.substr(2, s.size());   
    
    // cout<<s2.size();
    auto start = high_resolution_clock::now();
    // cout<<canConstruct(s, v);
    cout<<canConstructMemoized(s, v, mp);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
return 0;
}