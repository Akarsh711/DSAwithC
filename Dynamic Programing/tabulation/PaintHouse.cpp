#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int minCost(vector<vector<int>> &cost)
{
    vector<vector<long long >> dp(cost.size(), vector<long long>(cost[0].size(), INT_MAX));
    for(int i=0; i<cost[0].size(); i++){
        dp[0][i] = cost[0][i];
    }

    for(int i=1; i<cost.size(); i++){
        for(int j=0; j<cost[0].size(); j++){
            //Checking and finding minimus
            for(int k=0; k<cost[0].size(); k++){
                if(k!=j){
                    dp[i][j] = min(dp[i-1][k], dp[i][j]);
                }
            }
            dp[i][j]+=cost[i][j];
        }
    }

    long long res = 1e9;
    for(int i=0; i<cost[0].size(); i++){
        res = min(res, dp[cost.size()-1][i]);
    }
    return res;
}

int main()
{
    int n ;
    cin>>n ;
    int k ;
    cin>>k ;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            int temp;cin>>temp;
            v[i].push_back(temp);
        }
    }
    cout<<minCost(v);
}

/*
    SAMPLE TESTCASE:
    INPUT:
    4 3
    1 5 7
    5 8 4
    3 2 9
    1 2 4
    
    OUTPUT:
    8
 */