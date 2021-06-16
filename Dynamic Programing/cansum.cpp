#include <iostream>
using namespace std;


// Gives how many can give n when add together in arr 
// It's a bit different then howsum as it have if in loop. 
int howmanycanSum(int n, int arr[], int size){
	 if(n==0){
	 	return 1;
	 }
	 int is = 0;
	 for(int i=0; i<size; i++){
	 	if(n>=arr[i]){
	 		is=is+howmanycanSum(n-arr[i], arr, size);
	 	}
	 }
	 return is;
}

int main(){
	int arr[] = {5,3,4,7};
	int size = sizeof(arr)/sizeof(int);
	cout<<howmanycanSum(7, arr, size-1);

}