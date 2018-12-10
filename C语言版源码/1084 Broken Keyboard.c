#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
	char a1[100],a2[100],k[100];int weizhi[90],hash[150]={0};
	int i,j,n,m;
	scanf("%s",a1);
	scanf("%s",a2);
	for(i=0,j=0;a1[i]!='\0';i++,j++){
		if(isalpha(a1[i]))
			a1[i]=toupper(a1[i]);
		hash[(int)a1[i]]++;
		weizhi[j]=(int)a1[i];
	}
	for(i=0;a2[i]!='\0';i++){
		if(isalpha(a2[i]))
			a2[i]=toupper(a2[i]);
		hash[(int)a2[i]]-=100;
	}
	for(i=0,m=0;i<j;i++){
		if(hash[weizhi[i]]>0){
			k[m]=weizhi[i];m++;hash[weizhi[i]]=0;
		}
	} 
	for(i=0;a1[i]!='\0';i++){
		if(isalpha(a1[i]))
			a1[i]=toupper(a1[i]);
		for(j=0;j<m;j++){
			if(a1[i]==k[j]){
				printf("%c",k[j]);
				k[j]='\n';
				break;
			}
				
			
		}
	}
	return 0;
}

