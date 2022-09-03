/*
PROBLEM : In this problem we have given an array and we given an integer 
Our role is to find numbers from array which together form the integer
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// In this we need to neglect the first value of returned array as they are either -9 or NULL because of base cases
vector<int> howSum(int targetSum, vector<int> numbers, int size){
    if(targetSum == 0) return {NULL};
    if(targetSum < 0) return {-9};

    vector<int> remainderResult;
    for(int i=0; i<size; i++){	
        remainderResult = howSum(targetSum - numbers[i], numbers, size);
        if(remainderResult[0] == NULL){
            remainderResult.push_back(numbers[i] );
            return remainderResult;
        }
    }
    return {-9};
}

vector<int> howSumMemoized(int targetSum, vector<int> numbers, map<int, vector<int>> &dick, int size){
    if(targetSum == 0) return {NULL};
    if(targetSum < 0) return {-9};

    vector<int> remainderResult;
    for(int i=0; i<size; i++){	

        remainderResult = howSum(targetSum - numbers[i], numbers, size);
        if(remainderResult[0] == NULL){
            remainderResult.push_back(numbers[i]);
            dick[targetSum] = remainderResult;
            return dick[targetSum];
        }
    }
    dick[targetSum] = {-9};
    return dick[targetSum];
}


int main(){
map<int , vector<int>> memo;

vector<int> num = {2, 3, 5, 8};
vector <int> result;

result = howSum(8, num, num.size());
for(int i=1; i<result.size(); i++)
	cout<< result[i];

}