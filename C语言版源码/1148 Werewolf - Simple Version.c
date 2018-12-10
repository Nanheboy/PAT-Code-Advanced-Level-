#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int n,i,j,k,flag,renshu,langshu,flag1,m,lang1=999,lang2=999;
	int yangpin[105],ceshi[105];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&yangpin[i]);
	}
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			langshu=0;renshu=0;
			for(k=1;k<=n;k++){
				if(k==i||k==j){
					if(abs(yangpin[k])!=i&&abs(yangpin[k])!=j&&yangpin[k]<0){
						langshu++;
					}
					else if((abs(yangpin[k])==i||abs(yangpin[k])==j)&&yangpin[k]>0){
						langshu++;
					}
				}
				else{
					if(abs(yangpin[k])!=i&&abs(yangpin[k])!=j&&yangpin[k]<0){
						renshu++;
					}
					else if((abs(yangpin[k])==i||abs(yangpin[k])==j)&&yangpin[k]>0){
						renshu++;
					}
				}
			}
			if(langshu==1&&renshu==1){
				if(i<lang1||(i==lang1&&j<lang2)){
					lang1=i;lang2=j;
				}
			}
		}
	}
	if(lang1==999&&lang2==999)
		printf("No Solution");
	else printf("%d %d",lang1,lang2);
	return 0;
}
