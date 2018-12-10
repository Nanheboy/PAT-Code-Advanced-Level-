#include<stdio.h>
#include<stdlib.h>

int main(){
	char a[90];
	scanf("%s",a);
	int i=0;
	for(i=0;a[i]!='\0';i++);
	int n1,n2,n3;
	n1=n3=(i+2)/3;
	n2=i-n1-n3+2;
	int j,k;int top=0,rear=i-1;
	for(j=0;j<n1;j++){
		for(k=0;k<n2;k++){
			if(j<n1-1){
				if(k==0)
					printf("%c",a[top++]);
				else if(k==n2-1)
					printf("%c\n",a[rear--]);
				else printf(" ");
			}
			
		}
	}
	while(top<=rear){
		printf("%c",a[top++]);
	} 
	return 0;
}


