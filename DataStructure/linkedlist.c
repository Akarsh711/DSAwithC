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

struct Node * prepend(struct Node * start_node, int data){
    /* TODO: Add a Check if list have only one node or none*/
    struct Node * n = createNode(data);
    n->next = start_node;
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

void searchLoop(struct Node * start_node, int to_search){
    struct Node *temp = start_node;
    while(start_node){
        start_node = start_node->next; 
        if(start_node->data == to_search){
            printf("\nValue find by loop\n");
            return;
        }
    }
}

void insertAfterNodeLoop(struct Node *start_node, int data, int insert_after){
    struct Node *n = createNode(data);
    while(start_node){
        if(start_node->data == insert_after){
            n->next = start_node->next;
            start_node->next = n;
            printf("\nin fi");
            return; // You can also put this inefficient approach [start_node = start_node->next];
            
        }
        else{
            start_node = start_node->next;
        }
    }
}


// RECURSIVE FUNCTIONS -----------------
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
        printf("\nValue find in list\n");
    }
    else{
        search(start_node->next, to_search);
    }
}

void insertAfterNode(struct Node *start_node, int data, int after_which_node){
    /* TODO: Add Exception Handler or if else for [if node is empty or single or not present]*/
    struct Node * n = createNode(data);
    if(start_node->data == after_which_node){
        n->next = start_node->next;
        start_node->next = n;
    }
    else{
        insertAfterNode(start_node->next, data, after_which_node);
    }
}


int main(){
    struct Node *start_node = createNode(3);
    start_node->next = createNode(6);
    start_node->next->next = createNode(9);
    insert(start_node, 10);
    start_node = prepend(start_node, 1);
    insertLoop(start_node, 11);
    searchLoop(start_node, 11);
    search(start_node, 9);
    insertAfterNodeLoop(start_node, 66, 11);
    traverse(start_node);
    traverseLoop(start_node);
    printf("\ntest");
}
