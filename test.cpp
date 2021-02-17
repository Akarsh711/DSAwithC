#include <iostream>

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
}

int main(){
	int A[] = {5,47,3,46,4,67};
	std::swap(A[0] , A[0]);
	printArray(A, 6);
}