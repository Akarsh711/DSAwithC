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

int ma;

// O(n)
int func(Node * root){

	if(!root) return 0;
	
	int x = func(root->left);
	int y = func(root->right);
	ma = max(ma, x+y+1);
	return (max(x,y)+1);
}

int diameter(Node *root){
	ma = INT_MIN;
	int x = func(root);
	return ma;
}

// Also can be done as
// Declaring dia global and initializing h =-1
// int treeDiameter(Node *root, int h){
// 	if(root == NULL) return h;
// 	h++;
// 	int lh = treeDiameter(root->left, h);
// 	int rh = treeDiameter(root->right, h);

// 	dia = max((lh+rh)+1, dia);
// 	// cout<<dia<<endl;
// 	return max(lh, rh)

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

    cout<<diameter(root);

}