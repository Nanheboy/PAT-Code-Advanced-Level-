#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

int main(int argc, char *argv[]) {
	int n,i;double a[100005],sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	for(i=1;i<=n;i++){
		sum=sum+a[i]*i*(n-i+1);
	}
	printf("%.2lf",sum);
	return 0;
}




