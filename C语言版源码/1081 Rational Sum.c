#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int yuefen(long *fenmu,long *fenzi);
int muyinshu[50000],ziyinshu[50000];
typedef struct lizi{
	long fenzi;
	long fenmu;
}Fenshu; 
int main(int argc, char *argv[]) {
	int n,i,j,k;char a[101][100],zhongjie[100];
	scanf("%d",&n);
	Fenshu fenshu[101];
	Fenshu sum;
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;a[i][j]!='/';j++){
			zhongjie[j]=a[i][j];
		}
		zhongjie[j]='\0';
		fenshu[i].fenzi=atoi(zhongjie);
		for(j=j+1,k=0;a[i][j]!='\0';j++,k++){
			zhongjie[k]=a[i][j];
		}
			zhongjie[k]='\0';
			fenshu[i].fenmu=atoi(zhongjie);
	}
	sum=fenshu[0];
	for(i=1;i<n;i++){
		sum.fenzi=sum.fenzi*fenshu[i].fenmu+sum.fenmu*fenshu[i].fenzi;
		sum.fenmu=sum.fenmu*fenshu[i].fenmu;
		yuefen(&(sum.fenmu),&(sum.fenzi));
	}
	k=sum.fenzi/sum.fenmu;
	j=sum.fenzi%sum.fenmu;
	if(k!=0){
		if(j!=0){
			printf("%d %d/%d",k,j,sum.fenmu);	
		}
		else
			printf("%d",k);
	}
	else{
		if(j!=0)
			printf("%d/%d",j,sum.fenmu);
		else
			printf("0");
	}
	return 0;
}
int yuefen(long *fenmu,long *fenzi){
	int i,j,n,k,flag=1;
	long mu,zi;
	
	mu=*fenmu;zi=*fenzi;
	if(zi==0){
		return 0;
	}
	if(zi<0){
		zi=-1*zi;
		flag=0;
	}
	for(i=2,j=0;;){
		if(mu%i==0){
			mu=mu/i;
			muyinshu[j]=i;
			j++;
			if(mu==1)
				break;
			continue;
		}
		i++;
	}
	for(i=2,n=0;;){
		if(zi%i==0){
			zi=zi/i;
			ziyinshu[n]=i;
			n++;
			if(zi==1)
				break;
			continue;
		}
		i++;
	}
	for(i=0;i<j;i++){
		for(k=0;k<n;k++){
			if(muyinshu[i]==ziyinshu[k]){
				muyinshu[i]=1;ziyinshu[k]=1;
				break;
			}
		} 
	}
	mu=1;zi=1;
	for(i=0;i<j;i++){
		mu=mu*muyinshu[i];
	}
	for(k=0;k<n;k++){
		zi=zi*ziyinshu[k];
	}
	if(flag==0)
		zi=zi*-1;
	*fenmu=mu;
	*fenzi=zi;
	return 0;
}
