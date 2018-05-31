/* Find median of 2 sorted array in O(n) */
#include <stdio.h>
int median(int arr1[],int arr2[],int n){
	int i=0,j=0,c=0,m1,k;
	while(i<=n&&j<=n&c!=n){
		if(arr1[i]<=arr2[j]){
			i++;
			c++;
			k=i;
		}
		else{
			j++;
			c++;
			k=j;
		}
	}
	if(i==k)
		printf("%d",arr1[k-1]);
	else
		printf("%d",arr2[k-1]);
	return 0;
}
int main()
{
	int arr1[]={2,4,6,8,10,12,14};
	int arr2[]={1,3,5,7,9,11,13
	};
	median(arr1,arr2,7);
	return 0;
}
