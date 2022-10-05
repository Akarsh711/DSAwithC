#include<bits/stdc++.h>

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

int ceilans = INT_MAX;
int floorans = INT_MIN;
void findCeilAndFloor(Node * node, int data){
    if(node->data > data){
        if(node->data < ceilans){
            ceilans = node->data;
        }
    }
    if(node->data < data){
        if(node->data > floorans){
            floorans = node->data;
        }
    }
    for(auto child: node->children){
        findCeilAndFloor(child, data);
    }
}


int main(){
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root = constructor(arr, arr.size());
    findCeilAndFloor(root, 20);
    cout<<"ceil : "<<ceilans<<"\n";
    cout<<"floor : "<<floorans;
    
}
