// overloading operator
#include<iostream>
using namespace std;

class Numbers{
	int no = 1;
public:
	// class methods
	void set_val(){
		cout << "Enter the Numbers";
		cin >> no;
	}

	void show(){
		cout << endl << "numbers is"<< no << endl;
	}

	// void operator -(){
	// 	no = -no;
	// }
	Numbers operator +(Numbers bot){
		Numbers r;
		r.no = no + bot.no;	
		return r;
	}
	
};



int main(){
Numbers n, n2,n3, temp,pubg;

n.set_val();
n2.set_val();
n3.set_val();
// temp = n2.operator+(n);
temp = n2 + n;
// temp  = n2 + n, n3;
pubg= temp + n3;
pubg.show();

// n.get_val();
// n.show();
// n.operator-();
// -n;
// n.show();

}