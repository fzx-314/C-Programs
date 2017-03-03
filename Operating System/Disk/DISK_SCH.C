#include<stdio.h>
#include<conio.h>
#include<math.h>

void fcfs(int a[]);
void sstf(int a[]);
void scan(int a[]);



void main()
{
int n, a[10], ch, i;
printf("enter 10 cylinders numbers");
for(i=0; i<10; i++)
{
scanf("%d", &a[i]);
}
clrscr();


run:
{


printf("\n\n which algo do u want to use?");
printf("\n1) FCFS\n2)SSTF\n3)SCAN\n4)EXIT\n");
scanf("%d", &ch);

switch(ch)
{


      case 1: fcfs(a);
	      goto run;

      case 2: sstf(a);
	      goto run;

      case 3: scan(a);
	      goto run;

      case 4: exit(0);

      default: printf("please enter a valid choice");
	       goto run;

      }
      }
getch();
}

void fcfs(int a[])
{
int order[10], i, x, count=0, ptr;

printf("\n current pointer location");
scanf("%d", &ptr);
for(i=0; i<10; i++)
{
order[i] = a[i];
}
x= ptr- a[0];
if(x>0)
count=x;
else
count= -x;


for(i=1; i<10; i++)
{
x= a[i] - a[i-1];
if(x<0)
count =count+ (-x);
else
count =count+  x;
}

printf("Execution order:\n");
for(i=0; i<10; i++)
{
printf("%d ", order[i]);
}

printf("\nTotal cost : %d", count);
}


void sstf(int a[])
{
int i, j, ptr, count, x, m=9, b[10], min=9999, temp;
printf("\n current pointer location");
scanf("%d", &ptr);
j=ptr;
for(i=0; i<10; i++)
{
b[i] =a[i];
}

while(m>=0)
{
min=9999;
i=m;
while(i>=0)
{
if(abs(b[i]-ptr)<min)
{
min= abs(b[i]-ptr);
x=i;

}
--i;
}
ptr=a[x];
temp= b[x];
b[x] = b[m];
b[m] = temp;
--m;
}

count = abs(j-b[9]);
printf("execution order:\n");
for(i=9; i>=1; i--)
{
printf("%d ", b[i]);
count =count+ abs(b[i]-b[i-1]);
}
printf("%d ", b[0]);
printf("\nTotal cost : %d", count);



}


void scan(int a[])
{
  int ptr, b[11], i, j, min, x, temp;
 printf("\n current pointer location");
scanf("%d", &ptr);
b[0]= ptr;
for(i=0; i<10; i++)
{
b[i+1]= a[i];
}

for(i=0; i<10; i++)
{
min= i;
for(j=i+1; j<11; j++)
{
if(b[j]<b[min])
{
min = j;
}
}
temp = b[i];
b[i] = b[min];
b[min] = temp;
}


i=0;
while(b[i]!=ptr && i<11)
{
i++;
}
printf("\nExecution order :");
x=i;
i=x+1;
while(i!=x)
{
printf(" %d", b[i]);
i= (i+1)%11;
}


}




