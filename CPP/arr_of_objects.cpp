#include<iostream>
#include<string>
using namespace std;

class Student{
	int rollno;
	string name;

	public:
		void setValue(){
			cout << "Enter Rollno:";
			cin >> rollno;
			cout <<endl<< "Enter name:";
			cin >> name;			
		}
		void getValue(){
			cout << "Entered Value";
			cout<<rollno<<name;
		}
};

int main(){
	Student *p, s[3];
	p = &s[0];
	// cout << *p;

	// cout << p++;
	for(int i=0; i<3; i++){
		p->setValue();
		p->getValue();
		p++;
	}
	for(int i=0; i<3; i++){
		cout <<s[i].getValue();
	}
}