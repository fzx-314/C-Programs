#include<stdio.h>
int a[3][3];
void standard()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("|%d %d|",i,j);
		}
	}
}
void print();
void main()
{
	int i,j,count=0,p=0;
	clrscr();
	printf("Player 1 is 1 and player 2 is 0\n");
	printf("standard input type\n");
	standard();
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j]=2;
	while(count<9)
	{
		while(count<=5)
		{
			if(p==0)
			{
				printf("Player 1 turn your symbol is 1:");
				scanf("%d %d",&i,&j);
				a[i][j]=1;
				count++;
				p=1;
			}
			else
			{
				printf("Player 2 turn your symbol is 0:");
				scanf("%d %d",&i,&j);
				a[i][j]=0;
				p=0;
				count++;
			}
			print();
		}
		if(a[0][0]==1&&a[0][1]==1&&a[0][2]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[0][0]==0&&a[0][1]==0&&a[0][2]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		else if(a[0][0]==1&&a[1][0]==1&&a[2][0]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[0][0]==0&&a[1][0]==0&&a[2][0]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		else if(a[0][0]==1&&a[1][1]==1&&a[2][2]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[0][0]==0&&a[1][1]==0&&a[2][2]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		else if(a[0][2]==1&&a[1][1]==1&&a[2][0]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[0][2]==0&&a[1][1]==0&&a[2][0]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		else if(a[1][0]==1&&a[1][1]==1&&a[1][2]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[1][0]==0&&a[1][1]==0&&a[1][2]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		else if(a[2][0]==1&&a[2][1]==1&&a[2][2]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[2][0]==0&&a[2][1]==0&&a[2][2]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		else if(a[0][2]==1&&a[1][2]==1&&a[2][2]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[0][2]==0&&a[1][2]==0&&a[2][2]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		else if(a[0][1]==1&&a[1][1]==1&&a[2][1]==1)
		{
			printf("Player 1 wins");
			goto x;
		}
		else if(a[0][1]==0&&a[1][1]==0&&a[2][1]==0)
		{
			printf("Player 2 wins");
			goto x;
		}
		if(p==0)
		{
			printf("Player 1 turn your symobl is 1:");
			scanf("%d %d",&i,&j);
			a[i][j]=1;
			p=1;
			count++;
		}
		else
		{
			printf("Player 2 turn your symbol is 0:");
			scanf("%d %d",&i,&j);
			a[i][j]=0;
			p=0;
			count++;
		}
		print();
	}
	if(count==9)
		printf("Its a draw");
       x:getch();
}
void print()
{
	int i,j;
	clrscr();
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]!=2)
				printf("|%d|\t",a[i][j]);
			else
				printf("| |\t");
		}
		printf("\n");
	}
}
