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


int height(Node * root){
	if(root==NULL) return 0;
	
	int lHeight = height(root->left);
	int rHeight = height(root->right);
	return max(lHeight, rHeight)+1;// +1 for adding current height
}


bool isBalanced(Node* root){
	// It's complexity is O(n^2)
	if(root==NULL) return true;

	if(isBalanced(root->left) == false)
		return false;

	if(isBalanced(root->right) == false)
		return false;

	int lh = height(root->left);
	int rh = height(root->right);

	if(abs(lh-rh)<=1)
		return true;
	else
		return false;
}

// optimized version
bool isBalanced2(Node *root , int *height){
	// It's complexity is N 
	// As cpp have return problems that's why we don't did if(abs(lh...)) in height().
	// Here if you look closely return converted into pointer
	if(root==NULL) return true;

	int lh =0, rh = 0;

	if(isBalanced2(root->left, &lh)== false)
		return false;
	if(isBalanced2(root->right, &rh)== false)
		return false;

	*height  = max(lh, rh) +1;
	if(abs(lh - rh) <= 1)
		return true;
	else
		return false;

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
    // root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    int height = 2;
    if(isBalanced2(root, &height))
    	cout<<"True";
    else
    	cout<<"False";
    cout<<isBalanced(root);
}