#include <stdio.h>
void merge(int a[],int p,int q,int r)
{
    int n1,n2,L[10],R[10],i,j,k;
    n1=q-p+1;
    n2=r-q;
    for(i=0;i<n1;i++)
        L[i]=a[p+i];
    for(i=0;i<n2;i++)
        R[i]=a[q+j];
    i=j=1;
    for(k=p;k<r;k++)
        if(L[i]<=R[j])
            A[k]=L[i++];
        else 
            A[k]=R[j++];
}
void merge_Sort(int a[],int p,int r)
{
    if(p<r)
    {
        q=[(p+r)/2];
        merge_Sort(a,p,q);
        merge_Sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main(void) {
	
		return 0;
}

