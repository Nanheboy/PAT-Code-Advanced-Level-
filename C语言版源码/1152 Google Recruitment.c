#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//���⣺��һ�������ҳ������������У���������Ϊ���� 
int isprime(int sum){//�ж��������� 
	int p,i;
	p=sqrt(sum)+1;
	if(sum==1||sum==0)
		return 0;
	if(sum==2)
		return 1;
	for(i=2;i<=p;i++){
		if(sum%i==0)
			return 0;
	}
	return 1;
}
int main(int argc, char *argv[]) {
	int l,k;
	scanf("%d%d",&l,&k);
	char a[1005];
	int i,sum=1,flag=0,p;//flagΪ�ж��Ƿ��ҵ�������sumΪ������������ 
	getchar();//�Ե� \n 
	for(i=1;i<=l;i++){
		scanf("%c",&a[i]);
	}
	for(i=1;i<=l;i++){
		p=i;
		sum=1;
		for(;p<i+k&&(i+k-1)<=l;p++){
			if(p==i){
				sum=a[i]-'0';
			}
			else{
				sum=sum*10+a[p]-'0';
			}
		}
		if(isprime(sum)){
			for(p=i;p<i+k&&a[p]=='0';p++){   //��ѭ��Ϊ��ӡǰ�õ��� 
				printf("%c",a[p]);
			}
			printf("%d",sum);
			flag=1;
			break;
		}

	}
	if(flag==0){
		printf("404");
	}
	return 0;
}
