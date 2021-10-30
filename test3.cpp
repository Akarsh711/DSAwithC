#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

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

// int find_k(vector<int> v){
//     vector<int> sub={35,0,9, 27, 3, 22};
//     // vector<int> sub = v;
//     map<int, int> divis;
//     int res = 0;
//     for(auto i: sub){
//         for(auto j: find_divisors(i)){
//             divis[j] ++;
//         }
//     }
    
//     for(auto i:divis){
//         // cout<<i.first<<" "<<i.second<<"\n";
//         res = max(res, i.second);
//     }
//     // cout<<res;
//     return res;
// }

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

           
            // for(auto i:differences){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
        }
        // if(res==INT_MAX){
        //     cout<<-1<<endl;
        // }
        // else{
        //     cout<<res<<endl;
        // }
        cout<<(res==INT_MAX? -1 :res)<<endl;
        
    // find_k()
    }
}
int main(){
ios_base::sync_with_stdio(false);
    sol();
    // find_k({1,23});

cin.tie(NULL);

   
return 0;
}