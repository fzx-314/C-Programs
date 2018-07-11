#include<stdio.h>
#include<string.h>
int keyword=0,indentifier=0;
int iskeyword(char str[]){
	char keywords[32][10]={"int","char","float","double","long","struc","break","for","while","do","struct",
					"continue","case","const","register","static","typedef","union","unsigned","signed",
					"void","enum","extern","goto","default","sizeof","volatile","switch","return","if","else","short"};
	int flag=0,i;
	for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i],str)==0){ // Compare if current string matches with any keyword
            flag = 1;
            break;
        }
    }
    return flag;
}
int terminate(char str[],int j,FILE *fp){	// for classfication of current string as keyword or identifier
	str[j]='\0';
	j=0;
	if(iskeyword(str) == 1){
        fprintf(fp,"%s is keyword\n", str);
        keyword++;  
	}
    else{
        fprintf(fp,"%s is indentifier\n", str);
        indentifier++;
    }
    return j;
}
int main(void){
	int i,operator=0,num_count=0,j=0,cf=0;
	char c,str[32],op[2],op_flag=0,temp[2];
	FILE *fprt;
	FILE *fp;
	fprt=fopen("/home/fzx/Desktop/C prog/test2.c","r");//Input file
	fp=fopen("/home/fzx/Desktop/C prog/output.txt","w+");// ouput file
	while((c=fgetc(fprt))!=EOF){
		if(c=='/'||c=='*'||c=='%'){		// those operator whoes repetion does not make sense
			if(cf==1){
				j=terminate(str,j,fp);
				cf=0;
			}
			operator++;
			fprintf(fp,"%c is operator\n",c);
		}
		// ++, == , &&, -- are special case ans must be handled carefully using op_flag and op[] array
		else if((c=='+'||c=='-'||c=='&'||c=='|'||c=='=')&&op_flag==0){
			if(cf==1){
				j=terminate(str,j,fp); 
				cf=0; 
			}
			op[0]=c;
			op_flag=1;
		}
		else if((c=='+'||c=='-'||c=='&'||c=='|'||c=='=')&&op_flag==1){
			if(cf==1){
				j=terminate(str,j,fp);  
				cf=0;
			}
			op[1]=c;
			op_flag=0;
			fprintf(fp,"%c%c is operator\n",op[0],op[1]);
			operator++;
		}
		else if(isalnum(c)){
			str[j++]=c;
			cf=1;
		}
		else if((c==' '||c=='\n'||c==','||c=='('||c=='['||c=='{')&&(j!=0)){
			j=terminate(str,j,fp);
			cf=0;
		}
		else if(op_flag==1){
			op_flag=0;
			fprintf(fp,"%c is operator\n",op[0]);
			operator++;
		}
	}
	fprintf(fp,"Number of keyword %d,Number of operator %d,Number of indentifier %d\n",keyword,operator,indentifier);
	fclose(fp);
	fclose(fprt);
}
