/*Problem From Code Chef Search it by filename */

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    
    while(T--){
        int N;
        cin>>N;

        int oddcount =0;
        int evencount = 0;
        for(int i=0; i<A.size(); i++){
            int temp;
            cin>>temp;
            if(temp%2==0)
                evencount++;
            else
                oddcount++;
        }
        
        int evenindexes = N/2;
        int oddindexes = N- N/2;
        
        int res = min(evencount, oddindexes)+min(oddcount, evenindexes);
        cout<<res;
        }
    
    /*
        SAMPLE INPUT
        3
        3
        1 2 3
        3
        2 4 5
        2
        2 4
    */
}