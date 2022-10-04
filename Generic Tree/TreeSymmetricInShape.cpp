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

bool areMirror(Node * root1, Node * root2){
    if(root1->children.size() != root2->children.size()){
        return false;
    }

    for(int i=0; i<root1->children.size(); i++){
        int j = root1->children.size()-1-i;
        Node * c1 = root1->children[i];
        Node * c2 = root2->children[j];
        if(areMirror(c1, c2) == false) return false;
    }
    return 1;
}

bool isSymmetric(Node * root){
    return areMirror(root, root);
}

void levelOrderLineWise2(Node * root){
    // Mantra: Remove Print Add
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // O(N) Time
    // O(N) Space
    while(q.size() > 0){
        root = q.front();
        q.pop();
        if(root != NULL){
            cout<<root->data<<" ";
            for(auto child : root->children){
                q.push(child);
            }
        }
        else{
            cout<<"\n";
            if(q.size()>0)
                q.push(NULL);
        }
        // q.pop();
        
    }
}



int main()
{
    // Generic Tree Constructor
    // vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, 110, -1, -1, -1};
    vector<int> arr = {12, 20, 50, -1, 60, -1, -1, 30, 40, -1, 60};
    Node * root = constructor(arr, arr.size());
    cout<<isSymmetric(root);
    
    return 0;
}