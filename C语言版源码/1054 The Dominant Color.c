#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[100000000];
int b[500000];
int main(){
	int m,n;
	int i,j=0,t,max=0;int k;int mm;
	scanf("%d%d",&m,&n);
	t=m*n;
	for(i=0;i<t;i++){
		scanf("%d",&k);
		a[k]++;
		if(a[k]>1)continue;
		b[j]=k;
		j++;
	}
	max=a[b[0]];mm=b[0];
	for(i=0;i<j;i++){
		if(max<a[b[i]]){
			max=a[b[i]];
			mm=b[i];
		}
	}
	printf("%d",mm);
	
	
	return 0;
}


