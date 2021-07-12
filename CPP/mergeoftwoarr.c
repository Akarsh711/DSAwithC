#include<stdio.h>
// using namespace std;

void merge(int a[], int b[], int size, int size2)
{
	int tempa[size];
	int tempb[size2];

	for(int i=0; i<size; i++){
		tempa[i] = a[i];
	}

	for(int i=0; i<size2; i++){
		tempb[i] = b[i];
	}

	int arr[size+size2];
	int i= 0,j= 0, k= 0;

	while(i<size && j<size2){
		if(tempa[i]<tempb[j]){
			arr[k] = tempa[i];
			i++;
		}
		else{
			arr[k] = tempb[i];
			j++;
		}
		k++;
	}

	while(i<size)
	{
		arr[i] = tempa[i];
		i++;
		k++;
	}

	while(j<size2)
	{
		arr[k] = tempb[j];
		j++;
		k++;
	}
	for(int i=0; i<size+size2; i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int size, size2;
	scanf("%d%d", &size, &size2);
	int a[size], b[size2];
	printf("Array is Declared");

	printf("Enter Elements for first array");
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
	}

	printf("Enter Elements for second array");
	for(int i=0; i<size2; i++){
		scanf("%d", &b[i]);
	}

	merge(a, b, size, size2);

}	