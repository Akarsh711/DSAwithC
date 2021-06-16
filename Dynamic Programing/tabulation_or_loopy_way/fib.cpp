
#include <iostream>
#include <vector>
// to find nth number in fibonacci
using namespace std;

void fib(int n){
	vector <int> arr(n+1, 0);
	arr[1] = 1;

	// for(int i = 0; i<arr.size(); i++){
	// 	arr[i+1] +=arr[i];
	// 	arr[i+2] += arr[i];
	// }
	
	for(int i=2; i<arr.size(); i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout<< arr[n];
}
int main(){
	fib(6);
}