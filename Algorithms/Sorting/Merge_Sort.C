#include <stdio.h>
void merge(int a[],int p,int q,int r)
{
	int n1=q-p+1,n2=r-q,i,j,k;			//Size of left and right sub part Check logic q-p+1
	int L[n1],R[n2];				//auxilary array
	for(i=0;i<n1;i++)
		L[i]=a[p+i];				//copying left subtree
	for(i=0;i<n2;i++)
		R[i]=a[q+1+i];				//copying righ subtree
	i=j=0;
	k=p;                            // k=p casue of bug here dont replace it
	while(i<n1&&j<n2)				// to check if one of partition is empty or not
	{
		if(L[i]<=R[j])
			a[k++]=L[i++];			//copying if left subtree has smallest element
		else
			a[k++]=R[j++];			//copying if right subtrr has smallest element
	}
	while(i<n1)						//if one if partiton is empty 
		a[k++]=L[i++];					
	while(j<n2)
		a[k++]=R[j++];
}
void merge_sort(int a[],int p,int r)
{
	int q;
	if(p<r)				// Mainating Pointers
	{
		q=(p+r)/2;         // Logic might be wrong in some case
		merge_sort(a,p,q);	//Creating left subtree
		merge_sort(a,q+1,r);//Creating Right Subtree
		merge(a,p,q,r);		// Conquering or merging Left & Right Sub tree
	}
}
void print(int a[]) //Just another printing function
{
	int i=0;
	for(;i<10;printf("%d\t",a[i++]));
}
int main()
{
	int a[10],i=0;			            //Intializing array
	for(;i<10;i++)						// Getting Input
	{
		printf("Enter %d element\n",i+1);
		scanf("%d",&a[i]);
	}
	printf("Given array is\n");
	print(a);
	merge_sort(a,0,9);// Recursive call to merge_sort function
	printf("\nSorted array is\n");
	print(a);
	return 0;
}
