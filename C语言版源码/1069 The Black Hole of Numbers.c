#include<stdio.h>
#include<stdlib.h>

int decrease(int *s);
int increase(int *s);
int dcmp(const void *a,const void *b);
int cmp(const void *a,const void *b);
int main(){
	int n;int s[4],d[4];int w,u;int i,j;
	scanf("%d",&n);
	if(n%1111==0){
		printf("%d - %d = 0000",n,n);
		return 0;
	}
	while(1){
		for(i=0;i<4;i++){
			s[3-i]=n%10;
			d[3-i]=n%10;
			n=n/10;
		}
		w=decrease(s);
		printf("%04d",w);
		printf(" - ");
		u=increase(d);
		printf("%04d = ",u);
		n=w-u;
		if(n==6174){
			printf("%04d",n);
			return 0;
		}
		else{
			printf("%04d\n",n);
		}
			
	}
	return 0;
}
int decrease(int *s){
	int i,n=0;
	qsort(s,4,sizeof(int),dcmp);
	for(i=0;i<4;i++){
		n=s[i]+n*10;
	}
	return n;
	
}
int increase(int *s){
	int i,n=0;
	qsort(s,4,sizeof(int),cmp);
	for(i=0;i<4;i++){
		n=s[i]+n*10;
	}
	return n;
}
int dcmp(const void *a,const void *b){
	return -(*(int*)a-*(int *)b);
}
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}


