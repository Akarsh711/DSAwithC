#include<iostream>

using namespace std;

// Friend Functions/Classes
class Car{
private:
	char name = 'A';
	friend void display(Car);
};

void display(Car obj){
	cout<<obj.name;
}



// Friend class
class Test{
private:
	int x = 2;

public:
	int y = 3;
	friend class Test2;
};

class Test2{
public:
	void show(Test &obj){
		cout<<obj.x;
	}
};




// Friend Functions




int main(){
	Test t1;
	Test2 t2;
	t2.show(t1);

	Car bmw;
	display(bmw);
}