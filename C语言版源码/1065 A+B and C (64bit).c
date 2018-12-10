#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i;long long a,b,c,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		sum=a+b;
		if(a>0&&b>0&&a+b<=0)
			printf("Case #%d: true",i+1);
		else if(a<0&&b<0&&a+b>=0)
			printf("Case #%d: false",i+1);
		else{
			if(sum>c)
				printf("Case #%d: true",i+1);
			else
				printf("Case #%d: false",i+1);	
		}
		if(i==n-1);
		else
			printf("\n");
	}

	return 0;
}


