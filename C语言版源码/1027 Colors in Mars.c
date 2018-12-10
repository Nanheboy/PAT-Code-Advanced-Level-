#include<stdio.h>
#include<stdlib.h>

int main(){
	int a1,a2,a3;int i=0;
	int zhi[3][2]={0};
	scanf("%d%d%d",&a1,&a2,&a3);
	div_t t;
	t.quot=a1;
	while(t.quot){
		t=div(t.quot,13);
		zhi[0][i]=t.rem;
		i++;
	}
	t.quot=a2;i=0;
	while(t.quot){
		t=div(t.quot,13);
		zhi[1][i]=t.rem;
		i++;
	}
	t.quot=a3;i=0;
	while(t.quot){
		t=div(t.quot,13);
		zhi[2][i]=t.rem;
		i++;
	}
	printf("#");
	int j;
	for(i=0;i<3;i++)
		for(j=1;j>=0;j--){
		switch(zhi[i][j]){
			case 10:printf("A");break;
			case 11:printf("B");break;
			case 12:printf("C");break;
			default :printf("%d",zhi[i][j]);
		}
	}
	return 0;
}


