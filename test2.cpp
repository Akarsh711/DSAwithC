#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }

    
    // write your code here
    // All possible subarray
    for(int i=0;i<n;i++){
        for(int j=i; j<n; j++){
            for(int k = i; k<=j; k++){
                cout<<arr[k]<<" ";
            }        
            cout<<"\n";
        }
    }
}