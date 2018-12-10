#include<stdio.h>
#include<stdlib.h>

int main(){
	typedef struct jiegou{
		char name[12];
		char pass[12];
		int flag;
	}lizi[1002];
	lizi t;int flag=0;
	int n;int p[1002]={0};
	scanf("%d",&n);
	int i,j,k,sum=0;
	for(i=0;i<n;i++){
		scanf("%s",t[i].name);
		scanf("%s",t[i].pass);
		t[i].flag=0;
	}
	for(j=0;j<n;j++){
		for(k=0;t[j].pass[k]!='\0';k++){
			if(t[j].pass[k]=='1'){
				t[j].pass[k]='@';
				t[j].flag=1;
				flag=1;
			}
			if(t[j].pass[k]=='0'){
				t[j].pass[k]='%';
				t[j].flag=1;
				flag=1;
			}
			if(t[j].pass[k]=='l'){
				t[j].pass[k]='L';
				t[j].flag=1;
				flag=1;
			}
			if(t[j].pass[k]=='O'){
				t[j].pass[k]='o';
				t[j].flag=1;
				flag=1;
			}
		}
	}
	if(flag==0){
		if(n==1){
			printf("There is 1 account and no account is modified");
			return 0;
		}
		else{
			printf("There are %d accounts and no account is modified",n);return 0;
		}	
	}
	else{
		for(k=0,j=0;k<n;k++){
			if(t[k].flag==1){
				sum++;
				p[j]=k;
				j++;
			}
		}
	}
	p[j]=-1;
	printf("%d",sum);
	j=0;
	while(p[j]!=-1){
		printf("\n%s %s",t[p[j]].name,t[p[j]].pass);
		j++;
	}
	return 0;
}


