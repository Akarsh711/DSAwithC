#include<bits/stdc++.h>
using namespace std;

class MedianPriortiyQueue{
    public:
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;

        int sizeofmq(){
            return left.size() + right.size();
        }

        void balance(){
            if(left.size() - right.size() == 2){
                right.push(left.top());
                left.pop();
            } else if(right.size() - left.size() == 2){
                left.push(right.top());
                right.pop();
            }
        }

        void add(int val){
            if(right.size() > 0 && val> right.top()){
                right.push(val);
            } else{
                left.push(val);
            }       
            balance();     
        }
    
        int peek(){
            if(sizeofmq() == 0){
                cout<<"Underflow";
                return -1;
            }

            if(left.size()>=right.size()){
                return left.top();
            } else{
                return right.top();
            }
        }

        void remove(){
            if(sizeofmq() == 0){
                cout<<"Underflow";
                return;
            }

            if(left.size()>=right.size()){
                return left.pop();
            } else{
                return right.pop();
            }
        }
        
};

int main(){
    // MedianPriortiyQueue obj;
    // obj.add(1);
    // obj.add(2);
    // obj.add(3);
    // cout<<obj.peek();
    int t;
    while(t--){
        MedianPriortiyQueue obj;
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            obj.add(x);
            cout<<floor(obj.peek())<<"\n";
        }
    }
    return 0;
}