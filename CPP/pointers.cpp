#include<iostream>

using namespace std;
int main(){
    int avar = 9;
    int *p = &avar;
    int **q = &p;
    cout << q;
}