#include<iostream>
using namespace std;

// Nested Classes
class A{
public:
	int x;

	class B{
	public:
		int num = 99;	
	};B obj_name;

};


int main(){
	// Calling a Nested class
	A :: B obj;

	A obj2;
	cout<<obj2.x;

	cout<<obj2.obj_name.num;

}
