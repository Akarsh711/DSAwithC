#include<bits/stdc++.h>
using namespace std;

    vector<int> data;

    void swaparr(int idx1, int idx2){
        int temp = data[idx1];
        data[idx1] = data[idx2];
        data[idx2] = temp;
    }

    int _size() {
        return data.size();
    }
    
    void upheapify(int ci){
        if(ci == 0) return;
        int pi = (ci-1)/2;
        if(data[pi]>data[ci]){
            swaparr(ci, pi);
            upheapify(pi);
        }
    }
   
    void downheapify(int pi){
    
        int mini = pi;
        int c1 = 2*pi+1;
        if(c1 < data.size() && data[c1]<data[mini] ){
            mini = c1;
        }

        int c2 = 2*pi+2;
        if(c2 < data.size() && data[c2]<data[mini] ){
            mini = c2;
        }

        if(mini != pi){
            swaparr(pi, mini);
            downheapify(mini);
        }
    }

    void add(int val) {
        data.push_back(val);
        upheapify(data.size()-1);
    }


    int _remove() {
     //write your code here
        if(data.size() == 0){
            cout<<"Underflow\n";
            return -1;
        }
        swaparr(0, data.size()-1);
        int val = data[data.size()-1];
        data.pop_back();
        downheapify(0);
        return val;

    }

    

    int peek() {
     //write your code 4
    //  cout<<"YEH";
        if(data.size() == 0){
            cout<<"Underflow\n";
            return -1;
        }
      return data[0];
    }

    



int main(){
   

  while(1){
      string str;
        getline(cin,str);
      if(str[0]=='a'){
          string num=str.substr(4,str.length());
          int val=stoi(num);
          add(val);
      }else if(str[0]=='r'){
          int val=_remove();
          if(val!=-1){
              cout<<val<<endl;
          }
      }else if(str[0]=='p'){
          int val=peek();
          if(val!=-1){
              cout<<val<<endl;
          }
      }else break;
  }


   
}

/*
INPUT:
add 10
add 20
add 30
add 40
peek
add 50
peek
remove
peek
remove
peek
remove
peek
remove
peek
quit
*/

/*
OUTPUT:
10
10
10
20
20
30
30
40
40
50

*/