# include<stdio.h>
# include<conio.h>

struct node{
	int data;
	struct node *next;
};

struct node *START = NULL;
// A function to create Nodes Dynamically
struct node* createNode()
{
	struct node *n;
	n = (struct node*)malloc(sizeof(struct node)); /*malloc(sizeof(struct node)); This will give you void size pointer of memory 
										so we need to type cast it to struct like (struct node *)malloc(size) size can be explicit acc. to you*/
	return(n);
} 

void insertNode()
{
	struct node *temp;
	temp = createNode();

	printf("Enter a Number");
	scanf("%d", &temp->data);
	temp->next = NULL;

	if(START==NULL){
		START = temp;
	}
	else{
		struct node *t = START;
		while(t->next){
			// printf(t->next);
			t = t->next;
		}
		t->next = temp;
	}
}

void insertAtAnyPoint(int data){
	struct node t;
	struct node *temp = createNode();
	t = START;
	while(t.next){
		printf("%d \n", 't.data');
		t = t.next;
	}

}
void printList(){
	struct node *t = START;
	printf("here's your list sir !%d", START->data);
	while(t->next){
		printf("%d \n", t->data);
		t = t->next;
	}
}

/* COPY of Program -----------*/
