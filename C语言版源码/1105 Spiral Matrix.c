#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

struct lieshu{
	int iffill;
	int zhi;
}zhen[200][200];
int cmp(const void* a,const void* b);
int main(int argc, char *argv[]) {
	int n,i,j,flag=0,k,a[10005],m,pn;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	m=n;pn=1;
	for(i=1;i<m;i++){
		if(n%i==0){
			m=n/i;
			pn=i;
		}
	}
	j=0;k=0;
	for(i=n-1;i>=0;i--){
		zhen[j][k].zhi=a[i];
		zhen[j][k].iffill=1;
		if(k+1<pn&&zhen[j][k+1].iffill==0&&flag==0){
			k=k+1;continue;
		}
		else if(j+1<m&&zhen[j+1][k].iffill==0){
			j=j+1;continue;
		}
		else if(k-1>=0&&zhen[j][k-1].iffill==0){
			k=k-1;flag=1;continue;
		}
		else if(j-1>=0&&zhen[j-1][k].iffill==0&&flag==1){
			j=j-1;
			if(j-1<0||zhen[j-1][k].iffill==1){
				flag=0;
			}
			continue;
		}
		
	}
	for(i=0;i<m;i++){
		for(j=0;j<pn;j++){
			if(j==pn-1){
				if(i==m-1){
					printf("%d",zhen[i][j].zhi);
				}
				else
				printf("%d\n",zhen[i][j].zhi);
			}
			else 
				printf("%d ",zhen[i][j].zhi);
		}
	}
	return 0;
}
int cmp(const void* a,const void* b){
	return *(int*)a-*(int *)b;
}




