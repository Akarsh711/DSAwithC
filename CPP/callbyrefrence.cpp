#include <iostream>

using namespace std;

// call by Refrence with two ways

void test(int &front){
    front++;
}

void test2(int *front){
    *front +1;
}

void test3(int arr[]){
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
}

int main(){
    int arr[3];
    int front = 0;
    cout << front <<endl;
    test(front);
    cout << front <<endl;
    test(front);
    cout << front <<endl;
    
    test3(arr);
    cout<< arr[0]<<endl;
    cout<< arr[1];
    cout<< arr[2];
}
