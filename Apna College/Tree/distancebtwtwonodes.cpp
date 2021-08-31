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


bool findPath(Node *root, int n, vector<int> &path){
	if(!root) return NULL;
	path.push_back(root->data); //
	if(root->data == n) return true;

	if(findPath(root->left, n, path)||findPath(root->right, n, path)) return true;

	path.pop_back();
	return false;

}

int lca(Node*root, int a, int b){
	vector<int> path1, path2;
	if(findPath(root, a, path1)==false||findPath(root, b, path2)==false) return -1;

	int pc =-1;
	int index;
	int size;
	// int s_path1 = path1.size();
	// int s_path2 = path2.size();
	for(int i=0; i<path1.size() && i<path2.size(); i++){
		if(path1[i]!=path2[i]){
			pc = path1[i-1];
			index = i-1;
			size = ((path1.size()-index)+(path2.size()-index))-2;
			break;
		}
		else if(!(i+1<path1.size()) || !(i+1<path2.size())){
		    index = i;
		    size = ((path1.size()-index)+(path2.size()-index))-2;
		}
	}
	// cout<<path1.size();
	return size;
}
/**
    1
  /   \
 2    3
/ \  /  \
4  5 6  7
	/
	9
   /
   99

	
   from 5(node) and 6(node) as space problem
   5           6
    \         /
    98       9
     \      /
     90    99s
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


    root->right->left->left->right = new Node(99);
    root->left->right->right = new Node(98);
    root->left->right->right->right = new Node (90);
    cout<<lca(root, 98,99	);
}