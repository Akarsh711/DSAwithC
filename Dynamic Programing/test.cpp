#include<iostream>
using namespace std;

int main(){
	int i=1;
	int old = 0; 
	int sum = 0;
	int mul = 1;
	while(i<=25){
		sum = sum+i;
		i=i+3;
	}

	// cout<<sum<<endl;
	// i=1;
	// while(i<=4){
	// 	mul = mul*i;
	// 	i=i+3;
	// }
	// cout<<mul;

	cout<<sum<<endl;
	i=10;
	while(i>1){
		mul = mul*i;
		i=i-2;
	}
	cout<<mul<<endl;

int a = 2;
int b = 9;
int c = 3;

if(a>b){//a>b b>a
	cout<<"a is greater then b"<<endl;
	}
	else if(b>c){//b>c c>b
		cout<<"b is greater then c"<<endl;
		}
		else{
			cout<<"c is greater then b"<<endl;
		}

	if(a>c){//a>c c>a
		cout<<"a is greater then c"<<endl;
	}
	else{
		cout<<"c is greater then a"<<endl;
	}



	// arr of 5 ele
	// input val
	// Multiply them
	int arr[5];
	int mularr[5];
	int temp;
	for(int i=0; i<5; i++){
		cout<<"enter the value for arr";
		cin>>arr[i];
	}

	cout<<endl;
	temp=1;
	for(int i=0; i<5; i++){
		temp = temp*arr[i];	
	}
	cout<<temp;
}


	// cout<< "number are equal";



// Matrix Multiplication
// 3 no's greatest from them
// store 5 elements in list and then find multiplication and sum inside
