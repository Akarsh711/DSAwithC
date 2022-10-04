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

vector<int> findNodeToRootPath(Node * root, int data){
    if(root->data == data){
        return {data};
    }

    for(auto child: root->children){
        vector<int> res = findNodeToRootPath(child, data);
        if(res.size()>0){
            res.insert(res.begin(), root->data);
            return res;
        }
    }
    return {};
}

void findDistanceBtwTwoNodes(Node * root, int n1, int n2){
    vector<int> res1 = findNodeToRootPath(root, n1);
    vector<int> res2 = findNodeToRootPath(root, n2);
    int i;
    for(i=0; i<res1.size() && i<res2.size(); i++){
        if(res1[i]!= res2[i]){
            i--;
            break;
        }
    }
    int cnt = res1.size()-1-i + res2.size()-1-i;
    cout<<cnt;
}


int main()
{
    // Generic Tree Constructor
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100};
    Node * root = constructor(arr, 21);
    findDistanceBtwTwoNodes(root, 110, 70);
    // for(auto i: res){
    //     cout<<i<<" ";
    // }
    return 0;
}