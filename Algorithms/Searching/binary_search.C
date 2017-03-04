#include <stdio.h>
void binary_search(int a[],int x)
{
    int low=0,high=10,mid,flag=0;
    while(low<=high)
    {
            mid=(low+high)/2;
            if(a[mid]==a[x]){
                printf("Found");
                flag=1;
                break;
            }
            else if(x<a[mid])
                high=mid-1;
            else if(x>a[mid])
                high=mid+1;
    }
    if(flag==0)
        printf("Element not present");
}
int main(void) {
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int x;
    printf("Enter number you want to search:");
    scanf("%d",&x);
    binary_search(a,x);
	return 0;
}
