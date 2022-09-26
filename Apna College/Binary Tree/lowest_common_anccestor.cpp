#include <iostream>
using namespace std;
// Take two node and check where they meet(common anncesstor)
// We gonna take two paths and compare the decendent
// Means we gonna find the path for two of our nodes and then we compare the path
// of both and look where the paths gets change

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

bool getPath(Node *root, int key, vector<int> &path){
	if(root==NULL)
		return false; 
	
	path.push_back(root->data);//It will spit a nice bug if you put this in backtrack

	if(root->data == key) return true;

	if(getPath(root->left, key, path) || getPath(root->right, key, path)) return true;

	path.pop_back();

	return false;
}


int lCA(Node *root, int a, int b){
	vector<int> path1, path2;

	if(!getPath(root ,n1, path1) || !getPath(root, n2, path2))
		return -1;

	int pc; //path change

	for(pc=0; pc<path1.size() && pc<path2.size(); pc++){
		if(path1[pc]!=path2[pc])
			break;
	}

	return path1[pc-1];
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