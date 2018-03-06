/*
  Describe a O(nlogn)-time algorithm that,given a set S of n integers and another integer x, 
  determines whether or not there exist two elements in S whoes sum is exactly x.
  */
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
int main(void) {
	int a[10],i,x,j;
	for(i=0;i<10;i++)               // Getting Input
	{
	    printf("Enter Element number %d:",i+1);
	    scanf("%d",&a[i]);
	}
	merge_sort(a,0,9);          // Calling Merge sort
    printf("\nEnter Number you want to find sum as:");
    scanf("%d",&x);
    i=0;
    j=9;
    while(i<j)      // Linear scan of array which require order O(n) 
    {
        if((a[i]+a[j])==x)  // Maintaing two pointers i & j one points to start and other to end of array
        {
            printf("Element exist whoes sum is %d, Index of number is %d,%d\n",x,(i+1),(j+1));
            break;
        }
        else if((a[i]+a[j])<x) //if sum is less then number then increase i
            i++;
        else                // is sum is greater than number decrease j
            j++;
    }
	return 0;
}
