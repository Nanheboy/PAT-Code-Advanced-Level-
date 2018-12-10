#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

int voi[1005],father[1005];
int init(int x){
	while(x){
		father[x]=x;
		x--;
	}
	return 0;
}
int find(int x){
	if(x==father[x])return x;
	return father[x]=find(father[x]);
}
int merge(int x,int y){
	int fy,fx;
	fy=find(y);
	fx=find(x);
	if(fy!=fx){
		father[fy]=fx;
	}
	return 0;
}
int cmp(const void *a,const void* b);
int main(int argc, char *argv[]) {
	int n,i,k,j,a,b[1005]={0};
	scanf("%d",&n);
	init(n);
	for(i=0;i<1005;i++){
		voi[i]=-1;
	}
	for(i=1;i<=n;i++){
		scanf("%d:",&k);
		for(j=1;j<=k;j++){
			scanf("%d",&a);
			if(voi[a]==-1){
				voi[a]=i;
			}
			else{
				merge(voi[a],i);
			}
		}
	}
	int root[1005]={0},sum=0;
	for(i=1;i<=n;i++){
		if(root[find(i)]==0){
			sum++;
		}
		root[find(i)]++;
	}
	for(i=1,j=0;i<1005;i++){
		if(root[i]!=0){
			b[j]=root[i];
			j++;
		}
	}
	qsort(b,j,sizeof(int),cmp);
	printf("%d\n",sum);
	for(i=0;i<j;i++){
		if(i==j-1){
			printf("%d",b[i]);
		}
		else{
			printf("%d ",b[i]);
		}
	}
	return 0;
}
int cmp(const void *a,const void* b){
	return *(int*)b-*(int*)a;
}







