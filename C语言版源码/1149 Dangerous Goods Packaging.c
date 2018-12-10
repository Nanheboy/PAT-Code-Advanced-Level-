#include <stdio.h>
#include <stdlib.h>
typedef struct lizi{
	int zhi;
	struct lizi *next;
}jiedian;

int main(int argc, char *argv[]) {
	jiedian*hash[100005];
	int i,j,n,m,k,z,flag,list[1005];
	jiedian*a1,*b1,*p;
	char a[10],b[10];
	for(i=0;i<100005;i++){
		hash[i]=NULL;
	}
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s %s",a,b);
		a1=(jiedian*)malloc(sizeof(jiedian));
		a1->zhi=atoi(a);a1->next=NULL;
		b1=(jiedian*)malloc(sizeof(jiedian));
		b1->zhi=atoi(b);b1->next=NULL;
		p=hash[atoi(a)];
		if(p==NULL){
			hash[atoi(a)]=b1;
		}
		else{
			while(p->next) p=p->next;
			p->next=b1;
		}
		p=hash[atoi(b)];
		if(p==NULL){
			hash[atoi(b)]=a1;
		}
		else{
			while(p->next) p=p->next;
			p->next=a1;
		}
	}
	for(i=0;i<m;i++){
		scanf("%d",&j);k=0;flag=1;
		while(j--){
			scanf("%s",a);
			list[k]=atoi(a);k++;
		}
		for(j=0;j<k;j++){
			for(z=j+1;z<k;z++){
				if(hash[list[j]]!=NULL){
					for(p=hash[list[j]];p!=NULL;p=p->next){
						if(p->zhi==list[z]){
							flag=0;break;
						}
					}
				}
				if(flag==0)break;
			}
			if(flag==0)break;
		}
		if(flag==0)printf("No");
		else printf("Yes");
		if(i!=m-1) printf("\n");
	}
	return 0;
}
