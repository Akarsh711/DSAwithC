#include<bits/stdc++.h>
using namespace std;

struct Node{

};

int main(){
    int t;
    cin>>t;


    while(t--){
        int N;
        cin>>N;

        vector<int> x;
        vector<int> y;
        map<pair<int, int>, vector<vector<int>>> eqs;
        vector<int> ip; //intersecting points;

        for(int i=0;i<N; i++){
            int temp;
            cin>>temp;
            x.push_back(temp);
        }
        for(int i=0; i<N; i++){
            int temp;
            cin>>temp;
            y.push_back(temp);
        }

        // Line Equation
        for(int i=0; i<N; i++){
            /*
                1, 0, -xi ++
                0, 1, -yi ++
                1, -1, -xi+yi ++
                1, 1 , -xi-yi ++
            */

            // [a, b, c]4

            /*
                Type of lines    x      y
                -----------------------------
                90 deg          0         1
                135 deg         1         1
                180 deg         1         0
            */
            
            eqs[{x[i], y[i]}][0] = {0, 1, -x[i]};
            eqs[{x[i], y[i]}][1] = {1, 0, -y[i]};
            eqs[{x[i], y[i]}][2] = {1,1 ,(y[i]+x[i])};
            eqs[{x[i], y[i]}][3] = {1, -1, (y[i]-x[i])};
        }

        // Finding intersection points
        // void intersect(auto line1, auto line2){
            
        // }

        
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                //loop for line for point A.
                for(int k=0; k<4; k++){
                    // loop for line for point B.
                    for(int l=0; l<4; l++){

                    }
                }
            }
        }
        
    }
}