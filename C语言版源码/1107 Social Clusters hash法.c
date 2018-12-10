#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

int cmp(const void*a,const void*b);
typedef struct lizi{
	int hash[10000];
	int num;
}nhash;
int main(int argc, char *argv[]) {
	int k,i,n,j,h,m,z=0,flag[1005]={0},a[1005];
	scanf("%d",&k);
	nhash *khash;
	khash=(nhash*)calloc(k,sizeof(nhash));
	for(i=0;i<k;i++){
		z=0;
		scanf("%d:",&n)	;
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
			for(m=0;m<k;m++){
				if(khash[m].hash[a[j]]!=0){
					flag[z]=m;z++;
				}
			}
		}
		if(z!=0){
			for(j=0;j<n;j++){
				khash[flag[0]].hash[a[j]]++;
			}
			khash[flag[0]].num++;
			for(m=1;m<z;m++){
				khash[flag[0]].num+=khash[flag[m]].num;
				khash[flag[m]].num=0;
				for(h=0;h<1005;h++){
					if(khash[flag[m]].hash[h]>0){
						khash[flag[0]].hash[h]+=khash[flag[m]].hash[h];
						khash[flag[m]].hash[h]=0;
					}
				}
			}
		}
		else{
			for(m=0;m<k;m++){
				if(khash[m].num==0)
					break;
			}
			for(j=0;j<n;j++){
				khash[m].hash[a[j]]++;
			}
			khash[m].num++;
		}	
	}
	int shu=0,b[1005]={0};
	for(m=0,i=0;m<k;m++){
		if(khash[m].num>0){
			shu++;
			b[i]=khash[m].num;
			i++;
		} 
	}
	qsort(b,i,sizeof(int),cmp);
	printf("%d\n",shu);
	for(j=0;j<i;j++){
		if(j==i-1){
			printf("%d",b[j]);
		}
		else{
			printf("%d ",b[j]);
		}
	}
	return 0;
}
int cmp(const void*a,const void*b){
	return *(int*)b-*(int*)a;
}






