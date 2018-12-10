#include<stdio.h>
#include<stdlib.h>

int main(){
	double a[3][3];int i,j,max;char b[3];double c[3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=0;i<3;i++){
		max=a[i][0];b[i]='W';
		for(j=0;j<3;j++){
			if(a[i][j]>max){
				max=a[i][j];
				switch(j){
					case 0:b[i]='W';break;
					case 1:b[i]='T';break;
					case 2:b[i]='L';break;
				}
			}
		}
	}
	for(i=0;i<3;i++){
		switch(b[i]){
			case 'W':c[i]=a[i][0];break;
			case 'T':c[i]=a[i][1];break;
			case 'L':c[i]=a[i][2];break;
		}
	}
	for(i=0;i<3;i++){
		printf("%c ",b[i]);
	}
	printf("%.2lf",(c[0]*c[1]*c[2]*0.65-1)*2);
	return 0;
}



