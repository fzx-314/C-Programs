/* An log n search algorithm for some special arrays */

#include<stdio.h>
#define max 10
#define min(a,b) ((a<b)?(a):(b))
int expo(int a[],int n,int x){
    if (a[0]==x)
        return 0;
    int i = 1;
    while (i < n && a[i] <= x)
        i = i*2;
    return binsearch(a, i/2, min(i, n), x);
}
int binsearch(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binsearch(a, l, mid-1, x);
        return binsearch(a, mid+1, r, x);
    }
    return -1;
}
int main(void){
	int a[10],i,ans,x;
	for(i=0;i<max;scanf("%d",&a[i++]));
	scanf("%d",&x);
	ans=expo(a,max,x);
	printf("\n%d is at index %d\n",x,ans+1);
}
