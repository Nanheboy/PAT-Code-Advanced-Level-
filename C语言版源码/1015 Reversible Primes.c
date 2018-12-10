#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int panduanzhishu(long int a);
long int fanzhuan(long int N,int D);
int main(){
typedef	struct lizi{
		long int shu;
		int ji;
		struct lizi *next;
		int flag;
	}jihe,*jiheptr;
	jiheptr aaaptr;jiheptr bbbptr,ptr;
	aaaptr=bbbptr=(jiheptr)malloc(sizeof(jihe));
	bbbptr->next=NULL;
	while(1){
		if(bbbptr->next==NULL){
			ptr=(jiheptr)malloc(sizeof(jihe));
			ptr->next=NULL;bbbptr->next=ptr;
		}
		scanf("%ld",&bbbptr->shu);
		if(bbbptr->shu<0)
			break;
		scanf("%d",&bbbptr->ji);
			bbbptr=bbbptr->next;
	}
	bbbptr=aaaptr;
	while(bbbptr->shu>0){
		if(panduanzhishu(bbbptr->shu)){
			if(panduanzhishu(fanzhuan(bbbptr->shu,bbbptr->ji))){
				printf("Yes");
			}
			else printf("No");
		}
		else printf("No");
		if(bbbptr->next->shu>0)printf("\n");
		bbbptr=bbbptr->next;
	}
	return 0;
}
int panduanzhishu(long int a){
	double b;int i;
	if(a==1)
	return 0;
	b=sqrt(a)+0.5;
	for(i=2;i<b;i++){
		if(a%i==0)return 0;
	}
	return 1;
	
}
long int fanzhuan(long int N,int D){
	int a[30],b[30];int i=0,j=0,k=0;long int pp=1,sum=0;
	ldiv_t t;
	t.quot=N;
	while(t.quot){
		t=ldiv(t.quot,D);
		a[i]=t.rem;
		i++;
	}
	i--;
	while(i>=0){
		b[j]=a[i];
		j++;i--;
	}
	j--;
	for(;k<=j;k++){
		sum+=pp*b[k];
		pp=pp*D;
	}
	return sum;
}



