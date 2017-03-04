#include <stdio.h>
int main(void) {
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int x,i,flag=0;
    printf("Enter number you want to search:");
    scanf("%d",&x);
    for(i=0;i<10;i++)
    {
        if(a[i]==x){
            printf("Found");
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Not Found");
	return 0;
}
