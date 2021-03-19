#include<iostream>

using namespace std;

int main(){


	// Variable sized array (An array which have variable size sub array)
	int n, q, sub_size; //sub_size = sub array's size
    cin>>n;
    int **arr = new int*[n];
    cin>>q;
    
    for(int i=0; i<n; i++){
        cin>>sub_size;
        arr[i] = new int[sub_size];
        for(int j=0; j<sub_size; j++){
            cin>>arr[i][j];
        }
    }
    
    // Search Code
    int **to_search = new int*[q];
    for(int i=0; i<q; i++){
        to_search[i] = new int[2];
        for(int j=0; j<2; j++){
            cin>> to_search[i][j];
        }
    }

    for(int i=0; i<q; i++){
        // cout << endl;
        int ith = to_search[i][0];
        int jth = to_search[i][1];
        cout<< arr[ith][jth] <<endl;
        // cout<<ith<<jth <<endl;
        
    }
    // for(int i=1; i<q; i++){
    //     cout <<endl;
    //     for(int j=0; j<5; j++){
    //         cout << arr[i][j];
    //     }
    // }
    return 0;
	
}

