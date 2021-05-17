// It is nothing but sum of subtree with node at each pos.
// It's complexity is O(n)
#include<iostream>

using namespace std;
struct Node{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

int sumReplacement(struct Node* root){
	if(root==NULL) return 0;

	root->data += sumReplacement(root->left);
	root->data += sumReplacement(root->right);
	return root->data;
}

// Another approach of the same thing 
void sumReplacement2(Node * root){
	if(root==NULL) return;
	sumReplacement2(root->left);
	sumReplacement2(root->right);

	if(root->left!=NULL)
		root->data += root->left->data;
	
	if(root->right!=NULL)
		root->data += root->right->data;

}
void preOrder(Node * root){
	if(root==NULL) return;

	cout<< root->data<< " ";
	preOrder(root->left);
	preOrder(root->right);
}
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
    preOrder(root);
    // cout<<sumReplacement(root)<<"\n";
    sumReplacement2(root);
    preOrder(root);
}