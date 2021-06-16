#include<iostream>

using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	// if(a>b){
	// 	if(a>c){
	// 		cout<<"a is greater";
	// 	}
	// }
	// else if(c>b){
	// 		cout<<"c is grater";
	// 	}
	// 	else{
	// 		cout<< "b is greater";
	// 	}


	if(a<b && a<c){
		if(b<c)
			cout<<b;
		else
			cout<<c;
	}
	else if(a>b && a>c){
		if(b>c)
			cout<<b;
		else
			cout<<c;
	}

	if(a<=b && a>=c){cout<<a;}
	if(a>=b&& a<=c){cout<<a;}
}

