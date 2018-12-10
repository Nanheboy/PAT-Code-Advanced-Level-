#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j,n,flag=0;int k[55],m[55],t[55];int *p;int *pf;
	for(i=0;i<55;i++){
		m[i]=i;
	}
	p=t;
	pf=m;
	scanf("%d",&n);
	for(i=1;i<55;i++){
		scanf("%d",&k[i]);	
	}
	while(n){
		for(i=1;i<55;i++){
			p[k[i]]=pf[i];
		}
		n--;
		if(n!=0){
			p=(p==t)?m:t;
			pf=(pf==m)?t:m;
		}
	}
		
	for(j=1;j<55;j++){
		if(j!=1){
			printf(" ");
		}
		switch(p[j]){
			case 1:printf("S1");break;
			case 2:printf("S2");break;
			case 3:printf("S3");break;
			case 4:printf("S4");break;
			case 5:printf("S5");break;
			case 6:printf("S6");break;
			case 7:printf("S7");break;
			case 8:printf("S8");break;
			case 9:printf("S9");break;
			case 10:printf("S10");break;
			case 11:printf("S11");break;
			case 12:printf("S12");break;
			case 13:printf("S13");break;
			case 14:printf("H1");break;
			case 15:printf("H2");break;
			case 16:printf("H3");break;
			case 17:printf("H4");break;
			case 18:printf("H5");break;
			case 19:printf("H6");break;
			case 20:printf("H7");break;
			case 21:printf("H8");break;
			case 22:printf("H9");break;
			case 23:printf("H10");break;
			case 24:printf("H11");break;
			case 25:printf("H12");break;
			case 26:printf("H13");break;
			case 27:printf("C1");break;
			case 28:printf("C2");break;
			case 29:printf("C3");break;
			case 30:printf("C4");break;
			case 31:printf("C5");break;
			case 32:printf("C6");break;
			case 33:printf("C7");break;
			case 34:printf("C8");break;
			case 35:printf("C9");break;
			case 36:printf("C10");break;
			case 37:printf("C11");break;
			case 38:printf("C12");break;
			case 39:printf("C13");break;
			case 40:printf("D1");break;
			case 41:printf("D2");break;
			case 42:printf("D3");break;
			case 43:printf("D4");break;
			case 44:printf("D5");break;
			case 45:printf("D6");break;
			case 46:printf("D7");break;
			case 47:printf("D8");break;
			case 48:printf("D9");break;
			case 49:printf("D10");break;
			case 50:printf("D11");break;
			case 51:printf("D12");break;
			case 52:printf("D13");break;
			case 53:printf("J1");break;
			case 54:printf("J2");break;
		}
	}
	return 0;
}


