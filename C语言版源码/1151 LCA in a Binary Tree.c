#include <stdio.h>
#include <stdlib.h>
struct lizi{
	int zhi;
	int parent;
	int flag;
}btree[10005];
int p;int inorder[10005],preorder[10005];
int tree(int root,int parent,int up,int down);
int main(int argc, char *argv[]) {
	int m,n,i,j,k,a,flag1,flag2;
	
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++){
		scanf("%d",&inorder[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&preorder[i]);
	}
	for(i=0;i<n;i++){
		if(preorder[0]==inorder[i])
			break;
	}
	tree(i,-1,n-1,0);
	for(i=0;i<m;i++){
		flag1=1;flag2=1;
		for(j=0;j<n;j++){
			btree[j].flag=0;
		}
		scanf("%d%d",&j,&k);
		for(a=0;a<n;a++){
			if(btree[a].zhi==j){
				flag1=0;break;
			}
		}
		while(btree[a].parent!=-1){
			btree[a].flag=1;
			a=btree[a].parent;
		}
		btree[a].flag=1;
		//
		for(a=0;a<n;a++){
			if(btree[a].zhi==k){
				flag2=0;break;
			}
		}
		if(flag1==1&&flag2==1){
			printf("ERROR: %d and %d are not found.",j,k);
		}
		else if(flag1==1&&flag2==0){
			printf("ERROR: %d is not found.",j);
		}
		else if(flag1==0&&flag2==1){
			printf("ERROR: %d is not found.",k);
		}
		else {
			while(a!=-1){
				if(btree[a].flag==1&&btree[a].zhi==k){
					printf("%d is an ancestor of %d.",k,j);break;
				}
				else if(btree[a].flag==1&&btree[a].zhi!=k&&btree[a].zhi!=j){
					printf("LCA of %d and %d is %d.",j,k,btree[a].zhi);break;
				}
				else if(btree[a].flag==1&&btree[a].zhi==j){
					printf("%d is an ancestor of %d.",j,k);break;
				}
				btree[a].flag=1;a=btree[a].parent;
			}
		}
		if(i!=m-1)printf("\n"); 
	}
	return 0;
}
int tree(int root,int parent,int up,int down){//root 根下标,parent 父节点值 
	int k;
	btree[p].parent=parent;
	btree[p].zhi=inorder[root];
	parent=p;
	int rootdi;
	if(root>down){//zuo
		rootdi=preorder[++p];
		for(k=down;k<root;k++){
			if(rootdi==inorder[k]){
				break;
			}
		}
		tree(k,parent,root-1,down);
	}
	if(root<up){//you
		rootdi=preorder[++p];
		for(k=root+1;k<=up;k++){
			if(rootdi==inorder[k])
				break;
		}
		tree(k,parent,up,root+1);
	}
	
}
