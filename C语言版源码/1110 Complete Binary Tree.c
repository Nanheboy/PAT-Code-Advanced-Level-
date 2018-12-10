#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
typedef struct lizi{
	int parent;
	int lchild;
	int rchild;
}tree;

int main(int argc, char *argv[]) {
	int n,i,j=0,flag=1;int dui[50],head=0,rail=0,duiying[50];
	char a[10],b[10];
	scanf("%d",&n);
	tree *fuzhu,*btree;
	fuzhu=(tree*)calloc(n,sizeof(tree));
	btree=(tree*)calloc(n,sizeof(tree));
	for(i=0;i<n;i++){
		fuzhu[i].parent=-1;
		fuzhu[i].lchild=-1;
		fuzhu[i].rchild=-1;
	}
	for(i=0;i<n;i++){
		btree[i].parent=-1;
		btree[i].lchild=-1;
		btree[i].rchild=-1;
	}
	for(i=0;i<n;i++){
		
		scanf("%s %s",a,b);
		if(a[0]!='-'){
			fuzhu[i].lchild=atoi(a);
			fuzhu[atoi(a)].parent=i;
		}
		if(b[0]!='-'){
			fuzhu[i].rchild=atoi(b);
			fuzhu[atoi(b)].parent=i;
		}	
	}
	for(i=0;i<n;i++){
		if(fuzhu[i].parent==-1)
			break;
	}
	dui[rail]=i;
	rail++;
	while(head!=rail){
		if(fuzhu[dui[head]].lchild!=-1){
			dui[rail]=fuzhu[dui[head]].lchild;
			rail++;
		}
		if(fuzhu[dui[head]].rchild!=-1){
			dui[rail]=fuzhu[dui[head]].rchild;
			rail++;
		}
		btree[j].lchild=fuzhu[dui[head]].lchild;
		btree[j].rchild=fuzhu[dui[head]].rchild;
		duiying[j]=dui[head];
		j++;
		head++;
	}
	for(i=1;i<=n;i++){
		if(btree[i-1].lchild!=-1){
			if(btree[i-1].lchild!=duiying[2*i-1]){
				flag=0;break;
			}		
		}
		if(btree[i-1].rchild!=-1){
			if(btree[i-1].rchild!=duiying[2*i]){
				flag=0;break;
			}
		}
	}
	if(flag==1){
		printf("YES %d",duiying[n-1]);
	}
	else{
		printf("NO %d",duiying[0]);
	}
	return 0;
}








