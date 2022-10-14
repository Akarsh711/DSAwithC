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

void nodeToRootSumInRange(Node * root, string path, int sum, int lo, int hi){
    if(root == NULL){
        return;
    }

    if(root->left ==NULL && root->right == NULL){
        sum+=root->data;
        path+= root->data;
        if(sum>=lo && sum<=hi){
            cout<<path<<"\n";
        }
        return;
    }
    nodeToRootSumInRange(root->left, path+to_string(root->data) + " ", sum+root->data, lo, hi);
    nodeToRootSumInRange(root->right, path+to_string(root->data) + " ", sum+root->data, lo, hi);
}

int main(){
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int size = sizeof(arr)/sizeof(int);

    Node * root = constructFromPepCoding(arr);
    // preOrder(root);
    nodeToRootSumInRange(root, "", 0, 0, 1000);
}