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

int sum = 0;
int size = 0;
int height = 0;
int maxv = INT_MIN;
int minv = INT_MAX;

int multiSolver(Node * root, int ht){
    if(root == NULL) return 0;

    maxv = max(maxv, root->data);
    minv = min(minv, root->data);
    size++;
    int val1 = multiSolver(root->left, ht+1);
    int val2 = multiSolver(root->right, ht+1);
    height = max(ht, height);
    
    sum = val1+val2+root->data;
    return sum;

}

int findSize(Node * root){
    if(root == NULL) return 0;

    return findSize(root->left)+findSize(root->right)+1;
}

int findSum(Node * root){
    if(root == NULL) return 0;

    int s1 = findSum(root->left);
    int s2 = findSum(root->right);
    int sum = s1+s2+root->data;
    return sum;
}

int findHeight(Node *root){
    if(root == NULL) return 0;

    int h1 = findHeight(root->left);
    int h2 = findHeight(root->right);
    int height = max(h1,h2)+1;
    return height;
}

int findMax(Node * root){
    if(root == NULL) return 0;

    int m1 = findMax(root->left);
    int m2 = findMax(root->right);
    return max(root->data, max(m1, m2));
}

// Simillarly for MIN

int main(){
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    Node * root = constructFromPepCoding(arr);
    multiSolver(root, 0);
    // cout<<sum<<"\n";
    // cout<<size<<"\n";
    // cout<<height<<"\n";
    // cout<<maxv<<"\n";
    // cout<<minv<<"\n";
    
    cout<<findSum(root)<<"\n";
    cout<<findSize(root)<<"\n";
    cout<<findHeight(root)<<"\n";
    cout<<findMax(root)<<"\n";
    // preOrder(root);
}