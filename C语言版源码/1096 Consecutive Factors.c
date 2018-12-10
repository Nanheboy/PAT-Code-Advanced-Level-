#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
	unsigned int n,m;int k=1,i,j,num,max=0,start;
	 scanf("%d",&n);
	 m=sqrt((double)n)+2;
	for(i=2;i<m;i++){
		j=i;k=1;
		for(num=0;;num++){
			k=k*j;
			j++;
			if(n%k!=0||k>n){
				break;
			}
	
		}
		if(num>max){
			max=num;
			start=i;
		}
	}
	if(max==0){
		printf("1\n%d",n);
	}
	else {
		printf("%d\n",max);
		for(i=0;i<max;i++){
			printf("%d",start+i);
			if(i!=max-1){
				printf("*");
			}
		}
	}
	return 0;
}
