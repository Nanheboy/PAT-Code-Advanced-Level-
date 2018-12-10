#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define wuxian 999999
typedef struct tu{
	int cost;
}zhen[250][250],zen;
typedef struct{
	char name[5];
	int happy;
}cityname;
typedef struct {
	zhen G;
	cityname city[250];
	int cityshu;
	int hushu;
}tuxing;
void dayin(int *P,int v1,tuxing * jk);
int locate(char *m,tuxing *jk);
void DJI(tuxing *jk,int v0,int v1);
int main(int argc, char *argv[]) {
	tuxing *jk;int i,j,v0,v1;char m[5],n[5];
	jk=(tuxing *)malloc(sizeof(tuxing));
	scanf("%d%d%s",&(jk->cityshu),&(jk->hushu),jk->city[0].name);
	jk->city[0].happy=0;
	for(i=1;i<jk->cityshu;i++){
		scanf("%s%d",(jk->city[i].name),&(jk->city[i].happy));
	}
	char wei[5]="ROM";
	v1=locate(wei,jk);v0=0;
	for(i=0;i<jk->cityshu;i++){
		for(j=0;j<jk->cityshu;j++){
			jk->G[i][j].cost=wuxian;
			jk->G[j][i].cost=wuxian;
		}
	}
	for(i=0;i<jk->hushu;i++){
		scanf("%s%s",m,n);
		v0=locate(m,jk);v1=locate(n,jk);
		scanf("%d",&(jk->G[v0][v1].cost));
		jk->G[v1][v0].cost=jk->G[v0][v1].cost;
	}
	
	v0=0;v1=locate(wei,jk);
	DJI(jk,v0,v1);
	
	
	
	
	return 0;
}

int locate(char *m,tuxing *jk){
	int i;
	for(i=0;i<jk->cityshu;i++){
		if(strcmp(m,jk->city[i].name)==0)
		{
			return i;
		}
	}
	return -1;
}

void DJI(tuxing *jk,int v0,int v1){
	int P[250];int D[250];int min,i,j;int w,v;int happy[250];int jiedian[250];int luxian [250]={0};int final[250];
	for(i=0;i<jk->cityshu;i++){
		D[i]=jk->G[v0][i].cost;happy[i]=jk->city[i].happy;jiedian[i]=0;final[i]=0;
		P[i]=-1;
		if(D[i]<wuxian){
			P[i]=v0;jiedian[i]=1;luxian[i]=1;
		}
		}	
		final[v0]=1;
		for(i=1;i<jk->cityshu;i++){
			min=wuxian;v=0;
			for(w=0;w<jk->cityshu;w++){
				if(final[w]==0){
					if(D[w]<min){
						v=w;min=D[w];
					}
				}
			}
			final[v]=1;
			for(w=0;w<jk->cityshu;w++){
				if(final[w]==0&&jk->G[v][w].cost<wuxian){
					if(D[v]+jk->G[v][w].cost<D[w]){
						D[w]=D[v]+jk->G[v][w].cost;
						happy[w]=happy[v]+jk->city[w].happy;
						jiedian[w]=jiedian[v]+1;
						luxian[w]=luxian[v];
						P[w]=v;
					}
					else if(D[v]+jk->G[v][w].cost==D[w]){
						luxian[w]+=luxian[v];
						if(happy[v]+jk->city[w].happy>happy[w]){
							happy[w]=happy[v]+jk->city[w].happy;
							jiedian[w]=jiedian[v]+1;
							P[w]=v;
						}
						else if((happy[v]+jk->city[w].happy==happy[w])&&(jiedian[v]+1<jiedian[w])){
							jiedian[w]=jiedian[v]+1;
							P[w]=v;
						}
					}
				}
			} 
		}
	printf("%d %d %d %d\n",luxian[v1],D[v1],happy[v1],(happy[v1]/jiedian[v1]));
	dayin(P,v1,jk);
	
}

void dayin(int *P,int v1,tuxing * jk){
	int i;
	if(P[v1]==-1){
		printf("%s",jk->city[v1].name);
		
	}
	else {
		dayin(P,P[v1],jk);
		printf("->");
		printf("%s",jk->city[v1].name);
		
	}
}
