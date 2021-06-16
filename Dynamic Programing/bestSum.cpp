#include<iostream>
#include<vector>

using namespace std;


// same as how sum but here we find best way where number of element in array
// should be least as possible as how sum return's first way
vector<int> bestSum(int sum, vector<int> arr){
	if(sum == 0) return {1};
	if(sum <0) return {0};

	vector<int> shortest_comb = {0};
	for(int i=0; i<arr.size(); i++){

		vector<int> out_put = bestSum(sum-arr[i], arr);

		if(out_put[0]==1){
			out_put.push_back(arr[i]);
			if(shortest_comb[0] == 0 || out_put.size() < shortest_comb.size())
				shortest_comb =  out_put;
		}
	}
	return shortest_comb;
}
	
int main(){
	vector<int> arr= {2, 3, 5};
	int sum = 8;

	vector<int> result = bestSum(sum, arr);

	for(int i=0; i<result.size(); i++)
		cout<<result[i];
}