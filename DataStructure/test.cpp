#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    vector<int> test;

    for(auto i =0; i<9; i++){
        test.push_back(i);
    }

    for(int i =0; i<9; i++){
        cout<<test[i];
    }
    cout<<endl<<test.size();

}