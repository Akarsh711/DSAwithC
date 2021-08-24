// Level Order Traversal using Queue
// After every node there is NULL

#include <iostream>
#include <queue>
using namespace std;

struct Node{
        struct Node *left;
        struct Node *right;
        int data;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
    };

// struct Node * createNode(int item){
//     struct Node *n = (struct Node *)malloc(sizeof(struct Node));
//     n->data = item;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
// }

// insert
void insert(struct Node *root, struct Node *item){
    if(item->data <= root->data){
        if(root->left == NULL)
            root->left = item;
        else
            insert(root->left, item);
    }
    else{
        if(root->right == NULL)
            root->right = item;
        else
            insert(root->right, item);
    }
}



// left->root->right
void inOrder(struct Node *root){
    if(root){
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}


void levelOrderTraversal(struct Node *root){
    if(root==NULL){
        return;
    }

    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        struct Node *node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right); 
        }
        else if(!q.empty())
            q.push(NULL);
    }
}

int sumAtK(struct Node * root, int K){
    if(root==NULL){
        return -1;
    }

    queue<Node *>q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum = 0;
    while(!q.empty()){
        Node *node= q.front();
        q.pop();

        if(node!=NULL){
            if(level == K)
                sum += node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
/* TODO */
// Traversal, Search, Insert Using Loop 

/**
    1
  /   \
 2    3
/ \  /  \
4  5 6  7
**/
int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // cout<<root->data;
    // cout<<root->left->data;
    // cout<<root->right->data;

    // levelOrderTraversal(root);
    cout <<sumAtK(root, 1);
}

