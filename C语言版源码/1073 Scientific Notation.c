#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

int main(int argc, char *argv[]) {
	char s[10010],c,f,k[10000];
	int i,j,m,e,n;
	c=getchar();
	scanf("%s",s);
	for(i=0;s[i]!='E';i++){
		;
	}
	f=s[i+1];
	for(j=i+2,m=0;s[j]!='\0';m++,j++){
		k[m]=s[j];
	}
	k[m]='\0';
	e=atoi(k);
	if(f=='-'){
		n=e-1;
		if(c=='-')
			printf("-");
		printf("0.");
		while(n){
			printf("0");
			n--;
		}
		for(m=0;m<i;m++){
			if(s[m]=='.')
				continue;
			printf("%c",s[m]);
		}
	}
	else{
		if(e>=(i-2)){
			n=e-(i-2);
			if(c=='-'){
				printf("-");
			}
			for(m=0;m<i;m++){
				if(s[m]=='.')
					continue;
				printf("%c",s[m]);
			}
			while(n){
				printf("0");
				n--;
			}
		}
		else if(e==0){
			if(c=='-')
				printf("-");
			for(m=0;m<i;m++){
				if(s[m]=='.')
					continue;
				printf("%c",s[m]);
			}
		}
		else{
			n=e+1;
			if(c=='-')
				printf("-");
			for(m=0;m<i;m++){
				if(s[m]=='.')
					continue;
				printf("%c",s[m]);
				if(m==n)
					printf(".");
			}
		}
	}
	return 0;
}

