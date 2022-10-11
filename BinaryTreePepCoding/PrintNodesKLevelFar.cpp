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

vector<Node *> NodeToRootPath(Node * root, int data){
    if(root == NULL) return {};

    vector<Node *> ans;
    if(root->data == data){
        ans.push_back(root);
        return ans;
    }
    vector<Node *> v1 = NodeToRootPath(root->left,data);
    vector<Node *> v2 = NodeToRootPath(root->right,data);
    if(v1.size()>0){
        ans = v1;
        ans.push_back(root);
    }
    if(v2.size()>0){
        ans = v2;
        ans.push_back(root);
    }
    return ans;
}

void printKthLevel(Node * root, int k, Node* block){
   if(root == NULL || k < 0 || block == root)return;
   
   if(k == 0){
    cout<<root->data<<" ";
   }
   printKthLevel(root->left, k-1, block);
   printKthLevel(root->right, k-1, block);
}


void printNodesKLevelFar(Node * root, int data, int k){
    vector<Node *> path = NodeToRootPath(root, data);
    // for(auto i:path){
    //     cout<<i->data;
    // }
    
    for(int i=0; i<path.size(); i++){
        printKthLevel(path[i], k-i, ((i==0)?NULL:path[i-1]));
    }
}

int main(){
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int size = sizeof(arr)/sizeof(int);

    Node * root = constructFromPepCoding(arr);
    printNodesKLevelFar(root, 37, 1);
}