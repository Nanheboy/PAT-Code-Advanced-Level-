#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	long int N,b;long int a[50];int i=1;int flag=1;
	scanf("%ld%ld",&N,&b);
	if(N==0){
		printf("Yes\n0");return 0;
	} 
	ldiv_t t;
	t.quot=N;
	while(t.quot){
		t=ldiv(t.quot,b);
		a[i]=t.rem;
		i++;
	}
	i--;int j=1;int k;k=i;
	while(j<=i){
		if(a[i]!=a[j]){
			flag=0;
		}
		i--;j++;
	}
	if(flag==1)printf("Yes\n");
	else printf("No\n");
	for(;k>=1;k--){
		if(k==1){
			printf("%ld",a[k]);
		}
		else printf("%ld ",a[k]);
	}
	return 0;
}


