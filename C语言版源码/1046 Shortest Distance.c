#include<stdio.h>
#include<stdlib.h>

int main(){
	int ding[100000],n,m,i,j,head,end,k,min1,min2,sum[10005];
	scanf("%d",&n);
	ding[1]=0;
	for(i=1;i<n;i++){
		scanf("%d",&k);
		ding[i+1]=ding[i]+k;
	}
	scanf("%d",&ding[n+1]);
	scanf("%d",&m);
	j=0;k=m;
	while(m){
		scanf("%d%d",&head,&end);
		min1=0;min2=0;
		if(end>=head){
			min1=ding[end]-ding[head];
			min2=ding[n]-ding[end]+ding[n+1];
			min2+=ding[head]; 
		}
		else{
			min1=ding[head]-ding[end];
			min2=ding[n]-ding[head]+ding[n+1];
			min2+=ding[end]; 
		}
		sum[j]=(min1<min2)?min1:min2;
		j++;m--;
	}
	for(i=0;i<k;i++){
		printf("%d",sum[i]);
		if(i!=k-1){
			printf("\n");
		}
	}
	return 0;
}


