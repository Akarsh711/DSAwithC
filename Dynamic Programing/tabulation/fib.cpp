
#include <iostream>
#include <vector>
// to find nth number in fibonacci
using namespace std;

void printVec(vector<int> &v){
	for(auto i: v){
		cout<<i<<" ";
	}
}
int fib(int n){
	vector<int> v(n+1,0);//table
	v[1] = 1;
	// printVec(v);
	for(int i=0; i<=n; i++){
		v[i+1]+= v[i];
		if(!(i==n))
			v[i+2]+= v[i];
	}
	// printVec(v);
	return v[n];
}
int main(){
	// cout<<fib(6);
	cout<<fib(8);
}