// I again say Gail Lakman Mcdowell Have Best Playlist of DSA @ HackerRank Channel
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node * createNode(int data){
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->data = data;
	n->next = 0;
	return n;
}

void printLinkedList(struct Node *n){
	while(n->data){
		printf("%d item\n", n->data);
		n = n->next;
	}
}

struct Node * prepend(struct Node *head, int item){
	struct Node *newHead = createNode(item);
	newHead->next = head;
	return newHead;
}

// void push(struct Node* head_ref, int new_data) 
// { 
//     /* 1. allocate node */
//     struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
//     /* 2. put in the data  */
//     new_node->data  = new_data; 
   
//     /* 3. Make next of new node as head */
//     new_node->next = (head_ref); 
   
//     /* 4. move the head to point to the new node */
//     (head_ref) = new_node; 
// } 
void append(struct Node *temp, int item){
	struct Node *second = createNode(item);
	while(temp->next != 0){
		temp = temp->next;
	}
	temp->next = second;
	
}

int main(){
	int item;
	struct Node *head = createNode(1); 
	append(head, 2);
	append(head, 3);
	head = prepend(head, 0);
	printLinkedList(head);
	getch();
}


/* LAZY VERSION */

// // A simple C program to introduce 
// // a linked list 
// #include <stdio.h> 
// #include <stdlib.h> 
  
// struct Node { 
//     int data; 
//     struct Node* next; 
// }; 
  
// // Program to create a simple linked 
// // list with 3 nodes 
// int main() 
// { 
//     struct Node* head = NULL; 
//     struct Node* second = NULL; 
//     struct Node* third = NULL; 
  
//     // allocate 3 nodes in the heap 
//     head = (struct Node*)malloc(sizeof(struct Node)); 
//     second = (struct Node*)malloc(sizeof(struct Node)); 
//     third = (struct Node*)malloc(sizeof(struct Node)); 
  
//     /* Three blocks have been allocated dynamically.  
//      We have pointers to these three blocks as head, 
//      second and third      
//        head           second           third 
//         |                |               | 
//         |                |               | 
//     +---+-----+     +----+----+     +----+----+ 
//     | #  | #  |     | #  | #  |     |  # |  # | 
//     +---+-----+     +----+----+     +----+----+ 
     
//    # represents any random value. 
//    Data is random because we haven’t assigned  
//    anything yet  */
  
//     head->data = 1; // assign data in first node 
//     head->next = second; // Link first node with 
//     // the second node 
  
//      data has been assigned to the data part of the first 
//      block (block pointed by the head). And next 
//      pointer of first block points to second.   
//      So they both are linked. 
  
//        head          second         third 
//         |              |              | 
//         |              |              | 
//     +---+---+     +----+----+     +-----+----+ 
//     | 1  | o----->| #  | #  |     |  #  | #  | 
//     +---+---+     +----+----+     +-----+----+     
  
  
//     // assign data to second node 
//     second->data = 2; 
  
//     // Link second node with the third node 
//     second->next = third; 
  
//     /* data has been assigned to the data part of the second 
//      block (block pointed by second). And next 
//      pointer of the second block points to the third  
//      block. So all three blocks are linked. 
    
//        head         second         third 
//         |             |             | 
//         |             |             | 
//     +---+---+     +---+---+     +----+----+ 
//     | 1  | o----->| 2 | o-----> |  # |  # | 
//     +---+---+     +---+---+     +----+----+      */
  
//     third->data = 3; // assign data to third node 
//     third->next = NULL; 
  
//     /* data has been assigned to data part of third 
//     block (block pointed by third). And next pointer 
//     of the third block is made NULL to indicate 
//     that the linked list is terminated here. 
  
//      We have the linked list ready.   
  
//            head     
//              | 
//              |  
//         +---+---+     +---+---+       +----+------+ 
//         | 1  | o----->|  2  | o-----> |  3 | NULL | 
//         +---+---+     +---+---+       +----+------+        
     
      
//     Note that only head is sufficient to represent  
//     the whole list.  We can traverse the complete  
//     list by following next pointers.    */
  
//     return 0; 
// } 