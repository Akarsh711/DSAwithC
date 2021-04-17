#include <stdio.h>
void disp(int ar[],int n)
{ int i;
  printf( " elements in array are:-\n");
  for(i=0;i<n; i++)
  {
    printf("%d ",ar[i]);
     printf("\n");

    }

}
void insertion( int arr[], int element, int size,int capacity,int index)
{
    if(size>=capacity ||index> capacity)
    {
        printf("in if");

    }
    else{
        printf("out ffom if");
        for(int i=size-1; i>=index;i-- )
        {
            arr[i+1]=arr[i];
        }
        arr[index]=element;
    }
}


int main()
{
    int a[50]={8,20,1,18,0};
    int size=5, element=25, index=54;
    disp(a,5);
    insertion(a,element,size,50,index);
    size+=1;

    printf("\ntest%d,%d\n", a[index], index);
    if( a[index]==element)
    {   printf("insertion is successful");
        disp(a,size);

    }



}
