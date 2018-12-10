#include <stdio.h>
#include <stdlib.h>
struct quan{
	int dis;
}cycle[205][205];
int cout[100000][205]={0};
int main(int argc, char *argv[]) {
	int n,m,a,b,c,i,j,k,q;
	int pathnum,start;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		cycle[a][b].dis=c;
		cycle[b][a].dis=c;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(cycle[i][j].dis==0)
				cycle[i][j].dis=999999;
			if(cycle[j][i].dis==0)
				cycle[j][i].dis=999999;
		}
	}
	scanf("%d",&pathnum);
	int path[100000]={0};
	int p[100000];
	
	int flag1=1,flag2=1,flag3=1,min=999999;
	for(i=0;i<pathnum;i++){
		flag1=1;flag2=1;flag3=1;
		scanf("%d",&k);
		for(j=0;j<k;j++){
			
			scanf("%d",&a);
			p[j]=a;
			cout[i][a]++;
			if(j==0){
				start=a;
			}
			else{
				path[i]+=cycle[start][a].dis;
				start=a;
				
			}
		}
		if(path[i]>=999999){
			printf("Path %d: NA",i+1);flag1=0;
		}
		else {
			printf("Path %d: %d",i+1,path[i]);
		}
		if(j<n){
			printf(" (Not a TS cycle)");flag3=0;
		}
		else {
			for(k=1;k<=n;k++){
				if(k!=p[0]&&cout[i][k]>1)
					flag2=0;
				if(cout[i][k]==0)
					flag1=0;
			}
			if(p[j-1]!=p[0]){
				printf(" (Not a TS cycle)");flag3=0;
			}	
			else if(flag1==0){
				printf(" (Not a TS cycle)");flag3=0;
			}
			else if(flag2==0&&flag1==1){
				printf(" (TS cycle)");
			}
			else printf(" (TS simple cycle)");
			
		}
		
			printf("\n");
			if(path[i]<min&&flag3==1){
				min=path[i];
				q=i+1;
			}
			
	}
	printf("Shortest Dist(%d) = %d",q,min);
	return 0;
}
