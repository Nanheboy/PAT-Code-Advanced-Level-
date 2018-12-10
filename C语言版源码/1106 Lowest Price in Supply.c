#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

typedef struct kp{
	int name;
	struct kp *next;
}kceil;
typedef struct lizi{
	double pri;
	kceil* child;
}node;
	
	double min=9999999999999;
	int sum=0;
	int dsf(node*ptr,node*nodeptr);
	int suanjia(double r,node* nodeptr);
int main(int argc, char *argv[]) {
	int n,i,flag,sum1,pp,k;double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	node * nodeptr;
	nodeptr=(node*)calloc(n,sizeof(node));
	nodeptr->pri=p;
	nodeptr->child=NULL;
	kceil* zhongjie;kceil *head;
	for(i=0;i<n;i++){
		scanf("%d",&sum1);
		flag=1;
		while(sum1){
			scanf("%d",&k);
			if(flag==1){
				zhongjie=(kceil*)malloc(sizeof(kceil));
				zhongjie->name=k;
				zhongjie->next=NULL;
				nodeptr[i].child=zhongjie;
				head=nodeptr[i].child;
				flag=0;
			}
			else{
				zhongjie=(kceil*)malloc(sizeof(kceil));
				zhongjie->name=k;
				zhongjie->next=NULL;
				head->next=zhongjie;
				head=zhongjie;
			}
			sum1--;
		}
	}
	suanjia(r,nodeptr);
	dsf(nodeptr,nodeptr);
	printf("%.4lf %d",min,sum);
	return 0;
}
int dsf(node*ptr,node * nodeptr){
	kceil*yy;
	yy=ptr->child;
	if(ptr->child==NULL){
		if(ptr->pri<min){
			min=ptr->pri;
			sum=1;
		}
		else if(ptr->pri==min){
			sum++;
		}
		return 0;
	}
	else{
		dsf(nodeptr+ptr->child->name,nodeptr);
	}
	while(yy->next!=NULL){
		dsf(nodeptr+yy->next->name,nodeptr);
		yy=yy->next;
	}
	
}
int suanjia(double r,node* nodeptr){
	int dui[200000];int head,rail;
	head=rail=0;
	dui[head]=0;
	rail++;
	while(head!=rail){
		kceil *kk;
		kk=nodeptr[dui[head]].child;
		while(kk!=NULL){
			dui[rail]=kk->name;
			rail++;
			nodeptr[kk->name].pri=nodeptr[dui[head]].pri*((r+100.0)/100.0);
			kk=kk->next;
		}
		head++;
	}
	
}





