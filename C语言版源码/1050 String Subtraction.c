#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char s1[10005],s2[10005];char *t;int i;
	gets(s1);
	gets(s2);
	for(i=0;s2[i]!='\0';i++){
		while((t=strchr(s1,s2[i]))!=NULL){
			 *t='\n';
		}
	}
	
	for(i=0;s1[i]!='\0';i++){
		if(s1[i]=='\n'){
			continue;
		}
		else{
			printf("%c",s1[i]);
		}
	}
	return 0;
}


