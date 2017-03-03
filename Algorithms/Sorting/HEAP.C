#include<stdio.h>
int a[10]={10,23,11,22,87,16,54,32,67,93};
int heap_size=9;
int length;
void heapify(int a[],int i)
{
	int l,r,largest,temp;
	l=(2*i);
	r=(2*i+1);
	if((l<=heap_size)&&(a[l]>a[i]))
		largest=l;
	else
		largest=i;
	if((r<=heap_size)&&(a[r]>a[largest]))
		largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,largest);
	}
}
void build_heap(int a[])
{
	int i;
	length=heap_size;
	i=(length/2);
	for(;i>0;i--)
	{
		heapify(a,i);
	}
}
void heap_sort(int a[])
{
	int i,temp;
	length=heap_size;
	i=length;
	for(;i>=2;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		heap_size=heap_size-1;
		heapify(a,1);
	}
}
void main()
{
	int i;
	clrscr();
	build_heap(a);
	heap_sort(a);
	for(i=1;i<10;i++)
		printf("%d\t",a[i]);
	getch();
}