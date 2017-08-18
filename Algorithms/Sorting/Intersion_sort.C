#include<stdio.h>
#define n 10
int main(){
	int a[n],key,i,j,temp;  // variable decleration
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  // taking unsored input
	for(j=1;j<n;j++){       // insertion sort begins
	key=a[j];               //intialization of key element
	i=j-1;
	while(i>=0&&a[i]>key){  // finding element less then key
	a[i+1]=a[i];            // making way for minimum element 
	i--;
	}
	a[i+1]=key;             // giving elemnet its right place, bend the knee or drcarys 
	}
	for(i=0;i<n;i++)        // just another printing function
	    printf("%d\t",a[i]);
	return 0;
}
