#include<stdio.h>



void printArray(int* A, int n){

for (int i = 0; i < n; i++)
{
    printf("%d", A[i]);
}


}

int main()
{

int A[] = {34,45,23,11,66,57,86,98,46};
int n = sizeof(A);

printArray(A, n);

}