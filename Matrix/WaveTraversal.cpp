#include<bits/stdc++.h>
using namespace std;

void waveTraverse(vector<vector<int>> arr){
    int up = 0;
    for(int i=0; i<arr[0].size(); i++){
        for(int j=0; j<arr.size(); j++){
            if(up == 0){
                cout<<arr[j][i]<<"\n";
            } else{
                cout<<arr[arr.size()-j-1][i]<<"\n";
            }
        }
        up = (up?0:1);
        // if(up) up = 0;
        // else up = 1;
    }
}
int main(){
    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    waveTraverse(arr);
}