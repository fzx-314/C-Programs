#include <stdio.h>
void cntsort(int a[])
{
int i, j, b[10], c[100]={0};

   for(i=0; i<100; i++)
   {
	c[i]= 0;
   }
   for(i=0; i<10; i++)
   {
	c[a[i]]+= 1;
   }
   for(i=1; i<100; i++)
   {
	c[i]=c[i]+c[i-1];
   }
   for(i=9; i>=0; i--)
   {
	b[c[a[i]]-1]= a[i];
	c[a[i]]-= 1;
   }
   for(i=0; i<10; i++)
   {
		printf("  %d", b[i]);
   }
}
int main()
{
	int i, a[10];
	printf("enter 10 numbers to sort betwn 0 to 99:");
	for(i=0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	cntsort(a);
	printf("\n\n");
	return 0;
}


#include <stdio.h>
void Counting_sort(int a[],int b[],int k)
{
    int c[100],i;
    for(i=0;i<k;i++)// Initializing all values from range 0 to 100 to 0
        c[i]=0;
    for(i=0;i<10;i++)
        c[a[i]]+=1;			// Counting occurence of each element
    for(i=1;i<k;i++)
        c[i]=c[i]+c[i-1];	//addition function
    for(i=9;i>=0;i--)
    {
	b[c[a[i]]-1]=a[i];		// Sorting in array b
	c[a[i]]-=1;
    }
}
void print(int b[])		//Just another printing function
{
	int i=0;
	for(;i<10;printf("%d\t",b[i++]));
		
}
int main(void) {
	int a[10],b[10],i=0;
	for(;i<10;i++)						// Getting Input
	{
		printf("\nEnter %d element in range from 0 to 100:",i+1);
		scanf("%d",&a[i]);
    }
    Counting_sort(a,b,100);	//recursive call to counting sort
	print(b);
	return 0;
}
