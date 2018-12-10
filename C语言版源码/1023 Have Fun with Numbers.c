#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a,const void *b);
int main(){
	char a[30];int b[30],c[30],d[30];int i,j;int flag11=1;
	scanf("%s",&a);
	for(i=0;a[i]!='\0';i++){
		b[i]=(int)(a[i]-'0');
	}
	for(j=0;a[j]!='\0';j++){
		c[j]=(int)(a[j]-'0');
	}
	int flag[30]={0,0},k;
	for(k=j-1;k>=0;k--){
		if(2*c[k]+flag[k+1]>=10){
			c[k]=2*c[k]+flag[k+1]-10;
			flag[k]=1;
		}
		else {
			c[k]=2*c[k]+flag[k+1];
			flag[k]=0;
		}
		
	}
	if(flag[0]==1){
		printf("No\n");
		printf("1");
		for(k=0;k<i;k++){
			printf("%d",c[k]);
		}
		return 0;
	}
	else{
		for(k=0;k<j;k++){
			d[k]=c[k];
		}
	}
	qsort(c,i,sizeof(int),cmp);
	qsort(b,j,sizeof(int),cmp);
	int o;o=j;
	i--;j--;
	while(i>=0&&j>=0){
		if(b[i]!=c[j]){
			flag11=0;
		}
		i--;j--;
	}
	if(flag11==1)printf("Yes\n");
	else printf("No\n");
	for(i=0;i<o;i++){
		printf("%d",d[i]);
	}
	return 0;
}
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}


