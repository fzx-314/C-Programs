/* A modified version of binary search algorithm for array consist elements having uniform distribution 
Best case time complexity = O(log log (n))
Worst case time complexity= O(n)
*/

#include<stdio.h>
#define max 10
int interpolation(int a[],int lo,int hi,int x){
	if(lo<=hi && a[lo]<x && a[hi]>x){
		int pos=(lo+(((x-a[lo])*(hi-lo))/(a[hi]-a[lo])));
		if(a[pos]==x)
			return pos;
		else if(a[pos]>x)
			interpolation(a,lo,pos-1,x);
		else 
			interpolation(a,pos+1,hi,x);
	}
	return -1;
}
int main(void){
	int a[10],i,ans,x;
	for(i=0;i<max;scanf("%d",&a[i++]));   // Input array 
	scanf("%d",&x);                       //Element to search
	ans=interpolation(a,0,max-1,x);
	printf("\n%d is at index %d\n",x,ans+1);
}
