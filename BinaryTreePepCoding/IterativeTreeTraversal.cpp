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




void iteratvieSol(Node * root){
    stack<pair<Node *, int>>st;
    st.push({root, 1});
    
    string pre;
    string in;
    string post;
    while(!st.size() > 0){
        pair<Node *,int> top = st.top();
        st.pop();
        
        if(top.second == 1){
            cout<<top.first->data;
            pre+=top.first->data+" ";
            top.second++;
            st.push(top);
            if(top.first->left!=NULL)
                st.push({top.first->left, 1});
        }
        else if(top.second == 2){
            cout<<top.first->data<<" ";
            in+=top.first->data+" ";
            top.second++;
            st.push(top);
            
            if(top.first->right != NULL)
                st.push({top.first->right, 1});
        }
        else if(top.second == 3){
            post+=top.first->data+" ";
        }
    }
    cout<<pre<<"\n";
    cout<<in<<"\n";
    cout<<post<<"\n";
}

int main(){
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int size = sizeof(arr)/sizeof(int);

    Node * root = constructFromPepCoding(arr);
    iteratvieSol(root);
}