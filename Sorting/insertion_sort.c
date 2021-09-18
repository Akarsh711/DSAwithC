# include <stdio.h>
# include <conio.h>

int main(){
	int arr[] = {4,5,3,2,1};
	int temp;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i = 1; i <= arr_size; i++)
	{
		int n = arr[i];
		int p = i-1;
		
		while(p>=0 && n < arr[p])
		{
			arr[p+1] = arr[p];
			p = p-1;
		}	
		arr[p+1] = n;
	}

	for(i = 0; i < arr_size; i++)
	{
		printf("%d", arr[i]);
	}
}