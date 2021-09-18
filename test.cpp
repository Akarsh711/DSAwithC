#include<bits/stdc++.h>
using namespace std;
clock_t start = clock();

void solve() {
  int n, x; cin >> n >> x;
  map<int, int> cnt, op;
  for (int i = 0; i < n; i++) {
    int y; cin >> y;
    cnt[y]++;
    if (x != 0) {
      cnt[y ^ x]++;
      op[y ^ x]++;
    }
  }
  int equal = 0, operation = 0;
  for (auto u : cnt) {
    if (u.second > equal) {
      equal = u.second;
      operation = op[u.first];
    } else if (u.second == equal) {
      operation = min(op[u.first], operation);
    }
  }
  cout << equal << ' ' << operation << '\n';
}

signed main() {
  ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
//   cerr << fixed << setprecision(10);
//   cerr << "Time taken = " << (clock() - start) / ((double)CLOCKS_PER_SEC) << " s\n";
  return 0;
}
