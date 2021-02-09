#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * createNode(int data){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// LOOPY FUNCITONS
void traverseLoop(struct Node *start_node){
    while(start_node){
        printf("Loop Here%d", start_node->data);
        start_node = start_node->next;
    }
}

void insertLoop(struct Node *start_node, int data){
    struct Node *temp = start_node;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = createNode(data);
}

// RECURSIVE FUNCTIONS
void traverse(struct Node *start_node){
    if(start_node){ //Putting start_node->data give me segementation fault!! [RESEARCHABLE THING!]
        printf("%d",start_node->data);
        traverse(start_node->next);
    }
}

void insert(struct Node * start_node, int data){
    if(start_node->next){
        insert(start_node->next, data);
    }
    else{
        start_node->next = createNode(data);
    }
}

void search(struct Node* start_node, int to_search){
    if(start_node->data == to_search){
        printf("\nValue find in list");
    }
    else{
        search(start_node->next, to_search);
    }
}

int main(){
    struct Node *start_node = createNode(3);
    start_node->next = createNode(6);
    start_node->next->next = createNode(9);
    insert(start_node, 10);
    insertLoop(start_node, 11);
    
    traverse(start_node);
    search(start_node, 9);
    traverseLoop(start_node);

    printf("\ntest");
}
