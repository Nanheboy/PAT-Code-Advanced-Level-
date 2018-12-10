#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

int yuefen(long long*fenmu,long long*fenzi);
typedef struct lizi{
	long long fenzi;
	long long fenmu;
}Fenshu; 
int main(int argc, char *argv[]) {
	int n,i,f,p,j[2],k[2],jieguoj[4],jieguok[4],jieguom[4];char a[2][100],zhongjie[100];
	
	Fenshu fenshu[3];
	Fenshu sum,jian,chen,chu;
	scanf("%lld/%lld",&fenshu[0].fenzi,&fenshu[0].fenmu);
	scanf("%lld/%lld",&fenshu[1].fenzi,&fenshu[1].fenmu);
	sum=fenshu[0];
	
		sum.fenzi=sum.fenzi*fenshu[1].fenmu+sum.fenmu*fenshu[1].fenzi;
		sum.fenmu=sum.fenmu*fenshu[1].fenmu;
		yuefen(&(sum.fenmu),&(sum.fenzi));
	
	jieguok[0]=sum.fenzi/sum.fenmu;
	jieguoj[0]=sum.fenzi%sum.fenmu;
	jieguom[0]=sum.fenmu;
	if(jieguoj[0]<0&&jieguok[0]<0)
	 	jieguoj[0]=-1*jieguoj[0];
	jian=fenshu[0];
	
		jian.fenzi=jian.fenzi*fenshu[1].fenmu-jian.fenmu*fenshu[1].fenzi;
		jian.fenmu=jian.fenmu*fenshu[1].fenmu;
		yuefen(&(jian.fenmu),&(jian.fenzi));
	
	jieguok[1]=jian.fenzi/jian.fenmu;
	jieguoj[1]=jian.fenzi%jian.fenmu;
	jieguom[1]=jian.fenmu;
	if(jieguoj[1]<0&&jieguok[1]<0)
	 	jieguoj[1]=-1*jieguoj[1];
	chen=fenshu[0];
	
		chen.fenzi=chen.fenzi*fenshu[1].fenzi;
		chen.fenmu=chen.fenmu*fenshu[1].fenmu;
		yuefen(&(chen.fenmu),&(chen.fenzi));
	
	jieguok[2]=chen.fenzi/chen.fenmu;
	jieguoj[2]=chen.fenzi%chen.fenmu;
	jieguom[2]=chen.fenmu;
	if(jieguoj[2]<0&&jieguok[2]<0)
	 	jieguoj[2]=-1*jieguoj[2];
	chu=fenshu[0];
	
		chu.fenzi=chu.fenzi*fenshu[1].fenmu;
		chu.fenmu=chu.fenmu*fenshu[1].fenzi;
		if(chu.fenmu!=0){
			if(chu.fenmu<0&&chu.fenzi<0){
				chu.fenmu=-1*chu.fenmu;
				chu.fenzi=-1*chu.fenzi;
			}
			if(chu.fenmu<0&&chu.fenzi>0){
				chu.fenmu=-1*chu.fenmu;
				chu.fenzi=-1*chu.fenzi;
			}		
			yuefen(&(chu.fenmu),&(chu.fenzi));
		}
	
	if(chu.fenmu==0){
		jieguok[3]=0;
		jieguoj[3]=0;
		jieguom[3]=0;
	}
	else{
		jieguok[3]=chu.fenzi/chu.fenmu;
		jieguoj[3]=chu.fenzi%chu.fenmu;
		jieguom[3]=chu.fenmu;
	}
	if(jieguoj[3]<0&&jieguok[3]<0)
	 	jieguoj[3]=-1*jieguoj[3];
	//diyishu
	yuefen(&(fenshu[0].fenmu),&(fenshu[0].fenzi));
	 k[0]=fenshu[0].fenzi/fenshu[0].fenmu;
	 j[0]=fenshu[0].fenzi%fenshu[0].fenmu;
	 if(j[0]<0&&k[0]<0)
	 	j[0]=-1*j[0];
	 
	//diershu
	yuefen(&(fenshu[1].fenmu),&(fenshu[1].fenzi));
	k[1]=fenshu[1].fenzi/fenshu[1].fenmu;
	j[1]=fenshu[1].fenzi%fenshu[1].fenmu;
	if(j[1]<0&&k[1]<0)
	 	j[1]=-1*j[1];
	//
	for(i=0;i<4;i++){
		if(k[0]!=0){
			if(j[0]!=0){
				if(k[0]<0)
					printf("(%d %d/%d)",k[0],j[0],fenshu[0].fenmu);
					else
					printf("%d %d/%d",k[0],j[0],fenshu[0].fenmu);
			}
			else{
				if(k[0]<0)
					printf("(%d)",k[0]);
					else
					printf("%d",k[0]);
			}
		}
		else{
			if(j[0]!=0){
				if(j[0]<0)
					printf("(%d/%d)",j[0],fenshu[0].fenmu);
					else
					printf("%d/%d",j[0],fenshu[0].fenmu);
			}
			else{
				printf("0");
			}
		}
		switch(i){
			case 0:printf(" + ");break;
			case 1:printf(" - ");break;
			case 2:printf(" * ");break;
			case 3:printf(" / ");break;
		}
		if(k[1]!=0){
			if(j[1]!=0){
				if(k[1]<0)
					printf("(%d %d/%d)",k[1],j[1],fenshu[1].fenmu);
					else
					printf("%d %d/%d",k[1],j[1],fenshu[1].fenmu);
			}
			else{
				if(k[1]<0)
					printf("(%d)",k[1]);
					else
					printf("%d",k[1]);
			}
		}
		else{
			if(j[1]!=0){
				if(j[1]<0)
					printf("(%d/%d)",j[1],fenshu[1].fenmu);
					else
					printf("%d/%d",j[1],fenshu[1].fenmu);
			}
			else{
				printf("0");
				
			}
		}
		printf(" = ");
		
		if(i==3&&k[1]==0&&j[1]==0){
				printf("Inf");
				return 0;
			}
		
		else{
			if(jieguok[i]!=0){
			if(jieguoj[i]!=0){
				if(jieguok[i]<0)
					printf("(%d %d/%d)",jieguok[i],jieguoj[i],jieguom[i]);
					else
					printf("%d %d/%d",jieguok[i],jieguoj[i],jieguom[i]);
			}
			else{
				if(jieguok[i]<0)
					printf("(%d)",jieguok[i]);
					else
					printf("%d",jieguok[i]);
			}
		}
		else{
			if(jieguoj[i]!=0){
				if(jieguoj[i]<0)
					printf("(%d/%d)",jieguoj[i],jieguom[i]);
					else
					printf("%d/%d",jieguoj[i],jieguom[i]);
			}
			else{
				printf("0");
			}
		}
		}
		
		if(i!=3){
			printf("\n");
		}
	}
	
	return 0;
}
int yuefen(long long*fenmu,long long*fenzi){
	long long tem,a,b;
	a=*fenmu;b=*fenzi;
	if(a<b){
		tem=a;
		a=b;
		b=tem;
	}
	while(b!=0){
		tem=a%b;
		a=b;
		b=tem;
	}
	*fenmu=*fenmu/a;
	*fenzi=*fenzi/a;
	if(*fenmu<0){
		*fenmu=-1**fenmu;
		*fenzi=-1**fenzi;
	}
	return 0;
}
