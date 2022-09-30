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

void levelOrderLineWise(Node * root){
    // Mantra: Remove Print Add
    queue<Node *> q;
    queue<Node *> childq;
    q.push(root);
    
    O(N) Time 
    O(2N) Space
    while(q.size() > 0){
        root = q.front();
        cout<<root->data<<" ";
        q.pop();
        
        for(auto child: root->children){
            childq.push(child);
        }
        
        if(q.size() == 0){
            swap(q, childq);
            cout<<"\n";
        }
    }
}


/*Other Approaches*/

// Using NULL
void levelOrderLineWise2(Node * root){
    // Mantra: Remove Print Add
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    O(N) Time
    O(N) Space
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

// Using Count
void levelOrderLineWise3(Node * root){
    // Mantra Remains Same: Remove Print Add
    
    queue<Node *> q;
    q.push(root);

    O(N) Time
    O(N) space
    while(q.size() > 0){
       int size = q.size();
       while(size-- > 0){
           root = q.front(); q.pop();
           cout<<root->data<<" ";
           for(auto child:root->children){
               q.push(child);
           }
       }
       cout<<"\n";
    }
}

// Using Pairs
void levelOrderLineWise4(Node * root){

    queue<pair<Node *, int>> q;
    int level = 1;
    q.push({root,level});
    while(q.size() > 0){
        
        pair<Node *, int> temp = q.front(); q.pop();
        
        if(temp.second > level){
            cout<<"\n";
            level = temp.second;
        }
        cout<<temp.first->data<<" ";
        for(auto child : temp.first->children){
            q.push({child, level+1});        
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
    levelOrderLineWise(root);
    
    return 0;
}