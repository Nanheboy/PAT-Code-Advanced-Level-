#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	long int i,j,k;int d=1;int flag=1;
	struct zhan{
		long int a[5];
		int base,top;
	}zhanli;
	zhanli.base=0;zhanli.top=0;
	scanf("%ld%ld",&i,&j);
	k=i+j;
	
	if(k==0)
		printf("%ld",k);
	else{
	if(k<0)d=-1;
	k=k*d;
	ldiv_t qiuyu;
	qiuyu.quot=k;
	int q=0;
	while(qiuyu.quot){
		qiuyu=ldiv(qiuyu.quot,1000);
		zhanli.a[q]=qiuyu.rem;
		zhanli.top++;
		q++;
	}
	while(zhanli.top){
		if(d==-1)
			{
			printf("-");d=1;}
		zhanli.top--;
		if(flag==1)
			{
				if(zhanli.top==0)
				printf("%ld",zhanli.a[zhanli.top]);
			else{
				printf("%ld,",zhanli.a[zhanli.top]);
			}
				flag=0;
			}
		else 
		{
			if(zhanli.top==0)
			printf("%03ld",zhanli.a[zhanli.top]);
			else{
			
				printf("%03ld,",zhanli.a[zhanli.top]);
			}	
		}				
	}
}
	return 0;
}
