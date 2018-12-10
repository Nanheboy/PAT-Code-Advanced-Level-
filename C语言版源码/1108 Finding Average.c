#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
int main(int argc, char *argv[]) {
	int n,i,f,flag=1,dot=0,num=0;char a[50];double sum=0,j;
	scanf("%d",&n);
	if(n==0){
		printf("The average of 0 numbers is Undefined");return 0;
	}
	while(n--){
		flag=1;dot=0;
		scanf("%s",a);
		for(i=0;a[i]!='\0';i++){
			if(i==0){
				if(a[i]=='-'){
					continue;
				}
				else{
					if(isdigit(a[i])){
						continue;
					}
					else{
						flag=0;break;
					}
				}
			}
			else{
				if(isdigit(a[i])){
					continue;
				}
				else if(a[i]=='.'){
					dot++;
					if(dot>1){
						flag=0;
						break;
					}
					continue;
				}
				else{
					flag=0;break;
				}
			}
		}
		if(flag==1){
			j=atof(a);
			if(j<-1000||j>1000)
				flag=0;
		}
		if(flag==1){
			for(f=0;a[f]!='\0';f++){
				if(a[f]=='.'){
					break;
				}
			}
			if(i-f>3){
				flag=0;
			}
			
		}
		if(flag==1){
			sum+=atof(a);
			num++;
		}
		else{
			printf("ERROR: ");
			printf("%s",a);
			printf(" is not a legal number\n");
		}
	}
	if(num>0){
		if(num>1)
		printf("The average of %d numbers is %0.2lf",num,sum/(int)num);
		else{
			printf("The average of 1 number is %0.2lf",sum);
		}
	}
	else{
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
}







