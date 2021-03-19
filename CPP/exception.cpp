#include <iostream>
#include <string>
using namespace std;

int divison_zero(int a, int b){
	int x = 9999;
	if(b == 0)
		throw "test";
	throw a/b;
	return (a/b);
}
int main(){
	int x,y;
	cout << endl <<"Enter a";
	cin >> x;
	cout << endl << "Enter b";
	cin >> y ;
	try{
		cout <<divison_zero(x, y);
	}
	catch(int x){
		cout << "Catch "<< x;
	}
	catch(...){
		cout << "Default";
	}
	
	
}