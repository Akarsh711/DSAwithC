#include <map>
#include<iostream>
#include <string>


using namespace std;

// unoptimized/unmemoized version
int unogridTraverler(int n ,int m){
	if(n==0||m==0) return 0;
	if(n==1&&m==1) return 1;
	int x = unogridTraverler(n-1, m);
	int y = unogridTraverler(n, m-1);
	return x+y;
}

unsigned long gridTraveler2(int n ,int m, map<string, int> &dick){
	string key= to_string(n) + to_string(m);

	if(dick.count(key)!=0){return dick[key];}

	if(n==0||m==0) return 0;
	if(n==1&&m==1) return 1;

	dick[key] = gridTraveler2(n-1, m, dick)+ gridTraveler2(n, m-1, dick);
	return dick[key];
}




int main(){
	map<char, char> my_map = {
		{'a','1'},
		{'b','2'},
		{'c','3'}
	};
	
	map<string, int> dict;
	map<string, int> dict2;


	map <string, int> dick;
	cout<< gridTraveler2(100,100, dick);
	cout<<dick["1010"];
}


