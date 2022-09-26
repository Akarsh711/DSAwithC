/*
NODES AT DISTANCE K:
    It takes a node(target) in the tree and finds the nearby nodes according to distance(k) given.
    It searches subtree as well as supertree.

    Example:
            1
           / \
          2   5
         / \   \
        3  4    6

        for 5 with distance 1 we should have output 6, 1
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int val){
        data = val;
    }
};

// CASE 1 For the subtree
void printSubtreeNodes(Node * root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }

    printSubtreeNodes(root->left , k-1);
    printSubtreeNodes(root->right , k-1);
}


// CASE 2 For the supertree
int printNodeAtK(Node * root, Node * target, int k){
    if(root==NULL){
        return -1;
    }

    // It will solve the first case
    if(root == target){
        printSubtreeNodes(root, k);
        return 1;
    }

    int dl = printNodeAtK(root->left, target, k);
    if(dl !=-1){ //It means we found our target in left sub tree
        if(dl == k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->right, k-dl-1);
        }
        return 1+dl;
    }
     
    int dr = printNodeAtK(root->right, target, k);
    if(dr!=-1){
        if(dr == k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->left, k-dr-1);
        }
        return 1+dr;
    }
    return -1;
}


/*
    Explaning printNodeAtK in simple words:
    if we found target in left then we'll check distance for subtree and for right tree from anccesstor
    if we found target in right then we'll check distance for subtree and for left tree from anccesstor

    Why k-d-1?
    -1 one is there because we are refering root->left or root->right in which we lost a distance by 1.    
    

*/
int main(){
    	Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->left->left = new Node(5);
    root->left->left->right = new Node(6);
    root->left->right = new Node(7);

    // Node * target = new Node(4);
    printNodeAtK(root,  root->left->left->left, 2);
    return 0;
}