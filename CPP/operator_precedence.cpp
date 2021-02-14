#include<iostream>

using namespace std;


int main(){
	int m, l, r;
	m = 1;
	l = 0;
	r = 4;
	// PEMDAS always follows in programing
	int size = m-l+1;
	l = 4;
	int size2 =  l+(r-1)/2; //left to right exceution of all operator except:
	// Unary[+ - ! ~ ++ - - (type)* & sizeof	]
	// Conditional[?:]
	// Assignment [= += -= *= /= %=>>= <<= &= ^= |=	]
	cout << "size is :" << size <<endl<< size2;
}