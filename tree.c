# include <stdio.h>
# include <conio.h>
// # include <iostream>
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

void printTreeRecursively(struct Node * root){
    if(root){
        printTreeRecursively(root->left); //IN OOPS IT WILL LOOK LIKE THIS :- left.printTreeRecursively
        printf("%d",root->data);
        printTreeRecursively(root->right);
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

// struct Node* insertAnotherWay(struct Node* root, int key)
// {
//     if (root == nullptr) {
//         return newNode(key);
//     }
//     if (key < root->data) {
//         root->left = insertAnotherWay(root->left, key);
//     }
//     else {
//         root->right = insertAnotherWay(root->right, key);
//     }
 
//     return root;
// }

int main(){
    struct Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    struct Node *item = createNode(1);
    insert(root, item);
    printTreeRecursively(root);
    printf("------------------");
    inOrder(root);
    search(root, 2);
}