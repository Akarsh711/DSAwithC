#include <iostream>
#include <stack>

using namespace std;

void stackLookUp(stack<int> s){
	for(int i=0; i<=s.size(); i++){
		cout << s.top() <<endl;
		s.pop();
	}
}

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

void preorderLoopMine(struct Node *root){
	stack<Node *> s;
	struct Node *curr = root;
	while(curr!=NULL||s.empty() == false){

		// cout << curr->data;
		// if(curr->left!=NULL)
		// 	s.push(curr->left);
		// if(curr->right!=NULL)
		// 	s.push(curr->right);
		
		// curr= curr->left;
		while(curr!=NULL){
			cout << curr->data;
			if(curr->right != NULL)
				s.push(curr->right);
			curr=curr->left;
		}
		// Ab Suru hoga POP check ka process
		// s.pop();
		curr = s.top();
		s.pop();
		cout << "yahan aya"<<curr->data;
		// struct Node *test;
		// for(int i=0; i<=s.size(); i++){
		// 	test = s.top();
		// 	cout << "ye chala" <<endl;
		// 	s.pop();
		// }
		// loop lag jae dubara left ke liye to
	}

}


void traverse(struct Node *root){
	if(!root)
		return;
	traverse(root->left);
	cout << root->data;
	traverse(root->right);
}

void inOrderLoop(struct Node *root){
	stack<Node *> s;
	struct Node *curr = root;

	while(curr!= NULL || s.empty() == false){
		while(curr!=NULL){
			s.push(curr);
 			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->data << " ";
		curr = curr->right;

	}
}


void preOrder(struct Node *root){
	if(root==NULL)
		return;
	cout << root->data;
	preOrder(root->left);
	preOrder(root->right);
}

void preOrderLoop(struct Node *root){
	if(root == NULL)
		return;
	struct Node *curr =root;
	stack<Node *> s;
	s.push(curr);

	while(!s.empty()){
		curr = s.top();
		cout << curr->data << " ";
		s.pop();

		if(curr->right)
			s.push(curr->right);
		if(curr->left)
			s.push(curr->left);
	}
}

void postOrder(struct Node *root){
	stack<Node *> s;
	struct Node *curr= root;
	struct Node *prev = NULL;

	while(curr!=NULL || s.empty() == false){
		if(curr!=NULL){
			s.push(curr);
			curr = curr->left;
		}
		else{
			curr = s.top();
			if(curr->right==NULL || curr->right==prev){ //Second condition work for backtrack or else we stuck in infinite loop and first for recursion
				cout << curr->data << " ";
				s.pop();
				prev = curr; //Acting like a flag for visited node
				curr = NULL;
			}
			else{
				curr = curr->right;
			}	
		}
	}
}
// Home work Find for Preorder and Postorder

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
	// traverseLoop(root);
	// preorderLoop(root);
	preOrderLoop(root);
	cout <<endl;
	postOrder(root);
}
