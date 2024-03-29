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

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node *child : node->children)
  {
    display(child);
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

Node * linearizeOptimized(Node * root){
    vector<Node *> curr;
    for(auto child:root->children){
        curr.push_back(linearizeOptimized(child));
    }
    // curr.pop_back();
    while(curr.size()> 1){
        Node *last = root->children.back();
        root->children.pop_back();
        curr.pop_back();
        Node * secondlast =  curr.back();
        secondlast->children.push_back(last);
    }
    return root;
}

Node * linearizeOptimized2(Node * root){
    if(root->children.size()==0)return root;
    
    Node * prev = root->children.back();
    Node * tail = linearizeOptimized2(prev);

    // Node * lkt = linearizeOptimized2(root->children[root->children.size()-1]);
    while(root->children.size()>1){
        root->children.pop_back();
        Node * secondtail = linearizeOptimized2(root->children.back()); 
        secondtail->children.push_back(prev);
        prev = root->children.back();
        
        //// root->children.pop_back();
        
        // Node * last = root->children.back();
        // root->children.pop_back();
        // Node * sl = root->children[root->children.size()-1];
        // Node *slt = linearizeOptimized2(sl);
        // slt->children.push_back(last);
    }
    return tail;
    // return lkt;
}

int main()
{
    // Generic Tree Constructor
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root = constructor(arr, 21);
    cout<<"\n";
    Node * nn = linearizeOptimized2(root);


    // taking while(root != NULL) will give you error of index out of bound because in case of last child root->children[0] is not defined
    Display(root);
    // while(root->children.size()>0){
    //     cout<<root->data<<" ";
    //     root = root->children[0];
    // }
    // cout<<root->data;
    return 0;
}