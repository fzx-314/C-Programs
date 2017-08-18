/*
  To find min and max in an unsorted array in O(n) time
*/
#include<stdio.h>
#define n 11	// Change n for even or odd elements
int a[n];
int input(){	// accepting inputs
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	return 0;
}
int min_max(){
	int small,large,count=0,i;	//variable decleration
	if(n%2==0){					// for even value of n 
		count++;
		if(a[0]<a[1]){			
		/* comparing first 2 elements of array least of them 
		will be intialize to small and greatest will be intialize to large */
			small=a[0];			
			large=a[1];
		}
		else{
			small=a[1];
			large=a[0];
		}
		for(i=2;i<n;i=i+2){	// this loop will compare 2 elements of array and further compare with small and large to find min and max
		    count++;
			if(a[i]<a[i+1]){	
			    count++;
				if(a[i]<small){
					small=a[i];
				}
				count++;
				if(a[i+1]>large){
					large=a[i+1];
				}
			}
			else{
				count++;
				if(a[i+1]<small){
					small=a[i+1];
				}
				count++;
				if(a[i]>large){
					large=a[i+1];
				}
			}
		}
	}
	else{
		small=large=a[0];
		for(i=1;i<n;i=i+2){
			count++;
			if(a[i]<a[i+1]){
			    count++;
				if(a[i]<small){
					small=a[i];
				}
				count++;
				if(a[i+1]>large){
					large=a[i+1];
				}
			}
			else{
				count++;
				if(a[i+1]<small){
					small=a[i+1];
				}
				count++;
				if(a[i]>large){
					large=a[i+1];
				}
			}
		}
	}
	printf("Largest=%d\tSmallest=%d\tCount=%d",large,small,count);
	return 0;
}
int main(){

	input();
	min_max();
	return 0;
}
