#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char s[100][260],a[100][260];int n,i,j,len[100],flag=1;char c;
	scanf("%d",&n);
	c=getchar();
	for(i=0;i<n;i++){
		gets(s[i]);
		len[i]=strlen(s[i]);
	}
	for(i=0;i<n;i++){
		for(len[i]--,j=0;len[i]>=0;len[i]--,j++){
			a[i][j]=s[i][len[i]];
		}
		a[i][j]='\0';
	}
	char f;
	for(j=0;flag==1;j++){
		for(i=0;i<n&&a[i][j]!='\0';i++){
			f=a[0][j];
			if(f!=a[i][j]){
				flag=0;
				break;
			}
		}
		if(flag==1&&a[i][j]=='\0'&&i<n){
			j--;break;
		}
		if(flag==0){
			j--;break;
		}
	}
	if(j<0){
		printf("nai");
	}
	else{
		for(;j>=0;j--){
			printf("%c",a[0][j]);
		}
	}
	return 0;
}



