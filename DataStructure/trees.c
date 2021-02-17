#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * right;
	struct Node * left;
};

struct Node * createNode(int item){
	struct Node* n = (struct Node *)malloc(sizeof(struct Node *));
	n->data = item;
	n->left = 0;
	n->right = 0;
	return n;
}

void preOrderTraverse(struct Node * root){
	if(root){
		printf("%d", root->data);
		preOrderTraverse(root->left);
		preOrderTraverse(root->right);
	}
}

// void postOrderTreverse(struct Node * root){

// }

// void inOrderTreverse(struct Node * root){

// }

// void levelOrderTreverse(struct Node * root){

// }

// void insert(struct Node * root, int item){
// 	struct Node * par = root;
// 	struct Node * n = createNode(item);

// 	while(par != NULL){
// 		if(item < par->data){
// 			if(par->left == NULL)
// 				par->left = n;
// 			par = par->left;
// 			printf("%d", par);
// 		}
// 		else{
// 			return
// 			if(par->right == NULL)
// 				par->right = n;
// 			par = par->right;
// 			printf("%d", par);
// 		}
// 	}
// }

void insert(struct Node *root, int item){
	struct Node *par = root;
	struct Node *newNode = createNode(item);
	if(root == NULL){
		root = newNode;
		return;
	}
	while(par!=NULL){
		if(par->data > item){
			if(par->left==NULL)
				par->left = newNode;
			par = par->left;
		}
		else if(par->data < item){
			if(par->right==NULL)
				par->right = newNode;
			par = par->right;
		}	
	}
}

int main(){
	struct Node *root = createNode(5);
	// second level
	root->left = createNode(4);
	root->right = createNode(6);
	// 3rd level
	root->left->left = createNode(3);
	root->right->right = createNode(7);
	insert(root, 8);

	// let's traverse now
	preOrderTraverse(root);
}