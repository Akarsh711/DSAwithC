#include<iostream>
using namespace std;
#include "heap.h"
/* MIN HEAP */

// Utility Funcitions

class MinHeap{
public:
    int size=0,capacity = 9;
    int arr[9];
    // arr = {4, 5,6 ,6}

    int getLeftChildIndex(int parent){return parent*2+1;}
    int getRightChildIndex(int parent){return parent*2+2;}
    int getParentIndex(int childIndex){return (childIndex -1)/2;}

    bool isLeftChild(int index){return getLeftChildIndex(index)<size;}
    bool isRightChild(int index){return getRightChildIndex(index)<size;}
    bool isParent(int index){return getParentIndex(index)>=0;}

    int leftChild(int index){return arr[getLeftChildIndex(index)];}
    int rightChild(int index){return arr[getRightChildIndex(index)];}
    int parent(int index){return arr[getParentIndex(index)];}
    // void ensureExtraCapacity(){
    //     if(size==capacity){
    //         // TODO
    //         // increase size of array
    //         capacity *=2;
    //     }
    // }

    void eSwap(int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    void printHeap(){
        for(int i=0; i<size; i++){
            cout<< " "<< arr[i];
        }
        cout<<endl;
    }
    // primary functions
 


    int peek(){
        if(size==0)cout<<"size is 0";
        return arr[0];
    }

    int pool(){
        if(size==0)cout<<"size is 0";
        int item = arr[0];
        arr[0] = arr[size-1];//putting last element as front
        size--;
        heapifyDown();
        return item;
    }

    void add(int item){
        // ensureExtraCapacity();
        arr[size] = item;
        size++;
        heapifyUp();
    }

    // This two functions heapifyUp and heapifyDown are work together and sort the tree 
    void heapifyUp(){
        // first add node at last;
        // second check if parent is greater 
            // if true
            // swap
            // keep parent's index
            // now repeat this till find parent smaller or 
        int index = size-1;
        while(isParent(index) && parent(index) > arr[index]){
            eSwap(getParentIndex(index) , index);
            index = getParentIndex(index);
        }
    }

    void heapifyDown(){
        int index = 0;
        while(isLeftChild(index)){
            int smaller_child_index = getLeftChildIndex(index);
            if(isRightChild(index) && rightChild(index)<leftChild(index)){
                smaller_child_index = getRightChildIndex(index);
            }

            if(arr[index]< arr[smaller_child_index])
                break;
            else
                eSwap(index, smaller_child_index);
            index = smaller_child_index;
        } 




        // Put last node in place of root or index 0
        // compare it's child and swap it smaller of child
        // do it till uski atama ko shanti ni mil jae
    }
};

// //////////////////////////////////

// class Utility{
// public:
//     int getLeftChildIndex(int index){return index*2 +1;}
//     int getRightChildIndex(int index){return index*2 +2;}
//     int getParentIndex(int index){return index/2 -1;}

//     bool hasLeftChild(int index){return getLeftChildIndex(index) >-1;}
//     bool hasRightChild(int index){return getRightChildIndex(index)> -1;}
//     bool hasParent(int index){return getParentIndex(index) >-1;}

//     int leftChild(int index){return arr[getRightChildIndex(index)];}
//     int rightChild(int index){return arr[getLeftChildIndex(index)];}

//     void eSwap(int index1, int index2){
//         int temp = arr[index1];
//         arr[index1] = index2;
//         arr[index2] = temp;
//     }

//     void cpacityUpdata(void);

// };

class MaxHeap{
public:
    int size=0, capacity=9;
    int arr[9];
    
    int getLeftChildIndex(int index){return index*2 +1;}
    int getRightChildIndex(int index){return index*2 +2;}
    int getParentIndex(int index){return (index-1)/2;}

    bool hasLeftChild(int index){return getLeftChildIndex(index) <size;}
    bool hasRightChild(int index){return getRightChildIndex(index)<size;}
    bool hasParent(int index){return getParentIndex(index) >=0;}

    int leftChild(int index){return arr[getLeftChildIndex(index)];}
    int rightChild(int index){return arr[getRightChildIndex(index)];}
    int parent(int index){return arr[getParentIndex(index)];}

    void eSwap(int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    void printHeap(){
        for(int i=0; i<7; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }



    void peek(){
        cout<<arr[0];
    }

    int pool(){
        if(size<0){
            return 0;
        }
        int val = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapifyDown();
        return val;
    }

    void add(int item){
        // capacity increase karo first of all
        // we should use vector to dynamically increase size
        cout<<item<<endl;
        arr[size]=item;
        size++;
        // cout<<size<<endl;
        heapifyUp();
    }


    // This one keeps sort the array or BT
    void heapifyUp(){ 
        // int p_index = getParentIndex(size-1);
        // int c_index = size-1;
        // while(hasParent(c_index) && arr[p_index] < arr[c_index]){
        //     eSwap(p_index , c_index);
        //     c_index = p_index;
        //     p_index = getParentIndex(c_index);
        // }    

        int index = size-1;
        while(hasParent(index) && parent(index) < arr[index]){
            eSwap(getParentIndex(index) , index);
            index = getParentIndex(index);
        }
    }

    
    void heapifyDown(){
        // int index = 0;

        // while(hasLeftChild(index)){
        //     int var = getLeftChildIndex(index);

        //     if(hasRightChild(index) && rightChild(index)>leftChild(index)){
        //         int var = getRightChildIndex(index);
        //     }

        //     if(arr[index] > arr[var]){
        //         return;
        //     }
        //     else{
        //         eSwap(index, var);
        //     }
        //     index = var;   
        // }

        int index = 0;
        while(hasLeftChild(index)){
            int smaller_child_index = getLeftChildIndex(index);
            if(hasRightChild(index) && rightChild(index)>leftChild(index)){
                smaller_child_index = getRightChildIndex(index);
            }
            if(arr[index] > arr[smaller_child_index])
                break;
            else
                eSwap(index, smaller_child_index);
            index = smaller_child_index;
        } 
    }

};

int main(){
 
    MaxHeap h;
    h.add(5);
    h.add(4);
    h.add(22);
    h.add(4);
    // h.printHeap();
    h.add(45);
    h.add(7);
    h.add(1);
    h.printHeap();

    // h.printHeap();
    for(int i=0; i<7; i++){
        cout<<h.pool()<<" ";
    }

}

