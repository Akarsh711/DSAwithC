#include<bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node * constructFromPepCoding(int arr[]){
    Node * root = new Node(arr[0]);
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    int idx = 0;
    while(!st.empty()){
        pair<Node *, int> *top = &st.top();
        if(top->second == 1){
            idx++;
            if(arr[idx] != -1){
                Node * ln = new Node(arr[idx]);
                top->first->left = ln;
                st.push({ln, 1});
            }
            top->second++;

        } else if(top->second == 2){
             idx++;
            if(arr[idx] != -1){
                Node * rn = new Node(arr[idx]);
                top->first->right = rn;
                st.push({rn, 1});
            }
            top->second++;
        } else{
            st.pop();
        }
    }
    return root;
}

void preOrder(Node * root){
    if(root == NULL) return;
    cout<<root->data<<"\n";
    preOrder(root->left);
    
    preOrder(root->right);
}

void findSingleChildNode(Node * root){
    if(root == NULL) return;
    if(root->left && !root->right) cout<< root->data<<"\n";
    if(!root->left && root->right) cout<< root->data<<"\n";
    findSingleChildNode(root->left);
    findSingleChildNode(root->right);
}

int main(){
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int size = sizeof(arr)/sizeof(int);
    Node * root = constructFromPepCoding(arr);

    findSingleChildNode(root);

    // preOrder(root);
}