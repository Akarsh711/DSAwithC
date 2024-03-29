// In this we we'll look at rightmost node in each level
// Kindoff same as level order but in this we didn't use null in queue
#include<iostream>
#include<queue>
#include<vector>

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

void myrightView(Node *root){
	queue<Node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node * curr = q.front();
		q.pop();
		if(curr != NULL){
			if(q.front() == NULL){
				cout<<curr->data;
			}
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
		else if(!q.empty()) q.push(NULL);
	}
}

void rightView(Node *root){
	// it's complexity is O(n)
	if (root==NULL) return;
	queue<Node *> q;
	q.push(root);
	
	while(!q.empty()){

		int n = q.size();
		for(int i=0; i<n; i++){
			Node *temp = q.front();
			q.pop();

			if(i==n-1) cout<< temp->data<< " ";
		
			if(temp->left!= NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
	}	
}
void leftView(Node *root){
	// it's complexity is O(n)
	if (root==NULL) return;

	queue<Node *> q;
	q.push(root);
	
	while(!q.empty()){
		int n = q.size();
		for(int i=1; i<=n; i++){
			Node *temp = q.front();
			q.pop();

			if(i==1) cout<< temp->data<< " ";
		
			if(temp->left!= NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
	}	
}
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
 	myrightView(root);
 	cout<<"\n";
 	rightView(root);
}