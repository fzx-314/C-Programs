#include <stdio.h>
#include <math.h>
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void main()
{
    int arr[] = {9,1,15,13,11};
    int i;
    int n = sizeof(arr)/sizeof(arr[0]);
    clrscr();
    insertionSort(arr, n);
    for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
   getch();
}
