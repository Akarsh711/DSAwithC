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


void Mirror(Node * root){
    if(root == NULL) return;

    for(auto i: root->children){
        Mirror(i);
    }

    // Can also be done using reverse()
    reverse(root->children.begin(), root->children.end());
    // int i = 0, j = root->children.size()-1;
    // while(i<j){

    //     Node * temp = root->children[i];
    //     root->children[i] = root->children[j];
    //     root->children[j] = temp;

    //     i++;
    //     j--; 
    // }
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




int main()
{
    // Generic Tree Constructor
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    vector<int> arr2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root1 = constructor(arr, arr.size());
    // reverse(arr2.begin(), arr2.end());
    Node * root2 = constructor(arr2, arr2.size());
    Mirror(root2);
    cout<<areMirror(root1, root2);
    
    return 0;
}