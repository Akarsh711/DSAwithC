/*PROBLEM DESCRIPTION

 1. You are given a number n, representing the number of elements.
2. You are given a number k, representing the number of subsets.
3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.
*/
#include <iostream> 
#include <vector>
using namespace std ;

void printTable(vector<vector<int>> v){
   for(auto i: v){
      for(auto j: i){
         cout<<j<<" ";
      }
      cout<<"\n";
   }
}


   int main() {
      int n ;
      cin>>n ;
      int k ;
      cin>>k ;

     // write your code here
      vector<vector<long long>> dp(n+1,vector<long long>(k+1, 0));
      dp[1][1] = 1;
      for(int i=2; i<=n; i++){
         for(int j=1; j<=k; j++){
            dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
         }
      }
      // printTable(dp);
      cout<<dp[n][k];
   return 0;
   }

/*
SAMPLE INPUT
4
3

SAMPLE OUTPUT
6
*/