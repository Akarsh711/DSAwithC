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

//Mine's Solution 
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

// Apni Microsoft Wali Didi's Solution
void flattenPro(Node * root){
    if(!root) return;
    if(root->left){
        flattenPro(root->left);
        Node * temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node *t = root->right;
        while(t->right!=NULL) t=t->right;
        t->right = temp;
    }
    flattenPro(root->right);
    
}

// Striver's Flatten Solution 
void flatten3(Node * root, Node* prev){
    if(!root) return;
    flatten3(root->right, prev);
    flatten3(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

// Loopy Solution
/*
    It follows top down approach
    means it put the whole subtree first and then solve further

    Whereas in Recursion we first solve the subtree then we put on to the right 
*/
void flatten4(Node * root){
    Node *curr= root;
    while(curr){
        if(curr->left!=NULL){
            Node *temp = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            Node * t = curr->right;
            while(t->right!=NULL) t = t->right;
            t->right = temp;
        }
        curr= curr->right;
    }
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
    cout<<"ayaay"<<endl;
    // Node *newroot = flatten(root);
    flattenPro(root);
    printList(root);
    cout<<"endof program";
    return 0;
}