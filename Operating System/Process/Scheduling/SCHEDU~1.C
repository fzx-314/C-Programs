#include<stdio.h>
float awt=0,ata=0,act=0;
int bt[10];
int size,status;
int arrival_time[10];
int waiting_time[10];
int turnaround_time[10];
int completion_time[10];
/*void sort(int priority[])
{
	int i,j,key;
	for(i=1;i<size;i++)
	{
	    key=priority[i];
	    j=i-1;
	    while(i!=0&&priority[j]>priority[key])
	    {
		priority[j+1]=priority[j];
		j=j-1;
	    }
	    priority[j+1]=key
	}

} */
void FCFS()
{
	int t=0,i=0;
	for(;i<size;i++)
	{
			while(bt[i]!=0)
			{
				t++;
				(bt[i])--;
			}
			completion_time[i]=t;
			turnaround_time[i]=(completion_time[i]-arrival_time[i]);
			if(i!=0)
			{
				waiting_time[i]=completion_time[i-1]-arrival_time[i];
			}
	}
	waiting_time[0]=0;
	printf("process\tCompletion Time\tArrival Time\tWaiting Time\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\n",(i+1),completion_time[i],arrival_time[i],waiting_time[i]);
		awt=awt+waiting_time[i];
		ata=ata+turnaround_time[i];
		act=act+completion_time[i];
	}
	printf("Average waiting time:%f\nAverage turnaround time=%f\nAverage completion time:%f",(awt/size),(ata/size),(act/size));

}
/*void RR()
{
	int time_quantam,t=0;
	int tail=0,head=size,Queue[size],length,k;
	printf("Enter Time Quantam");
	scanf("%d"&time_quantam);
	do
	{
		k=time_quantam;
		while((burst_time[i]!=0)||(k!=0))
		{
			(burst_time[i])--;
			t++;
		}
		if(burst_time[i]==0)
		{
			completion_time[i]=t;
			waiting_time[i]=completion_time[i]-arrival_time[i];
		}
	}while(tail!=head);
}*/
void main()
{
	int i,sp,at,count;
	clrscr();
	printf("Enter number of process you want to schedule Max 10:");
	scanf("%d",&size);
	if(size>10)
		exit(0);
	count=1;
	f1:printf("Press 1 if all process arrive at same time else press 0:");
	scanf("%d",&at);
	switch(at)
	{
		case 0:for(i=0;i<size;i++)
		       {
				printf("Enter Arrival Time of Process %d:",(i+1));
				scanf("%d",&arrival_time[i]);
		       }
		       status=0;
		       break;
		case 1:for(i=0;i<size;i++)
		       {
				arrival_time[i]=0;
		       }
		       status=1;
		       break;
		default:printf("Invalid Selection\n");
			if(count==0)
				exit(0);
			else
			{
				count--;
				goto f1;
			}
	}
	for(i=0;i<size;i++)
	{
		printf("Enter Burst Time of porcess %d:",(i+1));
		scanf("%d",&(bt[i]));
	}
	count=1;
	f2:printf("1)FCFS\n2)SJF\n3)RR\n4)SRTF\n5)Priority\n6)SRTF\nSelect any one option:");
	scanf("%d",&sp);
	switch(sp)
	{
		case 1:FCFS();
			break;
	       /*	case 2:SJF();
			break;
		case 3:RR();
			break;
		case 4:SRTF();
			break;
		case 5:Priority();
		       break;
		case 6:SRTF();
		       break;*/
		default:printf("Invalid Selection\n");
			if(count==0)
				exit(0);
			else
			{
				count--;
				goto f2;
			}
	}
	getch();
}
