#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b);
int main() {
	int a[100001],n;int i,f=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	for(i=0;i<n;i++){
		if(a[i]<=0)continue;
		if(i+1<n&&a[i+1]==a[i])
			continue;
		else {
			
			if(f==a[i])
				{
					f++;
				}
			else {
				printf("%d",f);return 0;
			}
		}
	}
	printf("%d",f);
	return 0;
}
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}


