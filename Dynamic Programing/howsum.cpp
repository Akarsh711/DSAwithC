#include<iostream>
#include<vector>
#include <string>
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
            remainderResult.push_back(numbers[i]);
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



vector<int> num = {5,3,4,7};
vector <int> result;

result = howSumMemoized(7, num, memo, num.size());
for(int i=0; i<result.size(); i++)
	cout<< result[i];

}