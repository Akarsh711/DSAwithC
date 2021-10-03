#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    string s;
    cin>>s;
    int pos = s.find('A');
    s.erase();
    cout<<s.size();
    
    // s.erase(pos, pos);
    for(auto i: s){
        cout<<i;
    }

return 0;
}