#include<stdio.h>
#include<stdlib.h>

int main(){
	typedef struct jiegou{
		int shu;
		int sum;
	}lizi[10002];
	int n,i,j,k[100002];
	lizi t;
	for(i=0;i<10002;i++){
		t[i].sum=0;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k[i]);
		t[k[i]].shu=k[i];t[k[i]].sum++;
	} 
	for(i=0;i<n;i++){
		if(t[k[i]].sum==1){
			printf("%d",t[k[i]].shu);
			return 0;
		}
	}
	printf("None");

	return 0;
}


