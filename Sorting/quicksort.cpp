#include <iostream>
using namespace std;

void printArray(int, int); //Declaration here

// void hoarePartition(int arr[], int size){
// 	int i = 0;
// 	int j = size-1;
// 	int pivot = 5;

// 	while(true){ // When putting condition in here it's somehow not working gotta find why!
// 		while(arr[i] < pivot){
// 				i++;
// 		}
// 		while(arr[j] > pivot){
// 				j--;
// 		}	
// 		if(i >= j){
//             break;
//         }
// 		swap(arr[i], arr[j]);
// 	}
// }


int hoarePartition(int arr[], int l, int r){
	int i = l;
	int j = r;
	int mid = (l+r)/2;
	// int pivot = arr[l];
	int pivot = arr[mid];

	while(true){ // When putting condition in here it's somehow not working gotta find why!
		while(arr[i] < pivot){
				i++;
		}
		while(arr[j] > pivot){
				j--;
		}	
		if(i >= j){
            break;
        }
		swap(arr[i], arr[j]);
	}
	return j;
}

// void lumotoPartition()

void quickSort(int arr[], int l, int r){
	if(l<r){
		int pivot = hoarePartition(arr, l, r);
		quickSort(arr, l, pivot-1);
		quickSort(arr, pivot+1, r);
	}
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}


int main(){
	// int A[] = {5,47,3,46,4,67};
	int A[] = {7, 6, 5, 4, 3, 2,1};
	// int A[] = {7,-2, 4, 1, 3};
	int size = sizeof(A)/sizeof(int);
	printArray(A, size);
	// hoarePartition(A, size);
	quickSort(A, 0, size-1);
	printArray(A, size);
	
}