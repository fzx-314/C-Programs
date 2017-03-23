/*
  To find min and max in an unsorted array in O(n) time
*/
#include <stdio.h>
void Min_Max(int a[],int n)
{
    int i,j,min,max;
    if(n%2==0)  // If input size is even then complexity is 3(n/2)-2
    {
        if(a[0]<=a[1])   // Order of O(1) operation
        {
            min=a[0];
            max=a[1];
        }
        else
        {
            min=a[1];
            max=a[0];
        }
        i=2;
        j=3;
    }
    else        // If input size is odd then complexity is 3(n/2)
    {
        min=a[0];
        max=a[0];
        i=1;
        j=2;
    }
    for(;i<n,j<n;i+2,j+2)
    {
        if(a[i]<=a[j])   //1st comparision
        {
            if(a[i]<=min) //2nd comparision
            {
                min=a[i];
            }
            if(a[j]>max)    // 3rd comparision
            {
                max=a[j];
            }
        }
        else
        {
            if(a[j]<=min) //2nd comparision
            {
                min=a[j];
            }
            if(a[i]>max)// 3rd comparisiom
            {
                max=a[i];
            }
        }
    }
    printf("\nMin and Max are %d %d",min,max);
}
int main(void) {
	int a[1000],i=0,n;
	printf("Enter input size");
	scanf("%d",&n);             // Getting Input size
	for(;i<n;scanf("%d",&a[i++]));//Taking input
	Min_Max(a,n);
	return 0;
}

