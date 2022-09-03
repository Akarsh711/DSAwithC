#include <iostream>
using namespace std;

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


struct Node *buildTree(int arr[], int l, int r){
	if(l == r){
		return new Node(arr[l]);
	} 
	else if(l>r){
		return NULL;
	}

	int mid = (l+r)/2;
	struct Node *root = new Node(arr[mid]);
	
	root->left = buildTree(arr, l, mid-1);
	root->right = buildTree(arr, mid+1, r);
	return root;
}

void inOrder(struct Node *root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	cout <<root->data<< " ";
	inOrder(root->right);
}

int main(){
	// int arr[] = {1,2,4,5,6};
	int arr[] = {4,5,6,7,8,9};

	struct Node *root = new Node(2);
	// root->left = new Node(1);
	// root->right = new Node(3);
	root = buildTree(arr, 0, (sizeof(arr)/sizeof(int))-1);
	inOrder(root);
}