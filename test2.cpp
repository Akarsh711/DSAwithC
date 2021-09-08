// #include <stdio.h>
#include<iostream>
using namespace std;
struct Node{

	int data;
	struct Node * next;
	Node(int val){
		data = val;
		next =  NULL;
	}
};

void bot(Node * root){
	Node * curr = root;
	curr->next = new Node(45);
	curr->next->next= new Node(99);
}

void printList(Node *root){
	if(!root) return;
	cout<<root->data<<endl;
	printList(root->next);
}

int main(){
	Node * root = new Node(1);
	root->next = new Node(2);
	root->next->next = new Node(3);
	bot(root);
	printList(root);
}