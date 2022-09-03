#include<stdio.h>
#include<stdlib.h>
// not working

struct Node{
	int data;
	struct Node *next;
};

struct Node* createNode(int val){
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	n->data = val;
	n->next = NULL;
	return n;
}

void display(struct Node *head){
	struct Node * temp = head;
	do{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	while(temp!=head);
	printf("\n");
}

void insertAtHead(struct Node *head, int val){
	struct Node *n = createNode(val);
	if(head == NULL){
		n->next = n;
		head = n;
		return;
	}
	// Case in which if there is already an list

	struct Node *temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	temp->next = n;
	n->next = head;
	head = n;

}

void push(struct Node *head, int val){
	if(head ==NULL){
		insertAtHead(head, val);
		return;
	}

	struct Node *temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	struct Node *n = createNode(val);
	n->next = head;
	temp->next = n;
}


int main(){
	struct Node *head = createNode(2);
	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	display(head);
}