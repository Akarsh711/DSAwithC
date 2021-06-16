
class MinHeap{
	public:
	int getLeftChildIndex(int);
    int getRightChildIndex(int);
    int getParentIndex(int);
    bool isLeftChild(int);
    bool isRightChild(int);
    bool isParent(int);

    int leftChild(int);
    int rightChild(int);
    int parent(int);

    void eSwap(int, int);
    void printHeap();

    void peek();
    int pool();
    void add(int);
    void heapifyUp();
    void heapifyDown();
};

class MaxHeap{
public:
	int getLeftChildIndex(int);
    int getRightChildIndex(int);
    int getParentIndex(int);
    bool hasLeftChild(int);
    bool hasRightChild(int);
    bool hasParent(int);

    int leftChild(int);
    int rightChild(int);
    int parent(int);

    void eSwap(int, int);
    void printHeap();

    void peek();
    int pool();
    void add(int);
    void heapifyUp();
    void heapifyDown();
};