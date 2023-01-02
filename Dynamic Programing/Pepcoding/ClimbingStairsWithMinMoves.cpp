#include <iostream>
#include <vector>
using namespace std;

int minv = 1e9;

// Taking Global
int sol(int target, int n, int cnt, int arr[], vector<int> &dp){
  if(target == n){
    minv = min(minv, cnt);
    return 1;
  }
  else if(target < n) return 0;

  if(dp[n])return dp[n];
  int temp = 0;
  for(int j = arr[n]; j>=1; j--){
    temp += sol(target, n+j, cnt+1, arr, dp);
  }
  dp[n] = temp;

  return temp;
}

// By returning the path length and comparing in backtrack
int sol2(int target, int n, int cnt, int arr[], vector<int> &dp){
  if(target == n){
    // minv = min(minv, cnt);
    return cnt;
  }
  else if(target < n) return 1e9;

  if(dp[n])return dp[n];

  int temp = 1e9;
  for(int j = arr[n]; j>=1; j--){
    temp = min(temp, sol2(target, n+j, cnt+1, arr, dp));
  }
  dp[n] = temp;

  return temp;
}

int sol3(int target, int n, int arr[], vector<int> &dp){
  if(target == n){
    // minv = min(minv, cnt);
    return 1;
  }
  else if(target < n) return 1e9;

  if(dp[n])return dp[n];

  int temp = 1e9;
  for(int j = arr[n]; j>=1; j--){
    temp = min(temp, sol3(target, n+j, arr, dp));
  }
  dp[n] = 1+temp;

  return dp[n];
}


int cs(int arr[], int n, vector<int>& dp) {
  return sol3(n, 0, arr, dp)-1;
  // return minv;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n + 1, 0);

  cout << cs(arr, n, dp) << endl;
}

/* SAMPLE TESTCASE:
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
    4
*/