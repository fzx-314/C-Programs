#include<stdio.h>
#include<stdlib.h>
int *A;
long int heap_size,length;
long int s=0,c=0;
int f=0;
long int input(){			//input scanning begins from here
	long int n,i=0;
	int k;
	FILE *fp;
	fp=fopen("input.txt","r");	// reading inout from text file
	if(!fp)
		return 1;
	for(i=0;i<=0;i++)
		fscanf(fp,"%ld",&n);
	A=(int *)calloc(n,sizeof(int)); //creating memory
	i=0;
	while(i<n){
	fscanf(fp,"%d",&k);	// theoritically it should scan all numbers but it is not doing so :( end of world
        *(A+i)=k;
	i++;
       	}
	fclose(fp);
	return n;
}
int display(long int n){	// display number in sorted order as well as write it in new file
    long int i=0;
    FILE *fp;
    fp=fopen("output.txt","w+");
    if(!fp)
	return -1;
    if(f==1)
	i=1;
    while(i<n){
        printf("\n%d",*(A+i));
	fprintf(fp,"%d\n",*(A+i));
        ++i;
    }
	printf("\n");
	printf("Number of swaps:%ld\n",s);
	printf("Number of copmarision:%ld\n",c);
	fprintf(fp,"Number of swaps:%ld\n",s);
	fprintf(fp,"Number of copmarision:%ld\n",c);
    fclose(fp);
    return 0;
}
int bubble(int n){		// function call for bubble sort
    long int i, j, temp;
    int x;
    for(i=0; i<n-1; i++){
	c++;
        x=0;
        for(j=0; j<n-1-i; j++){
	    c++;
            if(*(A+j) > *(A+j+1)){
		c++;
		s++;
                temp = *(A+j);
                *(A+j) = *(A+j+1);
                *(A+j+1) = temp;
                x=1;
            }
        }
        if(x==0){
		c++;
            return 0;
        }
	c++;
    }
    c++;
    return 0;
}
int insertion(long int n){		// insertion sort
	long int i,j,temp;
	for(i=1;i<n;i++){
	c++;
	temp=*(A+i);
	j=i-1;
	while(j>=0&&*(A+j)>temp){
		c++;
		s++;
		*(A+j+1)=*(A+j);
		j=j-1;
	}	
	s++;
	*(A+j+1)=temp;
	}
	c++;
	return 0;
}
int selection(long int n){	// selection
	long int i,j,min,temp,temp1;
	for(j=0;j<n-1;j++){
	c++;
	min=j;
	for(i=j+1;i<n;i++){
		c++;
		if(*(A+i)<*(A+min)){
			min=i;
		}
		else c++;
	}
	if(min!=j){
	c++;
	s++;
	temp=*(A+j);
	*(A+j)=*(A+min);
	*(A+min)=temp;
	}
	else c++;
	}
	c++;
	return 0;
}
int merge(long int p,long int q,long int r){	// merge partion
	long int n1=q-p+1,n2=r-q,i,j,k;	
	int *L,*R;	
	L=(int *)calloc(n1,sizeof(int));
	R=(int *)calloc(n2,sizeof(int));				
	for(i=0;i<n1;i++)
		*(L+i)=*(A+p+i);				
	for(i=0;i<n2;i++)
		*(R+i)=*(A+q+1+i);				
	i=j=0;
	k=p;                            
	while(i<n1&&j<n2){	
		c++;			
		if(*(L+i)<=*(R+j)){
			c++;
			*(A+k)=*(L+i);
			k++;
			i++;	
		}		
		else{	c++;
			*(A+k)=*(R+j);
			k++;
			j++;
		}
	}		
	while(i<n1){
		c++;
		*(A+k)=*(L+i);
		k++;
		i++;
	}
	c++;			
	while(j<n2){
		c++;
		*(A+k)=*(R+j);
		k++;
		j++;
	}
	c++;
	s=0;
	return 0;
}
int merge_sort(long int p,long int r){		//merge sort
	long int q;
	if(p<r){
	q=(p+r)/2;
	merge_sort(p,q);
	merge_sort(q+1,r);
	merge(p,q,r);
	}
	return 0;
}
int heapify(long int i){		// function call for heapify
	long int l,r,largest,temp;
	l=2*i;
	r=(2*i)+1;
	if(l<=heap_size&&(*(A+l)>*(A+i)))
		largest=l;
	else
		largest=i;
	if(r<=heap_size&&(*(A+r)>*(A+largest)))
		largest=r;
	if(largest!=i){
		temp=*(A+i);
		*(A+i)=*(A+largest);
		*(A+largest)=temp;
		heapify(largest);
	}
	return 0;
}
int build_heap(){		// build heap function call
	long int i;
	length=heap_size;
	i=(length/2);
	for(;i>0;i--){
		heapify(i);
	}
	return 0;
}
int heap_sort(){		// final heap sort
	long int i,temp;
	length=heap_size;
	i=length;
	for(;i>=2;i--){
	c++;
	s++;
	temp=*(A+1);
	*(A+1)=*(A+i);
	*(A+i)=temp;
	heap_size=heap_size-1;
	heapify(1);
	}
	c++;
	s=0;
	return 0;
}
int quick_sort(long int x,long int y){	// quick sort fastest of all
	if(x<y){
	long int i=x,j=y,p,temp,k;
	p=*(A+i);
	while(i<j){
		if(*(A+j)<p){
			c++;
			s++;
			temp=*(A+i+1);
			*(A+i+1)=*(A+j);
			*(A+j)=temp;
			s++;
			temp=*(A+i);
			*(A+i)=*(A+i+1);
			*(A+i+1)=temp;
			++i;
	}
	else{
		c++;
		j--;
	}
	}
	quick_sort(x,i-1);
	quick_sort(i+1,y);
	}
	return 0;
}
int main(int argc,char *argv[]){	//main for usual user input
	long int n;
	char choice=9;
	n=input();	
	printf("1)Bubble\n2)Insertion\n3)Selection\n4)Merge\n5)Heap\n6)Quick\nEnter your choice:");
	choice=getchar();
	switch(choice){
	case '1':bubble(n);
	       display(n);
	       break;
	case '2':insertion(n);
	       display(n);
	       break;
	case '3':selection(n);
	       display(n);
	       break;
	case '4':merge_sort(0,n-1);
	       display(n);
	       break;
	case '5':heap_size=n-1;
	       build_heap();
	       heap_sort();
	       display(n);
               f=1;
	       break;
	case '6':quick_sort(0,n-1);
	       display(n);
	       break;
	default:printf("Better luck next time");
		break;
	}
	printf("\n");
	return 0;
}
