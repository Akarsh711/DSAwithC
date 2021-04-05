#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node * createNode(int data){
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inOrderLoop(struct Node *root){
	// stack<Node *> s;
	// struct Node *curr = root;

	// while(curr!= NULL || s.empty() == false){
	// 	while(curr!=NULL){
	// 		s.push(curr);
 // 			curr = curr->left;
	// 	}
	// 	curr = s.top();
	// 	s.pop();
	// 	cout << curr->data << " ";
	// 	curr = curr->right;

	// }

	if(root == NULL)
		return;

	stack<Node *> s;
	s.push(root);

	while(s.empty()==false){
		struct Node *n = s.top();

		if(n->right)
			s.push(n->right);

		// struct Node *n = s.top();
		cout << n->data << " ";
		s.pop();

		if(n->left)
			s.push(n->left);
	}
}


int main(){
	struct Node *root = createNode(9);
	root->left = createNode(7);
	root->right = createNode(11);
	root->left->left = createNode(6);
	root->left->right = createNode(8);
	root->right->left = createNode(10);
	root->right->right = createNode(12);
	inOrderLoop(root);
	cout << endl;
	
}