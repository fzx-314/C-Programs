/*Searching in O(root(n)) times algorithm */

#include<stdio.h>
#include<math.h>
#define min(a,b) ((a<b)?(a):(b))
#define max 10
int jump_search(int a[],int m,int x){
	int step=sqrt(m);
	int prev=0;
	if(a[min(step,m)-1]<x){
		prev=step;
		step+=sqrt(m);
		if(prev>m)
			return -1;
	}
	while(a[prev]<x){
		prev++;
		if(prev==min(step,m))
			return -1;
	}
	if(a[prev]==x)
		return prev;
}
int main(void){
	int a[10],i,ans,x;
	for(i=0;i<max;scanf("%d",&a[i++]));
	scanf("%d",&x);
	ans=jump_search(a,max,x);
	printf("\n%d is at index %d\n",x,ans);
}
