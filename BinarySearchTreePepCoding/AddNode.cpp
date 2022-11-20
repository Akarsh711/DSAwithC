#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * left = NULL;
    Node * right = NULL;
    Node(int val, Node *lc, Node *rc){
        left = lc;
        right = rc;
        data = val;
    }
    Node(int val){
        data = val;
    }
};

Node * addNode(Node * root, int val){
    if(root == NULL){
          return new Node(val, NULL, NULL);
    }
    if(val > root->data){
        root->right = addNode(root->right, val);
    }else if(val < root->data){
        root->left = addNode(root->left , val);
    }
    return root;
}

void display(Node * root){
    if(root == NULL)return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

struct Node * constructBST(int arr[], int lb, int ub){
    if(lb>ub)return NULL;
    int mid = (lb+ub)/2;
    Node * lc= constructBST(arr, lb, mid-1);
    Node * rc = constructBST(arr, mid+ 1 ,ub);

    Node * root = new Node(arr[mid], lc, rc);
    return root;
    
}

int main(){
    int arr[] = {12,25, 37, 50, 62, 75, 87};
    int size = sizeof(arr)/sizeof(int);
    Node *root = constructBST(arr, 0, size-1);
    Node *newRoot = addNode(root, 80);
    display(root);
    // It searches in log(n) which is better as compare to BT O(n)
}
