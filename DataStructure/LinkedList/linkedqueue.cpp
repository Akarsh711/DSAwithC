// QUEUE IMPLEMENTAION USING LINKED LIST
#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Q{
	struct Node *front, *rear;
};

struct Node *createNode(int n){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node *));
	node->data= n;
	node->next= NULL;
	return node;
}

struct Q *createQueue(){
	struct Q *q = new Q();
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void enQueue(struct Q* q, int n){
	if(q->rear == NULL){
		q->rear = q->front = createNode(n);
		return;
	}
	q->rear->next =createNode(n);
	q->rear = q->rear->next;
}

void deQueue(struct Q *q){
	struct Node *temp;
	if(q->front == NULL){
		printf("\n UNDERFLOW\n");
		return;
	}
	else{
		cout<<q->front->data;
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}

}
int main(){
	struct Q *q = createQueue();
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);
	deQueue(q);
	deQueue(q);
	deQueue(q);
	deQueue(q);
	deQueue(q);
	deQueue(q);
}