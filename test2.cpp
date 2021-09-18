// #include <stdio.h>
#include<iostream>
using namespace std;

bool sorted(int arr[], int n){
	if(n==1) return true;
	// if(n==1){
	// 	return true;
	// }
	// bool resArray = sorted(arr+1, n-1);
	// return (arr[0]< arr[1] && restArray);
	for(int i =0; i<n; i++){
		cout<<arr[i]<<endl;
	}
	sorted(arr+1, n-1);
}

int main(){
	int arr[] = {1,6,7,8, 5};
	sorted(arr, 5);
	// cout<<arr+1;
	return 0;
}