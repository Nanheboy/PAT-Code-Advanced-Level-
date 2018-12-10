#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,k,a[101],i,time=0;int qidian=0,zhongdian;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	for(i=0;i<n;i++){
		zhongdian=a[i];
		if((zhongdian-qidian)<0){
			time+=-1*4*(zhongdian-qidian);
		}
		else{
			time+=6*(zhongdian-qidian);
		}
		qidian=zhongdian;
	}
	time=time+n*5;
	printf("%d", time);


	return 0;
}



