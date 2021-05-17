#include <iostream>
using namespace std;
// vese to ye c ke kam ata hai pr maine galit se cpp main likh diya

int main(){
	int *price, n, i, ts;
	float avg;
	cout<<"enter the no.of objects";
	cin>>n;
	cout<<endl;

	price = (int*)malloc(n*sizeof(int));

	for(int i=0; i<n; i++){
		cout<<"object price";
		cin>>price[i];
	}

	ts = 0;
	for(int i=0; i<n; i++){
		ts = ts+price[i];
	}

	avg = ts/(float)n;
	cout<<"Total price="<<ts;
	cout<<"Avg price="<<avg;
}