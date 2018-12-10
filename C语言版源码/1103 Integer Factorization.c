#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>

int zhongzu[401];
int zuizu[401];
int max=0,j=0;
int kpow(int x,int y);
int dsf(int w,int n,int p,int k);
int duibi(int *zhongzu,int *zuizu,int k);
int main(int argc, char *argv[]) {
	int n,p,k,w,q;
	scanf("%d%d%d",&n,&k,&p);
	w=20;
	while(1){
		if(n-kpow(w,p)>=0){
			break;
		}
		else
			w--;
	}
	dsf(w,n,p,k);
	if(max==0){
		printf("Impossible");
		return 0;
	}
	printf("%d = ",n);
	for(q=0;q<k;q++){
		if(q==k-1){
			printf("%d^%d",zuizu[q],p);
		}
		else printf("%d^%d + ",zuizu[q],p);
	}
	return 0;
}
int dsf(int w,int n,int p,int k){
	int y;
	for(;w>=0;w--){
		if(kpow(w,p)*(k-j)<n){
			continue;
		}
		y=n;
		y=y-kpow(w,p);
		if(y>0){
			zhongzu[j]=w;
			j++;
			if(j==k){
				j=j-1;
				break;
			}
			else if(j<k){
				dsf(w,y,p,k);
			}
		}
		else if(y<0){
			continue;
		}
		else if(y==0){
			zhongzu[j]=w;
			j++;
			if(j==k){
				duibi(zhongzu,zuizu,k);j--;
				break;
			}
			else if(j<k){
				j--;
				continue;
			}
		}		
	}
	j--;
	return 0;
}
int duibi(int *zhongzu,int *zuizu,int k){
	int i,sum=0,y;
	for(i=0;i<k;i++){
		sum=sum+zhongzu[i];
	}
	if(sum>max){
		for(i=0;i<k;i++){
			zuizu[i]=zhongzu[i];
		}
		max=sum;
	}
	else if(sum==max){
		for(i=0;i<k;i++){
			if(zhongzu[i]>zuizu[i]){
				for(y=0;j<k;y++){
					zuizu[y]=zhongzu[y];
				}
				break;
			}
		}
		
	}
}
int kpow(int x,int y){
	int sum=1;
	while(y){
		sum=sum*x;
		y--;
	}
	return sum;
}



