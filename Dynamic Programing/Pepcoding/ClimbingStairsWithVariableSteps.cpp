#include <bits/stdc++.h>
using namespace std;

int sol(int target, int n, int arr[], int v[]){
    if(n == target) return 1;
    else if(n > target) return 0;

    if(v[n])return v[n];
    int cnt = 0;
    for(int j=1; j<=arr[n]; j++){
       cnt += sol(target, n+j, arr, v);
    }
    v[n] = cnt;
    return cnt;
}

int cs(int arr[], int n){
    // Memoized
    // vector<int> v(n+1, 0);
    int v[n+1];
    for(int i=0; i<n+1; i++){
        v[i] = 0;
    }
    return sol(n, 0, arr, v);

    // Tabulated
    // int dp[n+1];
    // dp[n] = 1;
    // for(int i=0; i<n; i++){
    //     dp[i] = 0;
    // }
    // for(int i=n-1; i>=0; i--){
    //     for(int j=1; (j<=arr[i] && i+j<n+1); j++){
    //         dp[i]+= dp[i+j];
    //     }
    // }
    // // cout<<dp[0];
    // return dp[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}

/*
TESTCASE:
Input:
10
3
3
0
2
1
2
4
2
0
0
Output:
5
*/