#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    vector<Node *> children;
};

Node* newNode(int data){
    Node * node = new Node();
    node->data = data;
    return node;
}

Node *constructor(vector<int> arr, int n){
    Node * root = NULL;
    stack<Node*> st;
    for(int i=0; i<n; i++){
        if(arr[i] == -1){
            st.pop();
        }else{
            Node * t = newNode(arr[i]);
            if(st.size() == 0){
                root = t;
                st.push(t);
            }
            else{
                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }
    return root;
}

void Display(Node * root){
    if(root == NULL) return;
    
    for(auto i: root->children){
        cout<<i->data<<" ";
        Display(i);
    }
}

int dia = 0;

int findDiameterReturnHeight(Node * node){
    int dch = -1; //deepest child height
    int sdch = -1; //second deepest child height

    for(Node * child : node->children){
        int ch = findDiameterReturnHeight(child); //returns child height
        if(ch > dch){
            sdch = dch;
            dch = ch;
        }
        else if(ch > sdch){
            sdch = ch;
        }
    }
    if(dch + sdch + 2 > dia){ // +2 because adding two edges of the root
        dia = dch+sdch+2;
    }
    dch +=1;
    return dch;
}
int main()
{
    // Generic Tree Constructor
    vector<int> arr = {80, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100};
    Node * root = constructor(arr,arr.size());
    findDiameterReturnHeight(root);    
    cout<<dia<<endl;
    return 0;
}