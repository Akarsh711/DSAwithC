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

void levelOrderLineWiseZigZag(Node * root){
    // Mantra: Remove Print Add
    stack<Node *> q;
    stack<Node *> childq;
    q.push(root);
    int lvl = 1;
    while(q.size() > 0){
        root = q.top();
        cout<<root->data<<" ";
        q.pop();
        
        if(lvl%2 == 0){
            for(int i=root->children.size()-1; i>=0; i--){
                childq.push(root->children[i]);
            }
        }else{
            for(auto child: root->children){
                childq.push(child);
            }  
        }
            
        
        if(q.size() == 0){
            swap(q, childq);
            lvl++;
            cout<<"\n";
        }
    }
}

int main()
{
    // Generic Tree Constructor
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root = constructor(arr, 21);
    Display(root);
    cout<<"\n";
    levelOrderLineWiseZigZag(root);
    
    return 0;
}