#include<iostream>
using namespace std;

int num = 1;
int total(int n, int i){
	if(i==1)
		return num;
	if(n%i==0)
		num++;
	return total(n, i-1);
}

// void factors(int n, int i){
// 	if(i==1){
// 		cout<<1;
// 		return;
// 	}
// 	if(n%i == 0)
// 		cout<<i;
// 	factors(n, i-1);

// }

void factors(int n, int i){
	if(i==n){
		cout<<n;
		return;
	}
	if(n%i == 0)
		cout<<i<<" ";
	factors(n, i+1);

}

// if n%i == 0;

int main(){
	int n;
	cin >>n;
	cout<<total(n, n)<<endl;
	factors(n,1);
}