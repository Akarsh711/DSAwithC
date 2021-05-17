
// Sample code to perform I/O:

#include <iostream>
#include<string>

using namespace std;
int girls(string s){
    int n = s.length();
    char arr[n];
    for(int i=0; i<n; i++){
        arr[i] =s[i];
    }
    
    int count;
    for(int i=0; i<n; i++){
        if(arr[i]!='6')
            count++;

        // cout<<arr[i];
    }
    if(s[n-1]=='6'){
        cout<<"in fi";
        // count = -1;
        }
    cout<<"in else";
    return count;
}
int main() {
    string num;
    
    cin >> num; 
    cout<<girls(num); 
}

