#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	typedef struct lizi{
		int g;
		int s;
		int k;
	}danwei;
	danwei a,b,c;
	scanf("%d.%d.%d %d.%d.%d",&a.g,&a.s,&a.k,&b.g,&b.s,&b.k);
	c.g=a.g+b.g;
	c.s=a.s+b.s;
	c.k=a.k+b.k;
	while(c.k>=29){
		c.k=c.k-29;
		c.s=c.s+1;
	}	
	while(c.s>=17){
		c.s=c.s-17;
		c.g=c.g+1;
	}
	printf("%d.%d.%d",c.g,c.s,c.k);
	return 0;
}


