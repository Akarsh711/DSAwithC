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

void printTree(struct Node *root){
    struct Node *temp = root;
    while(temp->data){
        printf("%d", temp->data);
        temp = temp->left;
        if(temp->left == NULL){
            return; 
            }
    }
    printf("test");
    while(temp->data){
        printf("%d", temp->data);
        temp = temp->right;
        if(temp->right == NULL)
            return;
    }

}

void printTreeRecursively(struct Node * root){
    if(root){
        printTreeRecursively(root->left);
        printf("%d",root->data);
        printTreeRecursively(root->right);
    }
}


int main(){
    struct Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    printTreeRecursively(root);



}