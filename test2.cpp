#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;cin>>n;
vector<char> v;
string s;cin>>s;
for(int i=0; i<s.size(); i++){
    v.push_back(s[i]);
}

int count = 1;
for(auto i:v){
    if(count == n){
        cout<<i;
        break;
    }
    count++;
}
return 0;
}