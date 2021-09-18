#include <iostream>
#include<map>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        map<int, int> inputarr;
        map<int, int> res;
        // map<int, int> oper;
        int N,X;
        cin>>N>>X;

        for(int i=0; i<N; i++){
            int temp;
            cin>>temp;
            inputarr[temp]++;
        }

        // Do the XOR and check the if greatness
        for(auto i: inputarr){
            if(X!=0)
                res[i.first^X] ++; //or you can do shortend res[i.first ^ X];
                // MM putting here = i.second
        }

        int greatest=0, low=0; 
        for(auto i: inputarr){
            if((i.second+res[i.first])>greatest){
                
                greatest = i.second+res[i.first];
                low = res[i.first];
            }
            else if((i.second+res[i.first]) == greatest)
                if(res[i.first]<low) low = max(res[i.first], low);//MM max

            // OR
            // greatest = max(res[i.first], greatest);
            // low = max(res[i.second], low);
        }
        cout<<greatest<<" "<<low<<endl;
    }
}
