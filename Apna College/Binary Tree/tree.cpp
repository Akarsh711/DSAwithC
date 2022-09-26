# include <stdio.h>
# include <conio.h>
# include <iostream>
# include <queue>

using namespace std;
struct Node{
        struct Node *left;
        struct Node *right;
        int data;
    };

struct Node * createNode(int item){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = item;
    n->left = NULL;
    n->right = NULL;
    return n;
}

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


// root->left->right
void preOrder(struct Node *root){
    if(root){
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
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

// left->right->root
void postOrder(struct Node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

// search
void search(struct Node *root, int item){
    if(root){
        if(root->data == item){
            printf("value find");
            return; 
        }
        search(root->left, item);
        search(root->right, item);
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
            printf("%d",node->data);
            if(node->left)
                q.push(node->left);
            else
                q.push(node->right); 
        }
        else if(!q.empty())
            q.push(NULL);
    }
}

/* TODO */
// Traversal, Search, Insert Using Loop 


int main(){
    struct Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    struct Node *item = createNode(3);
    insert(root, item);
    printf("------------------");
    inOrder(root);
    search(root, 2);
    levelOrderTraversal(root);
}

