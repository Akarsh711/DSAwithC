#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int minr, minc, maxr, maxc;
    minr = 0;
    minc = 0;
    maxr = matrix.size()-1;
    maxc = matrix[0].size()-1;

    int totalelement = matrix[0].size() * matrix.size();
    int cnt = 0;

    vector<int> ans;
    while(cnt<totalelement){
        // upperwall
        for(int i=minc; i<=maxc && cnt<totalelement; i++){
            ans.push_back(matrix[minr][i]);
            cnt++;
        }
        minr++;

        // rightwall
        for(int i=minr; i<=maxr && cnt<totalelement; i++){
            ans.push_back(matrix[i][maxc]);
            cnt++;
        }
        maxc--;

        // bottomwall
        for(int i=maxc; i>=minc && cnt<totalelement; i--){
            ans.push_back(matrix[maxr][i]); 
            cnt++;
        }
        maxr--;

        // leftwall
        for(int i=maxr; i>=minr && cnt<totalelement; i--){
            ans.push_back(matrix[i][minc]);
            cnt++;
        }
        minc++;
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}};
    vector<int> res = spiralOrder(v);
    for(auto i: res){
        cout<<i<<" ";
    }


}