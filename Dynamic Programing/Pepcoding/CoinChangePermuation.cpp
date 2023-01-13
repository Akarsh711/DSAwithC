#include <iostream>
#include <vector>
using namespace std;

int sol(vector<int> coins, int sum, vector<int> &memo){
  if(sum == 0)return 1;
  if(sum<0)return 0;

  int res = 0;
  if(memo[sum]!=-1) return memo[sum];
  for(int i=0; i<coins.size(); i++){
    int temp = sol(coins, sum-coins[i], memo);
    if(temp>0){
      res+=temp;
    }
  }
  memo[sum] = res;
  return res;
}

int tab(vector<int> coins, int sum){
  vector<int> dp(sum+1);
  dp[0] = 1;
  for(int i=0; i<=sum; i++){
    for(int j=0; j<coins.size(); j++){
      if(i-coins[j]>=0){
        int val = coins[j];
        dp[i]+=dp[i-val];
      }
    }
  }
  return dp[sum];
}

int CCP(vector<int> coins, int amt, vector<int> dp) {
  vector<int> memo(amt+1, -1);
  return tab(coins, amt);  
}

int main() {
  int n;
  cin >> n;
  vector<int> coins(n, 0);
  for (int i = 0; i < coins.size(); i++) {
    cin >> coins[i];
  }
  int amt;
  cin >> amt;
  vector<int> dp(amt + 1, 0);
  cout<<CCP(coins, amt, dp);

}

/*
SAMPLE INPUT:
4
2
3
5
6
7
SAMPLE OUTPUT:
5
*/