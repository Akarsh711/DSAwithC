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



Node * lca(Node *root, int a, int b){
      if(!root) return NULL;
      if(root->data == a || root->data == b) return root;
      Node * lh = lca(root->left, a, b);
      Node * rh = lca(root->right, a, b);
      if(lh!=NULL && rh!=NULL)return root;
      if(lh==NULL && rh==NULL) return NULL;
    
      if(lh!=NULL)return lh;
      else return rh;
}

int findPath(Node *root, int val){
  if(!root)return -1;
  if(root->data == val) return 0;
  int lh = findPath(root->left, val);
  int rh = findPath(root->right, val);

  if(lh==-1 && rh==-1) return -1;
  if(lh!=-1) return lh+1;
  if(rh!=-1) return rh+1;
}

// int findPath(Node * root, int k, int distance){
//   if(!root) return -1;
//   if(root->data == k) return distance;
//   int lh = findPath(root->left, k, distance+1);
//   if(lh!=-1) return lh;
//   return findPath(root->right, k, distance+1);
// }

int findDist(Node*root, int a, int b){
  Node *l = lca(root, a, b);
  int lh = findPath(l, a);
  int rh = findPath(l, b);
//   cout<<lh+rh;
//   if(!lh || !rh) return -1;
   return lh+rh;
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
    root->left->right->right->right = new Node(90);
    // Node * who =lca(root, 98,99);
    // cout<<who->data;
    // cout<<caller(root, 98, 99);
    dsrs


















































































































    'l;gukeryd



































  

    uncaller(root, 7, 3);
}g