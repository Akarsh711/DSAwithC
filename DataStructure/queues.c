# include <stdio.h>
# include <conio.h>


/*  Program for Queue [Normal, Circular] */
// Array Implementation of Queue
struct Queue{
    int front, rear, size;
    unsigned capacity;
    int * array;
};

struct Queue * createQueue(unsigned capacity){
    struct Queue *queue = (struct Queue*)malloc( 
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity -1;

    queue->array = (int *)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isFull(struct Queue *queue){
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue){
    return (queue->size == 0);
}

void enQueue(struct Queue *queue, int item){
    if(isFull(queue))
        return;
    queue->rear = (queue->rear +1)%queue->capacity; //Ask yourself why we used this 
    queue->array[queue->rear] = item;
    queue->size = queue->size+1;
    printf("enqued to item %d\n", item);
}

void deQueue(struct Queue *queue){
    if(isEmpty(queue))
        return;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size -1;
    printf("denquing  item");

}

int main(){
    struct Queue *q;
    q = createQueue(10);
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    deQueue(q);
    printf("front and rear %d:, %d:", q->array[q->front], q->array[q->rear]);
}

