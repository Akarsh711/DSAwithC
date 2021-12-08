#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
int idx = -1;
map<string, vector<vector<string>>> mp;
// vector<vector<string>> res;
vector<vector<string>> allConstruct(string s, vector<string> v){
    if(s == ""){
        // idx++;
        return {{}};
    }

    vector<vector<string>> res;
    vector<vector<string>> ans;
    for(auto i: v){
        if(s.find(i) == 0){
            res = allConstruct(s.substr(i.size(), s.size()), v);
            for(auto j :res){
                j.push_back(i);
                ans.push_back(j);
            }
        }
    }
    // if(ans=={{}}) return {};
    return ans;
}

vector<vector<string>> allConstructMemoized(string s, vector<string> v, map<string, vector<vector<string>>> &m){
    if(s == ""){
        // idx++;
        return {{}};
    }

    if(!mp[s].empty()){
        cout<<"aya"<<endl;
        return mp[s];
    }
    vector<vector<string>> res;
    vector<vector<string>> ans;
    for(auto i: v){
        if(s.find(i) == 0){
            res = allConstructMemoized(s.substr(i.size(), s.size()), v, m);
            for(auto j :res){
                j.push_back(i);
                ans.push_back(j);
            }
        }
    }
    // if(ans=={{}}) return {};
    mp[s] = ans;
    return ans;
}



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    // vector<string> v = {"purple", "p", "ur", "le", "purpl"};
    // string s = "purple";
    vector<string> v = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
    string s = "abcdef";
    // vector<string> v = {"bo", "rd", "ate", "t", "ska", "sk", "boar", "a"};
    // string s = "skateboard";

    // vector<string> v = {"a", "aa", "aaa", "aaaa"};
    // string s = "aaaaaaaaaaaaaaaaaaaaaaar";
    map<string, vector<vector<string>>> m;

    vector<vector<string>> res;
    res = allConstructMemoized(s, v, m);
    // res = allConstruct(s, v);
    
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}