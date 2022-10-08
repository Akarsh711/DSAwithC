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

// -1 : Preorder, +1
// child.size() : Postorder, Pop()
// 0 to child.size() -1 : Push Child, +1

void prePostOrder(Node * root){
     stack<pair<Node*, int>> st;
     st.push({root, -1});
     
     string pre;
     string post;
     while(st.size() > 0){
        pair<Node *, int> *top = &st.top();
        // st.pop();
        if(top->second == -1){
            pre+=to_string(top->first->data)+" ";
            // cout<<top.first->data<<" ";
            top->second++;
            // st.push(top);
        } 
        else if(top->second == top->first->children.size()){
            post+= to_string(top->first->data)+" ";
            st.pop();
        }
        else{
            pair<Node *, int> cp  = {top->first->children[top->second], - 1};
            top->second++;
            // st.push(top)
            st.push(cp);
        }
     }
     cout<<pre<<"\n";
     cout<<post<<"\n";
}

// or you can also do this way
void prePostOrder2(Node * root){
     stack<pair<Node*, int>> st;
     st.push({root, -1});
     
     string pre;
     string post;
     while(st.size() > 0){
        pair<Node *, int> top = st.top();
        st.pop();
        if(top.second == -1){
            pre+=to_string(top.first->data)+" ";
            top.second++;
            st.push(top);
        } 
        else if(top.second == top.first->children.size()){
            post+= to_string(top.first->data)+" ";
        }
        else{
            pair<Node *, int> cp  = {top.first->children[top.second], - 1};
            top.second++;
            st.push(top);
            st.push(cp);
        }
     }
     cout<<pre<<"\n";
     cout<<post<<"\n";
}
int main()
{
    // Generic Tree Constructor
    vector<int> arr = {80, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100};
    Node * root = constructor(arr,arr.size());
    prePostOrder(root);    
    prePostOrder2(root);
    return 0;
}