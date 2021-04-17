// Doubly Linked List
/*

Advantages over singly linked list 
1) A DLL can be traversed in both forward and backward direction. 
2) The delete operation in DLL is more efficient if pointer to the node to be deleted is given. 
3) We can quickly insert a new node before a given node. 
In singly linked list, to delete a node, pointer to the previous node is needed. To get this previous node, sometimes the list is traversed. In DLL, we can get the previous node using previous pointer. 
 
Disadvantages over singly linked list 
1) Every node of DLL Require extra space for an previous pointer. It is possible to implement DLL with single pointer though (See this and this). 
2) All operations require an extra pointer previous to be maintained. For example, in insertion, we need to modify previous pointers together with next pointers. For example in following functions for insertions at different positions, we need 1 or 2 extra steps to set previous pointer.
Insertion 
A node can be added in four ways 
1) At the front of the DLL 
2) After a given node. 
3) At the end of the DLL 
4) Before a given node.
*/
#include<iostream>

using namespace std;

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node *createNode(int data){
	struct Node *n = (struct Node *)malloc(sizeof(Node *));
	n->data = data;
	n->prev= NULL;
	n->next= NULL;
	return n;
}

struct Node *insert(struct Node *root, struct Node *n){
	while(root->next!=NULL){
		root = root->next;
	}
	n->prev = root;
	root->next=n;
	return n;
}

void printList(struct Node *root){
	while(root!=NULL){
		cout<<root->data;
		root = root->next;
	}
}

void reverseTraversal(struct Node *last){
	while(last !=NULL){
		cout <<last->data;
		last = last->prev;
	}
}

void insertAtAnyPos(struct Node *root, int after, struct Node *n){
	while(root->data!=after){
		root = root->next;
	}
	n->next = root->next;
	n->prev = root;
	root->next = n;
	n->next->prev=n;	
}

int main(){
	struct Node *root = createNode(1);
	struct Node *last = insert(root, createNode(2));
	insertAtAnyPos(root, 1, createNode(9));
	printList(root);
	cout <<endl;
	reverseTraversal(last);
	// cout<<"kya aya"<<root->next->data;
}