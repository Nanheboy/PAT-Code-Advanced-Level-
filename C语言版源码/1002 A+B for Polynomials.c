#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	typedef struct node{
		double xishu;
		int zhishu;
		struct node *next;
	}node;
	struct {
		struct node *ptr;
		int length;
	}p1,p2,p3;
	int k1,k2,i,j,n;double an;
	node *p,*q,*w;
	p1.ptr=NULL;p1.length=0;
	p2.ptr=NULL;p2.length=0;
	p3.ptr=NULL;p3.length=0;
	scanf("%d",&k1);
	p1.length=k1;
	for(i=0;i<k1;i++){
		scanf("%d%lf",&n,&an);
		if(p1.ptr==NULL){
			p1.ptr=(node*)malloc(sizeof(node));
			p1.ptr->zhishu=n;
			p1.ptr->xishu=an;
			p1.ptr->next=NULL;
			
			p=p1.ptr;
		}
		else{
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
			p->zhishu=n;
			p->xishu=an;
			p->next=NULL;
			
		}
	}
	//ceshi
//	printf("%d\n",p1.length);
	//
	scanf("%d",&k2);
	p2.length=k2;
	for(i=0;i<k2;i++){
		scanf("%d%lf",&n,&an);
		if(p2.ptr==NULL){
			p2.ptr=(node*)malloc(sizeof(node));
			p2.ptr->zhishu=n;
			p2.ptr->xishu=an;
			p2.ptr->next=NULL;
			
			p=p2.ptr;
		}
		else{
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
			p->zhishu=n;
			p->xishu=an;
			p->next=NULL;
			
		}
	}
	//ceshi
//	printf("%d\n",p2.length);
	//
	p=p1.ptr;q=p2.ptr; w=p3.ptr;
	for(i=0,j=0;i<p1.length&&j<p2.length;){
		if(p->zhishu>q->zhishu){
			if(w==NULL)
			p3.ptr=w=p;
			else {
				w->next=p;
				w=w->next;
			}
			p=p->next;
			i++;
			p3.length++;
		}
		else if(p->zhishu==q->zhishu){
			p->xishu=p->xishu+q->xishu;
			if(p->xishu==0.0){
				p=p->next;
				q=q->next;
				j++;i++;
			}
			else{
				if(w==NULL){
					p3.ptr=w=p;
				}
				else {
					w->next=p;
					w=w->next ;
				}
				p=p->next;
				q=q->next;
				j++;i++;
				p3.length++;
			}
			
		}
		else if(p->zhishu<q->zhishu){
			if(w==NULL){
				p3.ptr=w=q;
			}
			else {
				w->next=q;
				w=w->next;
			}
			q=q->next;
			j++;
			p3.length++;
		}
	} 
	//printf("i=%d,j=%d,p3=%d\n",i,j,p3.length);
	if(i>=p1.length&&j<p2.length){
		if(w==NULL){
			p3.ptr=w=q; 
		} 
		else{
			w->next=q; 
		}
		p3.length+=p2.length-j;
	}
	else if(i<p1.length&&j>=p2.length){
		if(w==NULL){
			p3.ptr=w=p; 
		} 
		else{
			w->next=p; 
		}
		
		p3.length+=p1.length-i;
	}
	if(p3.length==0){
		printf("%d",p3.length);return 0;
	}
		
	else
	printf("%d ",p3.length);
	for(i=0,w=p3.ptr;i<p3.length;i++,w=w->next){
		if(i!=p3.length-1){
			printf("%d %.1lf ",w->zhishu,w->xishu);
		}
		else printf("%d %.1lf",w->zhishu,w->xishu);
	}
	return 0;
}
