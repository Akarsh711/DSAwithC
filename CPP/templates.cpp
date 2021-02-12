// tempalte is a keyword used to create function and class template

#include<iostream>
#include <conio.h>

using namespace std;

// int big(int a int b){
// 	if(a > b)
// 		return a;
// 	else 
// 		return b;
// }

template <class X> //template <class type, class type, ...> type function_name(args)
X big(X a, X b){
	if(a > b)
		return a;
	else 
		return b;
}

int main(){
	cout << big(4,5);
	cout << big(5.6, 3.4); //this will not the same value as you passed as the values is float
							//we need overloading;
							// we also have other method which says 'to gernalise that function';
}

