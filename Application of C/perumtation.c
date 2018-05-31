/* To print all purmutation of a given string using backtracking */
#include <stdio.h>
#include <string.h>
int swap(char *a,char *b){
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int permutation(char *a,int l, int r){
	int i;
	if(l==r)
		printf("%s\n",a);
	else{
		for(i=l;i<=r;i++){
			swap((a+l),(a+i));
			permutation(a,l+1,r);
			swap((a+l),(a+i));
		}
	}
	return 0;
}
int main(){
	char str[]="abc";
	int n;
	n=strlen(str);
	permutation(str,0,n-1);
	return 0;
}
