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

void levelOrder(Node * root){
    if(!root) return;
    queue<Node *> q;
    q.push(root);
    while(q.size() > 0){
        Node * temp = q.front();
        cout<<temp->data<<" ";
        
        
        for(auto i: temp->children){
            q.push(i);
        }
        q.pop();
    }
}

bool isSimillar(Node * root1, Node * root2){
    if(root1->children.size() != root2->children.size()){
        return false;
    }

    for(int i=0; i<root1->children.size(); i++){
        if(!isSimillar(root1->children[i], root2->children[i])) return false;
    }
    return true;
}




int main()
{
    // Generic Tree Constructor
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    vector<int> arr2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40};
    Node * root1 = constructor(arr, arr.size());
    Node * root2 = constructor(arr2, arr2.size());
    cout<<isSimillar(root1, root2);
    
    return 0;
}