#include<stdio.h>
int convert(FILE *fprt){
	char c,d;
	FILE *fp;
	fp=fopen("/home/fzx/Desktop/C prog/temp.c","w+");
	while((c=fgetc(fprt))!=EOF){
		if(c=='/'){
			if((d=fgetc(fprt))=='*'){
				while(c!='*'&&d!='/'){
					c=d;
					d=fgetc(fprt);
				}
			}
			else if(d=='/'){
				while(d!='\n')
					d=fgetc(fprt);
			}
			else
				fprintf(fp,"%c",d);
			if(d=='\n')
				fprintf(fp,"%c",d);
		}
		else
			fprintf(fp,"%c",c);

	}
	fclose(fp);
}
