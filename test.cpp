#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#include<chrono>

using namespace std;
using namespace std::chrono;
int memoizedGridTraveller(int n, int m, map<pair<int, int>, int> mp){
    if(n==1 && m ==1) return 1;
    if(n<1 || m<1) return 0;

    if(mp[{n,m}]>0){
        return n+m;
    }
    int x = memoizedGridTraveller(n-1, m, mp);
    int y =memoizedGridTraveller(n, m-1, mp);
    mp[{n, m}]=x+y;
    return x+y;
    
}

int GridTraveller(int n, int m){
    if(n ==1 && m == 1) return 1;
    if(n<1 || m<1) return 0;

    int x = GridTraveller(n-1, m);
    int y =GridTraveller(n, m-1);
    return x+y;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

map<pair<int, int>, int> mp;
// cout<<GridTraveller(3,3);
// cout<<endl;


// auto start = system_clock::now();
// cout<<GridTraveller(18,18)<<endl;
// auto stop = high_resolution_clock::now();

// auto duration = duration_cast<microseconds>(stop - start);
  
// // To get the value of duration use the count()
// // member function on the duration object
// cout << duration.count() << endl;

auto start = high_resolution_clock::now();
cout<<memoizedGridTraveller(18,18, mp)<<endl;
auto stop = high_resolution_clock::now();

auto duration = duration_cast<microseconds>(stop - start);
  
// To get the value of duration use the count()
// member function on the duration object
cout << duration.count() << endl;
return 0;
}