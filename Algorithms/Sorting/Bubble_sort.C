#include<stdio.h>
/**
 * @breif C program to Sort array of 10 elements 
 *        using bubble sort
 */
int main()
{
    unsigned int i=0,j,temp=0,a[10];
    for(;i<10;i++)
    {
        printf("Enter %d element\n",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        temp=0;             //To check if swapping happend 
        for(j=1;j<10;j++)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                temp=1;
            }
        }
        if(temp==0)// in case array is already sorted then exit
        {
            break;
        }
    }
    for(i=0;i<10;printf("%d\t",a[i++]));
    return 0;
}
