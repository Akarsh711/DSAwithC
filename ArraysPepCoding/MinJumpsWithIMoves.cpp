/*
1. Given an integers X. 
2. The task is to find the minimum number of jumps to reach a point X in the number line starting from zero.
3. The first jump made can be of length one unit and each successive jump will be exactly one unit longer than the previous jump in length. 
4. It is allowed to go either left or right in each jump.
 */

#include<bits/stdc++.h>
using namespace std;

int minJumps(int x) {
  int sum = 0;
  int jump = 0;
  while(sum<x){
    jump++;
    sum+=jump;
  }
  if((sum - x) % 2 == 0){
    return jump;
  } 
  else if((sum+jump+1 -x) % 2 == 0){
    return jump+1;
  }else{
    return jump+2;
  }
}


int main(){
    int x;
    cin>>x;

    int jumps = minJumps(x);
    cout<<jumps;
}

/*
Input
X = 8
X = 9

Output
4
-1 -> 2 -> 3 -> 4 (order of jumps)

5
1 -> 2 -> -3 -> 4 -> 5 (prder of jumps)
*/