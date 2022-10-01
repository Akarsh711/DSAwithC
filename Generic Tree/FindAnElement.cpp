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
    // if(root == NULL) return;
    
    queue<Node *> q;
    q.push(root);
    // q.push(NULL);
    // cout<<"called";
    while(!q.empty()){
        
        root = q.front();
        q.pop();
        cout<<root->data<<" ";
        for(auto i: root->children){
            q.push(i);
        }
        
    }
}

Node * getTail(Node * root){
    while(root->children.size()>0){
        root = root->children[0];
    }
    return root;
}

// TC = O(N^2)
// SC = O(N) or SC = O(1)
void linearize(Node * root){
    for(auto child:root->children){
        linearize(child);
    }

    while(root->children.size()>1){
        // removing the last children 
        Node * last = root->children.back();
        root->children.pop_back();
        // last become second last
        Node *sl = root->children[root->children.size()-1];
        Node * tail = getTail(sl);
        tail->children.push_back(last);
    }

}

bool findElement(Node * root, int val){
    if(root->data == val) return true;

    for(auto child:root->children){
        if(findElement(child, val)){
            return true;
        }
    }
    return false;
}


int main()
{
    // Generic Tree Constructor
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root = constructor(arr, 21);

    if(findElement(root, -1)) cout<<"True";
    else cout<<"False";
    return 0;
}