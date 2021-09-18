#include<bits/stdc++.h>
using namespace std;


void test(auto eq){
  eq[{1,2}][0] = {0,1};
  cout<<eq[{1,2}];
}
int main(int argc, char const *argv[])
{
  map<pair<int, int>, vector<vector<int>>> eqs;
  cout<<"running...";
  test(eqs);
  return 0;
}
