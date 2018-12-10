#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
typedef struct lizi{
	char name[10];
	int high;
}danwei;
int cmp(const danwei*a,const danwei*b);
char zuo[10000][10];
char you[10000][10];
int main(int argc, char *argv[]) {
	int n,k,i,j=0,m=0,flag=0,zi=0,yi=0,di,p;
	scanf("%d%d",&n,&k);
	danwei *ren;
	ren=(danwei*)calloc(n,sizeof(danwei));
	for(i=0;i<n;i++){
		scanf("%s %d",&ren[i].name,&ren[i].high);
		getchar();
	}
	qsort(ren,n,sizeof(danwei),cmp);
	j=n;m=0;
	for(i=0;i<k;i++){
		j=j-m;zi=0;yi=0;flag=0;
		if(i==0){
			m=n/k+n%k;
		}
		else{
			m=n/k;
		}
		di=j-m;
		strcpy(zuo[zi],ren[j-1].name);
		zi++;
		for(p=j-2;p>=di;p--){
			if(flag==0){
				strcpy(zuo[zi],ren[p].name);
				zi++;flag=1;
			}
			else{
				strcpy(you[yi],ren[p].name);
				yi++;flag=0;	
			}
		}
		for(zi=zi-1;zi>=0;zi--){
				if(zi==0)
					printf("%s",zuo[zi]);
				else
					printf("%s ",zuo[zi]);
		}
		for(p=0;p<yi;p++){
				printf(" %s",you[p]);	
		}
		if(i!=k-1)
			printf("\n");
	}
	return 0;
}
int cmp(const danwei*a,const danwei*b){
	if((a->high-b->high)==0)
		return strcmp(b->name,a->name);
	return a->high-b->high;
}







