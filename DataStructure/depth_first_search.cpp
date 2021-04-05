#include <iostream>
// #include <map>
#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		Graph(){
			map<int, list<int>> dict= {
				{2,{5,3,4}},
				{3,{4,5,2}},
				{4,{5,2,3}},
				{5,{2,3,4}},
			};

		}

		void display(){
			cout << dict[2];
		}

};

int main(){
	Graph g;
}