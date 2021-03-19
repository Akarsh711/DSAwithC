#include<iostream>

using namespace std;

template <typename O>
class One{
	protected:
		O x = 4;
		int y = 45;
	public:
		void show(){
			cout<<"Value of x:"<<x;
		}
};

template <typename T>
class Two:public One<T>{
public:
	void display(){
		cout <<"XXX:"<<y;
	}
};

int main(){
	Two <int>t;
	t.display();
}