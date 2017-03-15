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
