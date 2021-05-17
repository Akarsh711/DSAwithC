// Height and Diameter of Tree
// Diameter of Tree: Number of nodes in the longest path b/w any 2 leaves.

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

int calcHeight(Node * root){
	if(root==NULL) return 0;
	
	int lHeight = calcHeight(root->left);
	int rHeight = calcHeight(root->right);
	return max(lHeight, rHeight)+1;// +1 for adding current height
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

    cout<<calcHeight(root);

}