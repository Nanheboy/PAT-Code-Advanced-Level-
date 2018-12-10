#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
	int n,i,j,k,m[5],z,sum=0,flag=0;char c,s[100][10],q[10];
	scanf("%d",&n);
	c=getchar();
	for(i=0;i<n;i++){
		gets(s[i]);
	}
	div_t t;
	for(i=0;i<n;i++){
		j=0;
		if(isdigit(s[i][0])){
			k=atoi(s[i]);
			if(k==0){
				printf("tret");
				if(i<n-1)
					printf("\n");
				continue;
			}
			t.quot=k;
			while(t.quot){
				t=div(t.quot,13);
				m[j]=t.rem;
				j++;
			}
			for(j=j-1;j>=0;j--){
				if(j==0){
					switch(m[j]){
						case 1:printf("jan");break;
						case 2:printf("feb");break;
						case 3:printf("mar");break;
						case 4:printf("apr");break;
						case 5:printf("may");break;
						case 6:printf("jun");break;
						case 7:printf("jly");break;
						case 8:printf("aug");break;
						case 9:printf("sep");break;
						case 10:printf("oct");break;
						case 11:printf("nov");break;
						case 12:printf("dec");break;
						case 0:if(flag){
									break;
								}
								else{
									printf("tret");
									break;
								}
					}
				}
				else{
					flag=1;
					switch(m[j]){
						case 1:printf("tam");break;
						case 2:printf("hel");break;
						case 3:printf("maa");break;
						case 4:printf("huh");break;
						case 5:printf("tou");break;
						case 6:printf("kes");break;
						case 7:printf("hei");break;
						case 8:printf("elo");break;
						case 9:printf("syy");break;
						case 10:printf("lok");break;
						case 11:printf("mer");break;
						case 12:printf("jou");break;
					}	
					if(m[j-1]!=0)
						printf(" ");//整除时不加0和空格 
				}
			}
		}
		if(isalpha(s[i][0])){
			for(z=j;s[i][j]!='\0';j++){
				q[z]=s[i][j];
				if(s[i][j]==' '){
					q[j]='\0';
					if(strcmp(q,"tam")==0)
						sum=13*1;
					else if(strcmp(q,"hel")==0)
						sum=13*2;
					else if(strcmp(q,"maa")==0)
						sum=13*3;
					else if(strcmp(q,"huh")==0)
						sum=13*4;
					else if(strcmp(q,"tou")==0)
						sum=13*5;
					else if(strcmp(q,"kes")==0)
						sum=13*6;
					else if(strcmp(q,"hei")==0)
						sum=13*7;
					else if(strcmp(q,"elo")==0)
						sum=13*8;
					else if(strcmp(q,"syy")==0)
						sum=13*9;
					else if(strcmp(q,"lok")==0)
						sum=13*10;
					else if(strcmp(q,"mer")==0)
						sum=13*11;
					else if(strcmp(q,"jou")==0)
						sum=13*12;
					z=-1;
				}
				else{
					;
				}
				z++;
			}
			q[z]='\0';
					if(strcmp(q,"jan")==0)
						sum+=1;
					else if(strcmp(q,"feb")==0)
						sum+=2;
					else if(strcmp(q,"mar")==0)
						sum+=3;
					else if(strcmp(q,"apr")==0)
						sum+=4;
					else if(strcmp(q,"may")==0)
						sum+=5;
					else if(strcmp(q,"jun")==0)
						sum+=6;
					else if(strcmp(q,"jly")==0)
						sum+=7;
					else if(strcmp(q,"aug")==0)
						sum+=8;
					else if(strcmp(q,"sep")==0)
						sum+=9;
					else if(strcmp(q,"oct")==0)
						sum+=10;
					else if(strcmp(q,"nov")==0)
						sum+=11;
					else if(strcmp(q,"dec")==0)
						sum+=12;
					else if(strcmp(q,"tret")==0)
						sum+=0;
					else if(strcmp(q,"tam")==0)
						sum=13*1;
					else if(strcmp(q,"hel")==0)
						sum=13*2;
					else if(strcmp(q,"maa")==0)
						sum=13*3;
					else if(strcmp(q,"huh")==0)
						sum=13*4;
					else if(strcmp(q,"tou")==0)
						sum=13*5;
					else if(strcmp(q,"kes")==0)
						sum=13*6;
					else if(strcmp(q,"hei")==0)
						sum=13*7;
					else if(strcmp(q,"elo")==0)
						sum=13*8;
					else if(strcmp(q,"syy")==0)
						sum=13*9;
					else if(strcmp(q,"lok")==0)
						sum=13*10;
					else if(strcmp(q,"mer")==0)
						sum=13*11;
					else if(strcmp(q,"jou")==0)
						sum=13*12;
			printf("%d",sum);
			 sum=0;
		}
		if(i<n-1)
			printf("\n");
	}
	
	
	return 0;
}
