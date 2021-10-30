// Problem Link : https://codeforces.com/contest/1593/problem/D2

// One way of solving is this

#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

namespace sol1
{
    set<int> find_divisors(int n){
        // vector<int> divisors;
        // for(int i=2; i<=n; i++){
        //     // if i is a divisor
        //     if(n%i == 0){
        //        divisors.push_back(i);
        //     }
        // }
        // return divisors;
        set<int> d;
        for (int dd = 1; dd * dd <= n; dd++)
            if (n % dd == 0) {
                d.insert(n / dd);
                d.insert(dd);
            }
        return d;

    }
    void sol(){
        int t;cin>>t;
        while(t--){
            int n;
            cin>>n;
            vector<int> v(n);
            forn(i, n){
                cin>>v[i];
            }
            // for(auto &i:v){
            //     cin>>i;
            // }
            // int vmax = v[0];
            
            
            int res=-1;
        
            for(int i=0; i<n; i++){
                int vmin = v[i];
                vector<int> differences(n);
                int same=0;
                for(int j=0; j<n; j++){
                    if(v[j] == v[i]){
                        same++;
                    }
                    else if(v[j]>v[i]){
                        differences.push_back(v[j]-v[i]);
                    }
                }

                if(same >= n/2){
                    res =INT_MAX;
                    // cout<<same<<"dfdfdf"<<endl;
                    break;
                }
                
                map<int, int> divis;
                
                // for(int i=0; i<n; i++){
                for(auto i: differences){
                    for(auto j: find_divisors(i)){
                        divis[j] ++;
                        // differences[i] = 0;
                    }
                }
                
                for(auto i:divis){
                    if(i.second>=n/2-same){
                        res = max(res, i.first);
                    }
                }
            }
            
            cout<<(res==INT_MAX? -1 :res)<<endl;
            
        }
    }
} // namespace sol1

namespace sol2{
int sol(){

        int t;cin>>t;
        
        while(t--){
            int n;cin>>n;
            
            vector<int> v(n);
            map<int, int> m2;
            
            int vmax = 0;
            int vmin = INT_MAX;
            for(auto &i : v){
                cin>>i;
                m2[i]++;
                i+=2e6;
                vmin = min(vmin, i);
            }

            // cout<<m2[v[0]];
            
            int flag = 0;
            for(auto i: m2){
                if(i.second >= n/2){
                    cout<<-1<<"\n";
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 1){continue;}
            

            // for(auto &i :v){
            //     // i+=abs(vmin);
            //     // cout<<i;
            //     vmax = max(vmax, i);
            // }
            // cout<<vmax<<":";
        
            int mx= 2e6+7;
            int ans = 0;
            sort(v.begin(), v.end());

                vector<int> remaindervec(n);
                vector<int> maping(mx);
            for(int i=mx; i>0; i--){ 
                for(int j=0; j<n; j++){
                    remaindervec[j]=v[j]%i;
                    // cout<<v[j]%i;
                    maping[remaindervec[j]]++;
                }
                // cout<<m[0]<<endl;
                int mi=0;
                for(int j=0; j<n; j++){
                    // cout<<j.secon<<" ";
                    // cout<<v[j];
                    mi = max(mi, maping[remaindervec[j]]);
                    maping[remaindervec[j]]--;
                }
                if(mi >= n/2){
                    ans = i;
                    break;
                }            
            }
            //  cout << (ans == mx ? -1 : ans) << endl;
            cout<<ans<<endl;
        }
    return 0;
    }
}



int main(){
ios_base::sync_with_stdio(false);
    sol2::sol();


cin.tie(NULL);

   
return 0;
}