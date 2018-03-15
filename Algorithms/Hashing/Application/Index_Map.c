/* creating Number index to find whether a particular number is present or not in O(1) time 
#include <stdio.h>
#include <math.h>
#include <stdbool.h> 
#define MAX 1000
bool hash[MAX+1][2];
/*Making every element as false
positive elements would stored in [Index][0] and negative in [index][1]
*/
void intialize(){
	int i;
	for(i=0;i<=MAX;i++){
		hash[i][0]=0;
		hash[i][1]=0;
	}
}
// Creating Hash of Numbers
int insert(){
	int n,x,i;
	printf("\nHow many elements you wish to enter:");
	scanf("%d",&n);
	intialize();
	for(i=0;i<n;i++){
		printf("\nEnter element:");
		scanf("%d",&x);
		if(x>=0)
			hash[x][0]=1;
		else{
			x=abs(x);
			hash[x][1]=1;
		}
	}
	return 0;
}
// Return true is element is prasent in hash index else return false
bool search(int x){
	if((int)x>=0){
		if(hash[x][0]==1)
			return 1;
	}
	else{
		x=abs(x);
		if(hash[x][1]==1)
			return 1;
	}
	return 0;
}
// Your usual main function
int main(){
	int x;
	bool a=0;
	insert();
	printf("\nEnter element to search:");
	scanf("%d",&x);
	a=search(x);
	if(a)
		printf("present\n");
	else
		printf("absent\n");
	return 0;
}
