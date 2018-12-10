#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

typedef struct lzi{
	int parent;
	int lchild;
	int rchild;
}node;
struct dui{
	int weizhi;
}duilie[12];
int g;
int inorder(int k,node*jiedian);
int main(int argc, char *argv[]) {
	int n,i,k;char rchild,lchild;int r,l;
	scanf("%d",&n);
	node *jiedian;
	jiedian=calloc(n,sizeof(node));
	for(i=0;i<n;i++){
		(jiedian+i)->parent=-1;
		(jiedian+i)->lchild=-1;
		(jiedian+i)->rchild=-1;
	}
	
	for(i=0;i<n;i++){
		getchar();
		scanf("%c %c",&rchild,&lchild);
		if(isdigit(rchild)){
			r=rchild-'0';
			(jiedian+i)->rchild=r;
			(jiedian+r)->parent=i;
		}
		if(isdigit(lchild)){
			l=lchild-'0';
			(jiedian+i)->lchild=l;
			(jiedian+l)->parent=i;
		}
	}
	for(i=0;i<n;i++){
		if((jiedian+i)->parent==-1){
			k=i;break;
		}	
	}
	g=n;
	int head=0,rail=0;
	duilie[rail].weizhi=k;
	rail++;
	while(head!=rail){
		printf("%d",duilie[head].weizhi);
		if((jiedian+duilie[head].weizhi)->lchild!=-1){
			duilie[rail].weizhi=(jiedian+duilie[head].weizhi)->lchild;
			rail++;
		}
		if((jiedian+duilie[head].weizhi)->rchild!=-1){
			duilie[rail].weizhi=(jiedian+duilie[head].weizhi)->rchild;
			rail++;
		}
		head++;
		if(head==rail){
			printf("\n");
		}
		else printf (" ");
	}
	inorder(k,jiedian);
	
	return 0;
}
int inorder(int k,node*jiedian){
	if(k!=-1){
		inorder((jiedian+k)->lchild,jiedian);
		printf("%d",k);g--;
		if(g>=1)
		printf(" ");
		inorder((jiedian+k)->rchild,jiedian);
	}
	
}

