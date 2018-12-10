#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);
int main(int argc, char *argv[]) {
	int n,i=0,k=0,j;long shu[100000][3]={0},pvi[100000]={0},min=99999999999,max=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%ld",&shu[i][0]);
	}
	for(i=0;i<n;i++){
		if(shu[i][0]>max){
			shu[i][1]=1;
			max=shu[i][0];
		}
	}
	for(i=n-1;i>=0;i--){
		if(shu[i][0]<min){
			shu[i][2]=1;
			min=shu[i][0];
		}
	}
	for(i=0;i<n;i++){
		if(shu[i][1]&&shu[i][2]){
			pvi[k]=shu[i][0];
			k++;
		}
	}
	
	if(k==0){
		printf("0\n");
		printf("\n");
	}
	else{
		printf("%d\n",k);
		qsort(pvi,k,sizeof(long),cmp);
		for(i=0;i<k;i++){
			if(i==k-1){
				printf("%d",pvi[i]);
			}
			else{
				printf("%d ",pvi[i]);
			}
		}
	}
	
	return 0;
}
int cmp(const void* a,const void* b){
	return *(long *)a-*(long *)b;
}
