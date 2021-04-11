// implementing queue in cpp
#include <iostream>

using namespace std;

// int isOverflow(int &rear){
//     if(rear == size)
//         return 1;
//     return 0;
// }
// void isUnderflow(int arr){}


void enQueue(int arr[], int val, int &front, int &rear, int size){
    if(rear == size){
        cout << "Over Flow" <<endl;
        return;
        }
    arr[rear] = val;
    rear++;
}

void deQueue(int arr[], int &front, int &rear, int size){
    if(front == rear){
        cout << "Under Flow" <<endl;
        return;
        }
    cout<<arr[front];
    front = front+1%size;
}


void enQueueD(int arr[], int val, int &front, int &rear, int &size, int capacity){
    if(size ==capacity){
        cout << "Over Flow" <<endl;
        return;
        }
    arr[rear] = val;
    rear = rear+1%capacity;
    size ++;
}

void deQueueD(int arr[], int &front, int &rear, int &size, int capacity){
    if(size == 0){
        cout << "Under Flow" <<endl;
        return;
        } 
    cout<<arr[front];
    front = front+1%capacity;
    size --;
}



int main(){
    int capacity = 3;
    int size = 0;
    int front=0;
    int rear = 0;
    int arr[capacity]; 
    // enQueue(arr, 1, front, rear, size);
    // enQueue(arr, 2, front, rear, size);
    // enQueue(arr, 3, front, rear, size);
    // enQueue(arr, 4, front, rear, size);
    // deQueue(arr, front, rear, size);
    // deQueue(arr, front, rear, size);
    // deQueue(arr, front, rear, size);
    // deQueue(arr, front, rear, size);


    enQueueD(arr, 9, front, rear, size, capacity);
    enQueueD(arr, 8, front, rear, size, capacity);
    enQueueD(arr, 7, front, rear, size, capacity);

    enQueueD(arr, 99, front, rear, size, capacity);
    deQueueD(arr, front, rear, size, capacity);
    enQueueD(arr, 6, front, rear, size, capacity);
    deQueueD(arr, front, rear, size, capacity);
    deQueueD(arr, front, rear, size, capacity);
    deQueueD(arr, front, rear, size, capacity);
    deQueueD(arr, front, rear, size, capacity);
    deQueueD(arr, front, rear, size, capacity);

}

