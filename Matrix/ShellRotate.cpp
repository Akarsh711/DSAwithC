#include<bits/stdc++.h>
#define int long long
using namespace std;


void display(vector<vector<int>>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void reverseArr(vector<int> &arr, int i, int j){
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--; 
        i++;
    }
}

vector<int> rotatearray(vector<int> arr, int r){
    // for(int i=0; i<arr.size(); i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int s = arr.size();
    r = r%s;
    if(r<0)
        r = arr.size()+r;
    
    // cout<<r<<" "<<arr.size()<<endl; 
    // reverse(arr.begin(), arr.end());
    reverseArr(arr, 0, arr.size()-1);
    reverseArr(arr, 0, arr.size()-r-1);
    reverseArr(arr, arr.size()-r, arr.size()-1);
    
    // for(int i=0; i<arr.size(); i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return arr;
}
vector<int> shellTo1D(vector<vector<int>> matrix, int s, int r){
    int minr, minc, maxr, maxc;
    minr = s-1;
    minc = s-1;
    maxr = matrix.size() - s;
    maxc = matrix[0].size() - s;

    vector<int> ans;
    // topwall
    for(int i=minc; i<=maxc; i++){
        ans.push_back(matrix[minr][i]);
    }
    minr++;
  
    // right wall
    for(int i=minr; i<=maxr; i++){
        ans.push_back(matrix[i][maxc]);
    }
    maxc--;

    // bottom wall
    for(int i=maxc; i>=minc; i--){
        ans.push_back(matrix[maxr][i]);
    }
    maxr--;

    // left wall
    for(int i=maxr; i>=minr; i--){
        ans.push_back(matrix[i][minc]);
    }


    return ans;
}

vector<vector<int>> oneDtoShell(vector<int> arr, vector<vector<int>> matrix, int s, int r){
    int minr, minc, maxr, maxc;
    minr = s-1;
    minc = s-1;
    maxr = matrix.size() - s;
    maxc = matrix[0].size() - s;

    int cnt = 0;
    
    // topwall
    for(int i=minc; i<=maxc; i++){
        matrix[minr][i]= arr[cnt];
        cnt++;
    }
    minr++;
  
    // right wall
    for(int i=minr; i<=maxr; i++){
        matrix[i][maxc]= arr[cnt];
        cnt++;
    }
    maxc--;

    // bottom wall
    for(int i=maxc; i>=minc; i--){
        matrix[maxr][i]= arr[cnt];
        cnt++;
    }
    maxr--;

    // left wall
    for(int i=maxr; i>=minr; i--){
        matrix[i][minc]= arr[cnt];
        cnt++;
    }


    return matrix;
}

void fillShellFromOned(vector<vector<int>> &arr, int s, vector<long long> &oned){
    int minr = s-1;
    int minc = s- 1;
    int maxr = arr.size() -s;
    int maxc = arr[0].size() -s;
    // int sz = lw + bw+ rw+ tw - 4;
    // int sz = 2*(lw)+ 2*(bw) - 4
    // int sz = 2*(maxr - minr + maxc - minc);

    // vector<int> oned(sz);
    // lw
    int idx = 0;
    for(int i=minr, j= minc; i<=maxr; i++){
        arr[i][j] = oned[idx];
        idx++;
    }

    // bw
    for(int i=maxr, j=minc+1; j<=maxc; j++){
        arr[i][j] = oned[idx];
        idx++;
    }
    // rw
    for(int i=maxr - 1, j=maxc; i>=minr; i--){
        arr[i][j] = oned[idx];
        idx++;
    }
    // tw
    for(int i=minr, j=maxc-1; j>=minc+1; j--){
        arr[i][j] = oned[idx];
        idx++;
    }
    // display(arr);
}


vector<vector<int>> sol(vector<vector<int>> matrix, int s, int r){

    vector<int> onedarr = shellTo1D(matrix, s, r);
    onedarr = rotatearray(onedarr,r);

    return oneDtoShell(onedarr, matrix, s, r);
    // fillShellFromOned(matrix, s, onedarr);
    return matrix;
}
int32_t main()
{
    int n, m, s, r;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    cin >> s >> r;
    
    // write your code here
    matrix = sol(matrix, s, r);
    // cout<<endl;
    display(matrix);

/* SAMPLE INPUT
5
7
11
12
13
14
15
16
17
21
22
23
24
25
26
27
31
32
33
34
35
36
37
41
42
43
44
45
46
47
51
52
53
54
55
56
57
2
3
*/

/*EXPECTED OUTPUT
11 12 13 14 15 16 17 
21 25 26 36 46 45 27 
31 24 33 34 35 44 37 
41 23 22 32 42 43 47 
51 52 53 54 55 56 57 
*/
}