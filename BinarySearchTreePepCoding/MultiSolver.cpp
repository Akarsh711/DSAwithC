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

int findSize(Node * root){
    int sum = 0;
    sum+=findSize(root->left);
    sum+=findSize(root->right);
    return sum+1;
}

void findMax(){

}

void findMin(){

}

void findMax(){

}

void findSum(){

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
    cout<<findSize(root);
}
