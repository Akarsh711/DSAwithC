#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
	unordered_map<string, int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc2"] = 2;	
	ourmap["abc3"] = 3;
	ourmap["abc4"] = 4;
	ourmap["abc5"] = 5;
	ourmap["abc6"] = 6;
	ourmap["abc7"] = 7;
	
	unordered_map<string, int> :: iterator it = ourmap.begin();
	while(it!=ourmap.end()){
		pair<string, int> p = *it;
		cout<<it->first<<" "<<it->second<<endl;
		cout<<p.first<<" "<<p.second<<endl;
		it++;
	}
}
