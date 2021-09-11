#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int val){
        data = val;
    }
};

Node * lca(Node *root, int a, int b){
    if(!root) return NULL;
    if(root->data == a|| root->data == b) return root;
    
    Node *lh = lca(root->left, a, b);
    Node *rh = lca(root->right, a,b);

    if(!lh && !rh) return NULL;
    if(lh && rh) return root;
    if(lh) return lh;
    return rh;
}

Node * nodesinSupertree(Node * root, int toFind, int distance){
    // can be done very easly with static keyword
    static int flag=0;
    static int count=0;

    cout<<flag<<count<<endl;
    if(!root) return NULL;
    if(root->data == toFind){ flag = 1; count++; return NULL;}
    if(distance==count)return root;
    
    
    Node * lh = nodesinSupertree(root->left, toFind, distance);
    Node * rh = nodesinSupertree(root->right, toFind, distance);
    if(flag == 1) count++;
    
    if(lh) return lh;
    if(rh) return rh;
    return NULL;
    
}

void nodesinSubtree(Node * root, int distance, int curr_distance, vector<int> &n){
    if(!root) return;
    if(curr_distance == distance) n.push_back(root->data);
    nodesinSubtree(root->left, distance, curr_distance+1, n);
    nodesinSubtree(root->right, distance, curr_distance+1, n);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> n;
    Node * res = nodesinSupertree(root, 2, 1);
    // Node * res = lca(root, 3,4);
    if(res)
        cout<<res->data;
    else
        cout<<"no res";
    return 0;
}