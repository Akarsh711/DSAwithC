#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

class MinHeap{
    public:
    int capacity;
    int *heap;
    MinHeap(int c){
        capacity = c;
        heap = new int[c];
    }
    
    // int capacity =4;
    int size = -1;
    // int heap[4];

    int findParent(int idx){return (idx-1)/2;}
    int findLeftChild(int idx){return(idx*2)+1;}
    int findRightChild(int idx){return (idx*2)+2;}
    
    // put last element to first
    int peek(){
        if(size == 0){
            return -1;
        }
        return heap[0];
    }

    int poll(){
        int item = heap[0];
        // heap[0] = heap[size];
        // size--;
        heapifyDown();
        return item;
    }

    void add(int val){
        size++;
        if(size == capacity){
            cout<<"Warning! Capacity Full";
        }
        heap[size] = val;
        heapifyUp();
    }

    void heapifyDown(){
        heap[0]=heap[size];
        heap[size]=INT_MAX;
        int root = 0;
        int leftchild = findLeftChild(0);
        int rightchild = findRightChild(0);

        while(heap[leftchild]<heap[root] || heap[rightchild]<heap[root] && (heap[leftchild] !=INT_MAX || heap[rightchild]!=INT_MAX)){

            if(heap[leftchild]<heap[rightchild] && heap[leftchild]<heap[root]){
                int temp = heap[leftchild];
                heap[leftchild] = heap[root];
                heap[root] = temp;
                root = leftchild;
            }

            if(heap[rightchild]<heap[root]){
                int temp = heap[rightchild];
                heap[rightchild] = heap[root];
                heap[root] = temp;
                root = rightchild;
            }

            leftchild = findLeftChild(root);
            rightchild = findRightChild(root);
        }
        // heap[size]=NULL;
        size--; 
    }
    
    // insert new one to top
    void heapifyUp(){
        int val = heap[size];
        // heap[size+1] = val;
        if(size == 0)
            return;
        int parentidx = findParent(size);
        // int parentidx = 0;
        int childidx = size;
        // cout<<parentidx;
        while(heap[parentidx]>val){
            // swap;
            // cout<<"working";
            heap[childidx] = heap[parentidx];
            heap[parentidx] = val;
            childidx = parentidx;
            parentidx = findParent(childidx);
        }
        // size++;
    }

    // void printHeap(){
    //     for(auto i: heap){
    //         cout<<i<<" ";
    //     }
    // }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinHeap mh(6);
    mh.add(7);
    mh.add(10);
    mh.add(4);
    mh.add(3);
    mh.add(20);
    mh.add(15);
    mh.poll();
    mh.poll();
    cout<<mh.poll();

    // MinHeap mh;
    // mh.add(3);
    // mh.add(4);
    // mh.add(2);
    // mh.add(1);
    // cout<<mh.poll();
    // cout<<mh.poll();
    // cout<<mh.poll();
    // cout<<mh.poll();

    // mh.add(5);
    // // cout<<mh.poll();
    // cout<<endl;


    // mh.add(0);
    // mh.add(9);
    // mh.add(2); mh.printHeap();
    // cout<<mh.poll();
    // cout<<mh.poll();
    // cout<<mh.poll();
    // cout<<mh.poll();
    // cout<<endl;
    // mh.printHeap();
    return 0;
}