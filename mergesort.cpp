#include <iostream>

using namespace std;


void merge(int arr[], int l, int mid, int r){
	// hamne banane do array sabse pahle 
	// kitne size ke bhai vo banege l->mid, mid+1->r tak ke size ke
	int size_of_first_arr = l+mid;
	int size_of_second_arr = (mid+1)+r;
	// int arr[size_of_first_arr];
	// int arr[size_of_second_arr]

	cout << "size of first and second array respectively" << size_of_first_arr<<size_of_second_arr;
	return;
}

void mergeSort(int arr[], int l, int r){
	if(l>=r){
		return;
	}
	cout<<"i don't want nub";
	int mid = l+(r-1)/2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	merge(arr, l, mid, r);
	
}

int main(){
	int arr[] = {5,6,3,6,7,4,2,1};
	int size = sizeof(arr)/sizeof(size);
	cout << "Confs are as follows " <<endl;
	cout << "array size is " << size <<endl;

	mergeSort(arr, 0, size-1);
}