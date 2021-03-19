#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cout<<"enter size of array";
    cin>>n;
    int **arr = new int*[n];
    int *cols_arr = new int[n];
    // Let's create a Two Dimensional Array 
    for(int i=0; i<n; i++){
        cout <<"Enter Size for Second Array";
        cin>>cols_arr[i];
        arr[i] = new int[cols_arr[i]];
        for(int j=0; j<cols_arr[i]; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        cout <<endl;

        for(int j=0; j<cols_arr[i];j++){
            cout << arr[i][j]<< " ";
        }
    }
    // cout << arr[0][1];
    return 0;
}

