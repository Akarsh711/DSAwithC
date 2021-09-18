#include <iostream>

using namespace std;

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

void merge(int arr[], int l, int mid, int r){

	int left = mid-l+1;
	int right = r-mid;

	int l_arr[left], r_arr[right];

	// copy element for left and right array
	int i,j,k;
	// for(int i=l; i<=mid; i++){
	// 	l_arr[i] = arr[i];
	// }
	// for(int j=mid+1; j<=r; j++){
	// 	r_arr[j] = arr[j]; //that suck while assignment as you need to consider 0th index or subarray but you're taking mid+1
	// }

	for (int i = 0; i < left; i++)
        l_arr[i] = arr[l + i];
    for (int j = 0; j < right; j++)
        r_arr[j] = arr[mid + 1 + j];

    // Compare the both l_arr and r_arr array and put small one in main arr
    i = j = 0;
    k=l;
    
    while(i<left && j<right){
    	if(l_arr[i] <= r_arr[j]){
    		arr[k] = l_arr[i];
    		i++;
    	}
    	else{
    		arr[k] = r_arr[j];
    		j++;
    	}
    	k++;
    }

    // Now put element left in any of both array in arr as l and r array can be uneven
    while(i<left){
    	arr[k] = l_arr[i];
    	i++;
    	k++;
    }
    // Either one of the while will run because one of them have been already empty 
    while(j<right){
    	arr[k] = r_arr[j];
    	j++;
    	k++;
    }

	printArray(l_arr, sizeof(l_arr)/sizeof(int));
	printArray(r_arr, sizeof(r_arr)/sizeof(int));
	cout << "endl" << endl;
}

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =(l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 
int main()
{
    int arr[] = {12, 11, 14,56};
    int arr_size = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, arr_size - 1);
    cout << "The Resultant Array:" << endl;
    printArray(arr, sizeof(arr)/sizeof(int));
}