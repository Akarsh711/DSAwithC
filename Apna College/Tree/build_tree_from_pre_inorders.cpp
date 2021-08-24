#include <iostream>

using namespace std;

// In this we gonna build tree from preorder and inorder
struct Node{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}	
};

int search(int inorder[], int start, int end, int curr){
	for(int i=start; i<=end; i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}

Node * buildtreefromPreOrder(int preorder[], int inorder[], int start, int end){
	static int idx = 0;

	if(start>end){
		return NULL;
	}

	int curr = preorder[idx];
	idx++;
	Node * node = new Node(curr);
	// !IMPORTANT!This below if should be after idx++ as when a node is leaf it should return, while
	// incrementing idx for next recursion!
	if(start == end){
		return node;
	}

	int pos = search(inorder, start, end, curr);
	node->left = buildtreefromPreOrder(preorder, inorder, start, pos-1);
	node->right = buildtreefromPreOrder(preorder, inorder, pos+1, end);
	
	return node;
}
/*
ALGO:
	int arr[] = {4,5,6,7,8,9}; //Sorted/Inorder
	int prearr[] = {6,4,5,8,7,9}; //Preorder
*/


void inorderPrint(Node *root){
	if(root == NULL){
		return;
	}
	inorderPrint(root->left);
	cout << root->data << " ";
	inorderPrint(root->right);
}

int main(){
	int preorder[] = {1,2,4,3,5};
	int inorder[] = {4,2,1,5,3};

	Node *root = buildtreefromPreOrder(preorder, inorder, 0, 4);
	inorderPrint(root);
	return 0;
}