#include<bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    vector<Node *> children;
};

int ss = 0;
int height = 0;
int maxv = INT_MIN;
int minv = INT_MAX;

Node* newNode(int data){
    Node * node = new Node();
    node->data = data;
    return node;
}
Node * constructor(vector<int> arr, int size){
    Node * mainroot = NULL;
    stack<Node *> st;
    for(int i=0; i<size; i++){
        if(arr[i] == -1){
            st.pop();
        } else{
            Node * root = newNode(arr[i]);
            if(st.size() == 0){
                mainroot = root;
            }else{
                st.top()->children.push_back(root);
               
            }
            st.push(root);
        }
    }
    return mainroot;
}
void multiSolver(Node * root, int depth){
    ss++;
    minv = min(minv, root->data);
    maxv = max(maxv, root->data);
    height = max(height, depth);
    
    for(auto child:root->children){
        multiSolver(child, depth+1);
    }

}


int main(){
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root = constructor(arr, arr.size());
    multiSolver(root, 0);
    cout<<"Size = "<<ss<<"\n";
    cout<<"MIN = " <<minv<<"\n";
    cout<<"MAX = "<<maxv<<"\n";
    cout<<"Height = "<<height<<"\n"; 
}
