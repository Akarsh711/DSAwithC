#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
	struct Node *left;
	struct Node *right;
	int data;
	Node(int val){
		left = NULL;
		right = NULL;
		data = val;
	}

};
// sum replacement
// take each node's child and sum it to current node


int sumReplacement(Node *root){
	if(!root) return 0;

	int val1 = sumReplacement(root->left);
	int val2 = sumReplacement(root->right); 
	root->data= val1+val2+root->data;
	return root->data;
}

void inOrder(Node *root){
	if(!root) return;
	inOrder(root->left);
	cout<<root->data<<endl;
	inOrder(root->right);
}
// 36
/**
    1
  /   \
 2    3
/ \  /  \
4  5 6  7
	/
	9
**/

int main(){

	struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(9);
    root->right->right = new Node(7);
    cout<<sumReplacement(root);
    cout<<endl;
    inOrder(root);
}