/*A program to run tic tac tow */
#include<stdio.h>
int i,j,p,x,y,chance=0; 	
int grid[3][3];
int grid_l[3][3];
char grid1[3][3];
/*
	i and j represent cordinate of grid
	p defines position define by player 1=00.2=01.3=02,4=10,5=11,6=12,7=20,8=21,9=22
	x and y for furthur use
	chance is an variable deciding who will play next game
	grid is where we play the game
*/
/*It calculate weather position entered by user is valid or not basically it check for overwright */
int lock(){
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			grid_l[i][j]=0;
	return 0;
}
/*
position marks the value of player in gird by with help of encode function 
as soon as encode throws values it enter apporiate number with help of chance variable
*/
int position(){
	int w;
	if(!grid_l[i][j]){
		grid_l[i][j]=1;
		if(chance==0){
			grid[i][j]=0;
			grid1[i][j]=79;
		}
		else if(chance==1){
			grid[i][j]=1;
			grid1[i][j]=88;
		}
		w=win();
		return w;
	}
	return 10;
}
/* encode function caluclate the grid position by taking user entered parameter
for eg: if user enteged position 7 then i value will be 2 and j will be 0 refering to 20 position in grid */
int encode(){
	int temp=p-1,w;
	i=temp/3;
	j=temp%3;
	if(i>2||j>2)
		return 11;
	w=position();
	return w;
}
/*It calculate which player won after each move 
It is divided into 3 component 
1) horiziontal 
2) vertical
3) diagonal
As value stored in each grid matrix will be either 0 or 1 it just calculate sum of 3 entries   */
int win(){
	int k,l;
	for(k=0;k<3;k++){
		if(((grid[k][0]+grid[k][1]+grid[k][2])==0))
			return 1;
		else if((grid[k][0]+grid[k][1]+grid[k][2])==3)
			return 2;
		else if((grid[0][k]+grid[1][k]+grid[2][k])==0)
			return 1;
		else if((grid[0][k]+grid[1][k]+grid[2][k])==3)
			return 2;
	}
		if((grid[0][0]+grid[1][1]+grid[2][2])==0)
			return 1;
		else if((grid[0][0]+grid[1][1]+grid[2][2])==3)
			return 2;
		else if((grid[0][2]+grid[1][1]+grid[2][0])==0)
			return 1;
		else if((grid[0][2]+grid[1][1]+grid[2][0])==3)
			return 2;
	return 0;

}
/*All type of error or message are handle by display function  */
int display(int w){
	if(w==1||w==2)
		printf("player %d wins\n\n",w);
	if(w==10)
		printf("%d %d is alread filled try again\n",i,j);
	if(w==11)
		printf("cell limit out of bound try again\n");
	if(w==0)
		printf("\nplayer %d chance please enter a value:",chance+1);
	if(w==9)
		printf("\nIts a Draw\n");
	return 0;
}
/*Shows general composition of grid  */
void showInstructions()
{
    printf("\t\t\t  Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below"
            " and play\n\n");
     
    printf("\t\t\t  1 | 2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");
     
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
    printf("\n player 1 is x and player 2 is o\n");
}
/*A dynamic grid updating after each moves that a player plays  */
void showBoard()
{
    printf("\n\n");
     
    printf("\t\t\t  %c | %c  | %c  \n", grid1[0][0],
                             grid1[0][1], grid1[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", grid1[1][0],
                             grid1[1][1], grid1[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", grid1[2][0],
                             grid1[2][1], grid1[2][2]);
  
}
// Inatilizing showBoard()
int intialize(){
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			grid1[i][j]= ' ';
}
int main(){
	int k,l,w=0,c=0;
	for(k=0;k<3;k++)
		for(l=0;l<3;l++)
			grid[k][l]=300;
		showInstructions();
		lock();
		intialize();
	do{
		w=0;
		c++;				// keeping track of number of moves played
		display(w);
		scanf("%d",&p);
		w=encode();
		if(w>=10)		// Handeling error
			display(w);
		else{
			chance++;
			chance%=2;
		}
		if(c==9&&w!=1&&w!=2)
			w=9;
		showBoard();
	}while(c!=9&&w!=1&&w!=2);
		display(w);
	return 0;
}
