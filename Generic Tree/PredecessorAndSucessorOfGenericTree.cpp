#include<bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    vector<Node *> children;
};

int predecessor;
int successor;
int state = 0;


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

void findPredecessorAndSuccessor(Node * root, int data){
    if(state == 0){
        if(root->data == data){
            state = 1;
        }
        else{
            predecessor = root->data;
        }
    }
    else if(state == 1){
        successor = root->data;
        state = 2;
    }
    for(auto child: root->children){
        findPredecessorAndSuccessor(child, data);
    }
}


int main(){
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root = constructor(arr, arr.size());
    findPredecessorAndSuccessor(root, 50);
    cout<<"predecessor : "<<predecessor<<"\n";
    cout<<"successor : "<<successor<<"\n";
}
