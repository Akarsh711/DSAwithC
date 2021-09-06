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

Node * flatten(Node *root){
    if(!root) return NULL;
    Node * lh = flatten(root->left);
    Node * rh = flatten(root->right);
    if(lh==NULL&&rh==NULL)return root;
    if(lh!=NULL && rh!=NULL){
        Node*temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node * t = root->right;
        while(t->right!=NULL){
            t= t->right;
        }
        t->right = temp;
        return root;
    }
    if(lh!=NULL){
        root->right = lh;
        return root;
    }
    return root;
}

void printList(Node * root){
    if(!root) return;
    cout<<root->data;
    printList(root->right);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);
    Node *newroot = flatten(root);
    printList(newroot);
    cout<<"endof program";
    return 0;
}