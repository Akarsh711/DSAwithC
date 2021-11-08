// From CSES problem set
#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int t;cin>>t;
    for(int i=1; i<=t; i++){
        long long n = i*i;
        long long all = n*(n-1)/2;
        long long danger = 4 * (i-1) * (i-2);
        cout<<(all - danger)<<endl;
    }
return 0;
}