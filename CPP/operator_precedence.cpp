#include<iostream>

using namespace std;


int main(){
	int m, l;
	m = 1;
	l = 0;
	// PEMDAS always follows in programing
	int size = m-l+1; //left to right exceution of all operator except:
	// Unary[+ - ! ~ ++ - - (type)* & sizeof	]
	// Conditional[?:]
	// Assignment [= += -= *= /= %=>>= <<= &= ^= |=	]
	cout << "size is :" << size;
}