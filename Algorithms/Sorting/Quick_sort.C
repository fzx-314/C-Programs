#include <stdio.h>
void quick_sort(int a[], int x, int y)
{
   if(x<y)
   {
		int i=x, j=y, p, temp, k;
		p= a[j];
		while(i<j)
		{
			if(a[i]>p)
			{
				swap(&a[i], &a[j-1]);
				swap(&a[j], &a[j-1]);
				--j;
			}
			else
				i++;
		}
		//printf("\n");
		quick_sort(a, x ,j-1);
		quick_sort(a, j+1, y);
	}
}
void swap(int *a, int *b)
{
	int t;
	t= *a;
	*a= *b;
	*b= t;
}
int main()
{
	int k, a[10];
	printf("Enter 10 elements to sort:");
	for(k=0;k<10;k++)
	{
		scanf("%d",&a[k]);
	}
	printf("\n\n");
	quick_sort(a, 0, 9);
	printf("\n\n");
	for(k=0; k<10; k++)
	{
		printf("\t%d", a[k]);
	}
	return 0;
}
