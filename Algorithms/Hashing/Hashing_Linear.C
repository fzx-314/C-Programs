/* Hashing where collision is resolved by linear probing */
#include<stdio.h>
#define size 10
int c[size];
int a[size];
int i;
void insertH(int a[],int rem){
		int temp;
		if(c[rem]==-1)
			c[rem]=a[i];
		else if(c[rem]!=-1){
				temp=(rem+1)%10;
				while(c[temp]!=-1)
					temp=(temp+1)%10;
				c[temp]=a[i];
		}
}
int main(){
		int rem;
		for(i=0;i<size;c[i++]=-1);
		for(i=0;i<size;i++){
			printf("Enter %d input:",i+1);
			scanf("%d",&a[i]);
		}
		for(i=0;i<size;i++){
			rem=a[i]%10;
			insertH(a,rem);
		}
		for(i=0;i<size;printf("%d\t",c[i++]));
		return 0;
}
